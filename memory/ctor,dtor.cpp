/*
����delete �� delete[]�������õ�������û�й�ϵ��,��Ϊ���ڴ�ģ���м�¼�ŷ����˶��ٸ�,���Ƕ���
����,delete��delete[]����������,���,���ô���,�ͻ���ɱ���,������Ϊ,����delete���ڴ�ģ��ȥƥ��ᷢ��ƥ�䲻��,����һ����¼'
��С���ڴ��,ͬ��,delete[]Ҳ�漰�����ö��ٴ���������,�������к���ָ������,�ͻᷢ���ڴ�й¶ 
*/
#include<iostream>
using namespace std;
class foo{
    public:
        foo ():id(0){cout<<"default:"<<this<<' '<<id<<endl;};
        foo (int _id):id(_id){cout<<"argu ctor this="<<this<<"id= "<<id<<endl;}
        ~foo (){cout<<"dtor this="<<this<<"id="<<id<<endl;}
        void get ()
        {
            cout<<"id="<<id<<endl;
        }
    private:
        int id;
};
int main ()
{
    foo* p=new foo[5];
    foo* t=p;
    for(int i=0;i<5;++i)
    {
        new(t++) foo(i);
    }
    cout<<"p="<<p<<' '<<"t="<<t<<endl;
    delete[] p;
    cout<<"de af p="<<p<<endl;
    p->get();
    ++p;
	p->get();
	++p;
	p->get();
	++p;
	p->get(); 
    return 0;
}
