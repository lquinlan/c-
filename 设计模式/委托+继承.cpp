/*
    ������Ƽ�����ͬһ������,���в�ͬ�ı�����ʽ,��ͬһ�����ݸı�,��ͬ�ı�����ʽȫ�ı�,�����õ�,�������ģʽ
    �������һ������,��ʾ������ʽ,ͬʱ��ͬ����ʽ�����ٴλ����Ͻ�������,ͬҵ����֪��,�����ø����ָ��,ָ������,����,������
    ��Ҫһ�ֱ���,��ʽʱ,������,subject����ע��,�������ݷ����ı�ʱ,������updata�����������ݾ��ı�.
*/
#include<iostream>
#include<vector>
class subject;
class observe{
    public:
    virtual void updata (subject* sub,int m_view);
};
class sbuject{
    public:
    void attach (observe *ob)
    {
        m_view.push_back(ob);
    }
    void set_value (int va)
    {
        value=va;
        notify();
    }
    void dete (observe *ob)
    {
        for(int i=0;i<m_view.size();i++)
        {
            if(m_view[i]==ob)
            {
                m_view.erase(m_view.begin()+i);
                break;
            }
        }
    }
    void notify ()
    {
        for(int i=0;i<m_view.size();i++)
        {
            m_view[i]->updata(this,value);
        }
    }
    private:
    int value;//����
    vector<observe*> m_view;//ע������;
};