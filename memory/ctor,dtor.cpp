/*
对于delete 和 delete[]对于内置的类型是没有关系的,因为再内存模型中记录着分配了多少个,但是对于
对象,delete和delete[]就有区别了,如果,调用错了,就会造成崩溃,这是因为,按照delete的内存模型去匹配会发生匹配不上,多了一个记录'
大小的内存快,同样,delete[]也涉及到调用多少次析构函数,对于类中含有指针的情况,就会发生内存泄露 
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
