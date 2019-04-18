/*
    对于设计及对于同一份数据,具有不同的表现形式,且同一份数据改变,不同的表现形式全改变,可以用到,这种设计模式
    我们设计一个父类,表示他的形式,同时不同的形式可以再次基础上进行派生,同业我们知道,可以用父类的指针,指向子类,这样,当我们
    需要一种表现,形式时,我们向,subject进行注册,这样数据发生改变时,调用其updata导致所有数据均改变.
*/
#include<iostream>
#include<vector>
using namespace std;
class subject;
class observe{
    public:
    virtual void updata (subject* sub,int m_view);
};
class subject{
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
                delete m_view[i];
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
    ~subject ()
    {
         for(int i=0;i<m_view.size();i++)
        {
           delete m_view[i];
        }
    }
    private:
    int value;//数据
    vector<observe*> m_view;//注册容器;
};
