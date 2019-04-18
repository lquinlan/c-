/*
    一种整体与部分的关系,同时允许以同一中方式来看待系统,如常用的文件系统;
    一般包含一个顶层的抽象类,和在此基础上的派生的基本类,和组合类
    抽象类中一般包括以下几个虚拟函数
    注意基类的构造函数应该是虚函数 
    operator
    add
    remove
    getchild
*/
#include<iostream>
#include<vector>
using namespace std;
class compoment
{
    public:
    compoment ()
    {

    }
  virtual ~compoment ()
    {
		cout<<"xigou"<<endl; 
    }
    virtual void Operator ()=0;
    virtual void add (compoment *ch)
    {

    }
    virtual void remove (compoment *ch)
    {

    }
    virtual compoment* getchild (int index) const
    {

    }

};
class leaf :public compoment
{
	public:
    leaf ()
    {
        
    }
    ~  leaf ()
    {
    cout<<"xixixi"<<endl; 
    }
    virtual void Operator ()
    {
        cout<<"this leaf"<<endl;
    }
};
class composite :public compoment
{
    private:
    vector<compoment*> m_va;
    public :
    composite ()
    {

    }
    ~composite ()
    {
        for(int i=0;i<m_va.size();i++)
        {
            delete m_va[i];
        }
    }
    virtual void Operator ()
    {
        cout<<"this composite operator"<<endl;
		vector<compoment*>::iterator it1,it2;
		for(it1=m_va.begin(),it2=m_va.end();it1!=it2;it1++)
		{
			(*it1)->Operator();
		}
    }
    virtual void add (compoment *ch)
    {
    	m_va.push_back(ch); 
    }
    virtual void remove (compoment *ch)
    {
    	vector<compoment*>::iterator it=m_va.begin();
    	while(it!=m_va.end())
    	{
    		if((*it)==ch)
    		{
    			delete *it;
    			m_va.erase(it);
			}
			else
			{
				++it;
			}
		}
    }
    virtual compoment* getchild (int index)
    {
    //	cout<<m_va.size()<<endl;
    	if(index<0||index>m_va.size())
    	{
    		return nullptr;
    	}
    	return m_va[index-1]; 
    }
};
int main ()
{
	leaf* pLeaf1=new leaf();
	leaf* pLeaf2=new leaf();	
	composite* pComposite=new composite();
	pComposite->add(pLeaf1);
	pComposite->add(pLeaf2);
	pComposite->remove(pLeaf1);
	pComposite->getchild(1)->Operator();
	delete pComposite;
	return 0;
}
