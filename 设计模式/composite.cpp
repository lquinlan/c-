/*
    һ�������벿�ֵĹ�ϵ,ͬʱ������ͬһ�з�ʽ������ϵͳ,�糣�õ��ļ�ϵͳ;
    һ�����һ������ĳ�����,���ڴ˻����ϵ������Ļ�����,�������
    ��������һ��������¼������⺯��
    ע�����Ĺ��캯��Ӧ�����麯�� 
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
