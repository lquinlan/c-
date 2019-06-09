/*
	Name: Set���� 
	Copyright:δ����ɽ�ֹת����ʹ�� 
	Author: ������ 
	Date: 15/12/18 19:36
	Description:���ݽṹ�γ���� 
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
	int key,pro,size,cnt;//key�ڵ�ֵ,pro��תֵ;
	void dataup ()
	{
		size=ch[0]->size+ch[1]->size+cnt;//��ڵ�
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
inline int random ()//ϵͳ�ṩ�������������̫��,��д48271����ȡ��int����
{
	static int seed=23324;
	return seed=(int)seed*482711LL%2147483647;
}
typedef node* tree;
class Set{
private:
	tree nil=new node;
	tree root,null/*������ַǷ�ָ�����*/,len;
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
		tree y=x->ch[!d];//�µĸ�,��������,�����ұ��
		if(y==null)  //����ո�ʹ�ṹ����
			return ;
		x->ch[!d]=y->ch[d]; //����ԭ������ߵĺ��ӱ���¸�ԭ���ĺ���
		y->ch[d]=x;
		x->dataup();//�ȸ��º���
		y->dataup();//�ٸ��¸���
		x=y;
	}
	bool _add(tree &p ,int tkey)
	{
        if(find(p,tkey))
        {
            return false;
        }
		if(p==null) //���Ϊ��,�½�һ���ڵ�
			p=newnode(tkey);
		else{
			int d=tkey>p->key;//���ն����������ķ�ʽ������������
			_add(p->ch[d],tkey);
			if(p->ch[d]->pro>p->pro)//�����ȼ����и���
				rotate (p,!d);
		}	
		p->dataup();//������ת����Ľڵ���
        return true;
	
	}
	bool find(const tree &p ,int tkey) const
	{
		if(p==null) //���Ϊ��
			return false;
		else
		if(p->key==tkey)//���ԭ���Ѿ���
		return true;
		else{
			int d=tkey>p->key;//���ն����������ķ�ʽ������������
			find(p->ch[d],tkey);
		}
	}
	void _remove (tree &p,int tkey) 
	{
		if(p->key==tkey)//�ҵ��ýڵ�
		{
			if(p->cnt>1)//����ж��ֻ��Ҫ��һ
				p->cnt--;
			else if(p->ch[0]==null)//��Ϊ��,�ұ����
				p=p->ch[1];
			else if(p->ch[1]==null)//ͬ��
				p=p->ch[0];
			else {//����Ҷ�ӽڵ�,��ת,��Ҷ�ӽڵ�
				int d=p->ch[0]->pro>p->ch[1]->pro;//���Һ��������ȼ��ߵı�ɸ�
				rotate(p,d);
				_remove(p->ch[d],tkey);
			}
		}else {
			_remove(p->ch[tkey>p->key],tkey);//���û���ҵ����ն������������в���
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
/*˵��:
    ��Ϊƽ������ʵ�����漰����ָ��Ĳ���,Ϊ�����û��Ƿ�ʹ��,
    ���ｫʵ�ֲ����ĺ�����Ϊ˽��,���ṩ����Ӧ�Ľӿں������û�����;
*/
	Set ()//��ʼ��
	{
		root=null=nil;
		null->key=null->pro=int_max;
		null->size=null->cnt=0;
		null->ch[0]=null->ch[1]=null;
		//len=base;
	}
	Set (const Set &t)//���ƹ���
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
  
    Set& operator = (const Set &t)//��������
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
        ��Ϊ���ϵĽ������Ǽ����г�������,�����Ұ������س�����������������;
        ����:&&;
        ����:+;
        �:-;
    */
    friend Set& operator && (const Set &a, const Set &b);
    friend Set& operator + (const Set &a,const Set &b);
    friend Set& operator - (const Set &a,const Set &b);
	bool add (int tkey)//���Ԫ��
	{
		return _add(root,tkey);
	}
    bool addall (Set c)// ��� set ��û��ָ������c�е�����Ԫ�أ�������ӵ��� set ��
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
    // �Ƴ� set �е�����Ԫ�ء�
    void clear ()
    {
        vector<int>d;
        d=getdata();
        for(int i=0;i<d.size();i++)
        {
            remove(d[i]);
        }
    }
     //��� set �д���ָ����Ԫ��o�������Ƴ���
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
    //��� set ����ָ����Ԫ��o���򷵻� true��
    bool contains (int tkey) const
    {
        return find(root,tkey);
    }
    //����� set ����ָ������c�е�����Ԫ�أ��򷵻� true��
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
    //��Set��Ϊ��
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
    //�Ƴ� set ����Щ������ָ������c�е�Ԫ�ء�
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
    //   ������ set ����Щ�����ڼ���c�е�Ԫ�ء�
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
    //Set��С
    int Size ()
    {
        return root->size;
    }
    //��Set�е�Ԫ�����������ʽ����,������Ϊc++���鷵�رȽ��鷳,ѡ��vector����;
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
