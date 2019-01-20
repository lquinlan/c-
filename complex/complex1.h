//复数类，模板实现；
/*
    *1.关于类模板的前置声明
        需要在前面添加template<>声明；
    *2.关于在类外定义的成员函数和全域函数
         在类外定义的的成员函数和全域函数，凡是用到该类的地方都需要写成class（类名）<typename>;
    *3.关于类模板的友元函数
        *（1）友元函数写在类模板中，不会有奇怪的问题；
        *（2）类内声明，类外定义
            （1）增加前置声明
            （2）类中的声明增加<t>显示的参数列表，表明是之前声明的一个实列；
    *** 关于模板的使用在《c++ prime》16章（577）中有详细的介绍（事后恶补）；
	*4.同一个类之间的对象互为友元
    *5.关于返回参数是传值还是传引用,看存放结果的东西是否原来已经存在
    *6.typename()创建临时对象,声明周期只存在于当前行
    c++基础语法掌握的太差劲了，需要恶补了?；
*/
//防卫式的声明
/*避免重复声明*/
#ifndef __complex1_h__
#define __complex1_h__
#include<iostream>
using namespace std;
//必要的前置声明
template<class T1,class T2>
class com;
template<class T1,class T2>
com<T1,T2>& _dopt (com<T1,T2>*,const com<T1,T2> &);
template<class T1,class T2>
//类的声明
/*
    类的大致分类
        1.不带指针的类
            对于不带指针的类，我们不必太在意，其拷贝构造，拷贝复制（编译器默认的基本就可以完成操作，编译器选择的复制方式是，一个bit一个bit的填充）
            同样如果没有特殊的需求，我们同样可以考虑系统默认的析构函数；
        2.对于带指针的类，将在下个例子中进行介绍；
*/
class com{
    public:
        com<T1,T2> (T1 r,T2 v) :re(r),im(v){}
        com<T1,T2> ():re(0),im(0){}
        //关于构造函数的写法
        /*
            简单讲就是初始化和赋值的区别；
            在参数列表的是初始化
            在函数体内的是赋值
            两者最终实现的效果虽然一样但是发生的时间和方式完全不同
            我们更加推荐使用参数列表这种更加正规的方式，以防出现一些不必要的错误；
        */
        com<T1,T2> & operator += (const com<T1,T2>&);
        //关于返回值的传递是引用还是传值
        /*
            通常情况下引用的效率要高于传值；
            简单的来说我们在可以传递引用的情况尽量都使用传引用
            不可以传引用的情况，返回的结果实在函数体中临时生成的，在这种情况下，只能传值，其他没用特殊的说明，皆可传引用
            甚至有些情况下只能传递引用，如一些操作符的连+/-等；
        */
        T1 real ()const
        {
            return re;
        }
        T2 imag ()const
        {
            return im;
        }
        //关于常成员函数
        /*
            对于成员函数我们需要考虑清楚，该函数是否会修改，成员变量的值
            如果不会修改，一定要+const告诉编译器，以防使用者在使用时发生错误；
        */
    private:
        T1 re;
        T2 im;
    friend com<T1,T2>& _dopt<T1,T2> (com<T1,T2>*,const com<T1,T2>&);
};
template<class T1,class T2>
inline T1 real (const com<T1,T2> & x)
{
    return x.real();
}
template<class T1,class T2>
inline T2 imag (const com<T1,T2>& x)
{
    return x.imag();
}
template<class T1,class T2>
inline com<T1,T2>& _dopt (com<T1,T2> *ths,const com<T1,T2>& r)
{
    ths->re+=r.re;
    ths->im+=r.im;
    return *ths;
}
template<class T1,class T2>
inline com<T1,T2>& com<T1,T2>::operator+=(const com<T1,T2>& r)
{
    return _dopt(this,r);
}
template<class T1,class T2>
inline com<T1,T2> operator+ (const com<T1,T2>& x,const com<T1,T2>& y)
{
    return com<T1,T2>(real(x)+real(y),imag(x)+imag(y));
}
template<class T1,class T2>
inline com<T1,T2> operator + (T1 x,const com<T1,T2>& y)
{
    return com<T1,T2>(real(y)+x,imag(y));
}
template<class T1,class T2>
inline com<T1,T2> operator+ (const com<T1,T2>& x,T1 y)
{
    return com<T1,T2>(real(x)+y,imag(x));
}
template<class T1,class T2>
ostream& operator<< (ostream& os,const com<T1,T2>& x)
{
    os<<"("<<real(x)<<','<<imag(x)<<")";
}
template<class T1,class T2>
inline const com<T1,T2>& operator+ (const com<T1,T2> &x)
{
    return x;
}
template<class T1,class T2>
inline com<T1,T2> operator- (const com<T1,T2> &x)
{
    return com<T1,T2>(-real(x),-imag(x));
}
template<class T1,class T2>
inline bool operator == (const com<T1,T2> & x,const com<T1,T2> y)
{
    return real(x)==real(y)&&imag(x)==imag(y);
}
template<class T1,class T2>
inline com<T1,T2> conj (const com<T1,T2>& x )
{
    return com<T1,T2>(real(x),-imag(x));
}
#endif
