/*
	Name: Set工具 
	Copyright:未经许可禁止转载与使用 
	Author: 武祥洋 
	Date: 15/12/18 19:36
	Description:数据结构课程设计 
*/

#ifndef _Set_h_
#define _Set_h_
#include<iostream>
#include<vector>
#define inf 0x3f3f3f3f
#define int_max 2147483647 
using namespace std;
struct node{
	node* ch[2];
	int key,pro,size,cnt;//key节点值,pro旋转值;
	void dataup ()
	{
		size=ch[0]->size+ch[1]->size+cnt;//算节点
	}
    node ()
    {
        ch[0]=NULL;
        ch[1]=NULL;
    }
    ~node ()
    {
        delete ch[0];
        delete ch[1];
    }
};
inline int random ()//系统提供的随机函数性能太差,手写48271可以取尽int的数
{
	static int seed=23324;
	return seed=(int)seed*482711LL%2147483647;
}
typedef node* tree;
class Set{
private:
	tree nil=new node;
	tree root,null/*避免出现非法指针访问*/,len;
	tree newnode (int tkey)
	{
		len=new node; 
		len->key=tkey;
		len->pro=random();
		len->ch[0]=len->ch[1]=null;
		len->size=len->cnt=1;
		return len;
	}
	void rotate (tree &x,int d)
	{
		tree y=x->ch[!d];//新的根,右旋左变根,左旋右变根
		if(y==null)  //避免空根使结构混乱
			return ;
		x->ch[!d]=y->ch[d]; //这是原来根左边的孩子变成新根原来的孩子
		y->ch[d]=x;
		x->dataup();//先更新孩子
		y->dataup();//再更新父亲
		x=y;
	}
	bool _add(tree &p ,int tkey)
	{
        if(find(p,tkey))
        {
            return false;
        }
		if(p==null) //如果为空,新建一个节点
			p=newnode(tkey);
		else{
			int d=tkey>p->key;//按照二叉搜索树的方式进行向下搜索
			_add(p->ch[d],tkey);
			if(p->ch[d]->pro>p->pro)//按优先级进行更新
				rotate (p,!d);
		}	
		p->dataup();//更新旋转过后的节点数
        return true;
	
	}
	bool find(const tree &p ,int tkey) const
	{
		if(p==null) //如果为空
			return false;
		else
		if(p->key==tkey)//如果原来已经有
		return true;
		else{
			int d=tkey>p->key;//按照二叉搜索树的方式进行向下搜索
			find(p->ch[d],tkey);
		}
	}
	void _remove (tree &p,int tkey) 
	{
		if(p->key==tkey)//找到该节点
		{
			if(p->cnt>1)//如果有多个只需要减一
				p->cnt--;
			else if(p->ch[0]==null)//左为空,右变成他
				p=p->ch[1];
			else if(p->ch[1]==null)//同理
				p=p->ch[0];
			else {//不是叶子节点,旋转,至叶子节点
				int d=p->ch[0]->pro>p->ch[1]->pro;//左右孩子中优先级高的变成根
				rotate(p,d);
				_remove(p->ch[d],tkey);
			}
		}else {
			_remove(p->ch[tkey>p->key],tkey);//如果没有找到按照二叉搜索树进行查找
		}
		p->dataup();
    }
	void _print (tree p)
	{
		if(p==null)
			return;
		_print(p->ch[0]);	
	//	cout<<"cnt="<<p->cnt<<endl;
		for(int i=1;i<=p->cnt;i++)
		{
			cout<<p->key<<' ';
		}
		_print(p->ch[1]);
	}
	void getprint (tree p,vector<int> &data)const
	{
		if(p==null)
			return ;
		getprint(p->ch[0],data);	
	//	cout<<"cnt="<<p->cnt<<endl;
		for(int i=1;i<=p->cnt;i++)
		{
			data.push_back(p->key);
		}
		getprint(p->ch[1],data);
	}
public:
/*说明:
    因为平衡树的实现中涉及大量指针的操作,为避免用户非法使用,
    这里将实现操作的函数设为私有,并提供了相应的接口函数供用户操作;
*/
	Set ()//初始化
	{
		root=null=nil;
		null->key=null->pro=int_max;
		null->size=null->cnt=0;
		null->ch[0]=null->ch[1]=null;
		//len=base;
	}
	Set (const Set &t)//复制构造
	{
		root=null=nil;
		null->key=null->pro=int_max;
		null->size=null->cnt=0;
		null->ch[0]=null->ch[1]=null;
        vector<int>data;
		data=t.getdata();
		for(int i=0;i<data.size();i++)
		{
			add(data[i]);
		}
	} 
  
    Set& operator = (const Set &t)//拷贝构造
    {
        Set *tmp;
        tmp=new Set();
        vector<int>data;
		data=t.getdata();
		for(int i=0;i<data.size();i++)
		{
			tmp->add(data[i]);
		}
        return *tmp;
    }
    /*
        因为集合的交并差是集合中常见操作,这里我把它重载成了运算符来方便操作;
        交集:&&;
        并集:+;
        差集:-;
    */
    friend Set& operator && (const Set &a, const Set &b);
    friend Set& operator + (const Set &a,const Set &b);
    friend Set& operator - (const Set &a,const Set &b);
	bool add (int tkey)//添加元素
	{
		return _add(root,tkey);
	}
    bool addall (Set c)// 如果 set 中没有指定集合c中的所有元素，则将其添加到此 set 中
    {
        vector<int> q;
        q=c.getdata();
        bool flag=false;
        for(int i=0;i<q.size();i++)
        {
            if(add(q[i]))
            {
               flag=true; 
            }
        }
        return flag;
    } 
    // 移除 set 中的所有元素。
    void clear ()
    {
        vector<int>d;
        d=getdata();
        for(int i=0;i<d.size();i++)
        {
            remove(d[i]);
        }
    }
     //如果 set 中存在指定的元素o，则将其移除。
	bool remove ( int tkey) 
	{
        if(contains(tkey))
        {
            _remove(root,tkey);
            return true; 
        }
        else
        {
        	return false;
        }
		
	}
    //如果 set 包含指定的元素o，则返回 true。
    bool contains (int tkey) const
    {
        return find(root,tkey);
    }
    //如果此 set 包含指定集合c中的所有元素，则返回 true。
    bool containsAll (Set c)
    {
        vector<int>d;
        d=c.getdata();
        bool flag=true;
        for(int i=0;i<d.size();i++)
        {
            if(!contains(d[i]))
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
    //是Set否为空
    bool isEmpty ()
    {
        if(root->size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //移除 set 中那些包含在指定集合c中的元素。
    bool removeAll (Set c) 
    {
        vector<int>d;
        d=c.getdata();
        for(int i=0;i<d.size();i++)
        {
            if(contains(d[i]))
            {
                remove(d[i]);
            }
        }
        return true;
    }
    //   仅保留 set 中那些包含在集合c中的元素。
    bool retainAll (Set c)
    {
        vector<int>d;
        d=getdata();
        for(int i=0;i<d.size();i++)
        {
            if(c.contains(d[i]))
            {
                continue;
            }
            else
            {
                remove(d[i]);
            }
        }
        return true;
    }
    vector<int> getdata () const 
    {
        vector<int> data; 
        getprint(root,data);
        return data;
    }
    //Set大小
    int Size ()
    {
        return root->size;
    }
    //将Set中的元素以数组的形式返回,这里因为c++数组返回比较麻烦,选择vector代替;
    vector<int> toArray () const
    {
        return getdata();
    }
	void print ()
	{
		_print(root);
		cout<<endl;
	}
};
Set& operator && (const Set &a, const Set &b)
{
    Set *tmp;
    tmp=new Set();
    vector<int> d;
    d=a.getdata();
    for(int i=0;i<d.size();i++)
    {
    	int c=d[i];
        if(b.contains(c))
        {
            tmp->add(c);
        }
    }
    return *tmp;
}
Set& operator + (const Set &a,const Set &b)
{
        Set *tmp;
        tmp=new Set();
        for(auto i:a.toArray())
        {
            tmp->add(i);
        }
        for(auto i:b.toArray())
        {
            tmp->add(i);
        }
        return *tmp;
}
Set& operator - (const Set &a, Set &b)
{
        Set *tmp;
        tmp=new Set();
        for(auto i:a.toArray())
        {
            tmp->add(i);
        }  
       tmp->removeAll(b);
       return *tmp;
}
#endif // !_Seth_Set_h_
