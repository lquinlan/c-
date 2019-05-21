#include<iostream>
#include<algorithm> 
using namespace std;
//c++17新加入的规则,为了优化可变参数包的使用,减少递归的调用
/*
折叠表达式支持 32 个操作符: +, -, *, /, %, ^, &, |, =, <, 
>, <<, >>, +=, -=, *=, /=, %=, ^=, &=, |=, <<=, 
>>=,==, !=, <=, >=, &&, ||, ,, .*, ->*.
*/
namespace t0
{
    //c++11的旧版本
    template<class t>
    t sum1 (t&& v)
    {
        return v;
    }
    template<typename t1,typename... t2>
    t1 sum1 (t1&& v,t2&&... args)
    {
        return v+sum1(forward<t2>(args)...);
    }
    //c++17新版本
    //对于+ *左折叠和右折叠无区别
    //1元
    template<typename... T>
    auto sum2 (T&&... args)
    {
        //左折叠((((1+2)+3)+...)+n)
        return (...+args);

    }
    template<typename... T>
    auto sum3 (T&&... args)
    {
        //右折叠(1+(2+(3+(...+n))))
        return (args+...);

    }
    //2元
    template<typename... T,typename T2>
    auto sum4 (T2&& t,T&&... args)
    {
        //3) 二元右折叠 (E op ... op I) 成为 (E1 op (... op (EN?1 op (EN op I))))
        return (args+...+t);

    }
    template<typename... T,typename T2>
    auto sum5 (T2&& t,T&&... args)
    {
        //4) 二元左折叠 (I op ... op E) 成为 ((((I op E1) op E2) op ...) op EN)
        return (t+...+args);

    }
    template<typename... T>
    auto sum6 (T&&... args)
    {
        
        return (...&&args);

    }
    template<typename... T>
    auto sum7 (T&&... args)
    {
        
        return (...||args);

    }
}
//例子
namespace t1
{
    //查找给定容器所包含多个数的数目
    template<typename va,typename... Ar>
    auto count (va && v,Ar&&... args)
    {
        return (std::count(std::begin(v),std::end(v),args)+...);
    }
    //打印
    template<typename... T>
    void printall (T&&... args)
    {
        (cout<<...<<args)<<endl;
    }
    //调用
    template<typename T1,typename... T2>
    void getf (T1 && f,T2&&... args)
    {
        (...,f(args));
    }

}
int main ()
{
    cout<<t0::sum1(1,2,3,4,5,6)<<endl;
    cout<<t0::sum2(1,2,3,4,5,6)<<endl;
    cout<<t0::sum3(1,2,3,4,5,6)<<endl;
    cout<<t0::sum4(1,2,3,4,5,6)<<endl;
    cout<<t0::sum5(1,2,3,4,5,6)<<endl;
    //cout<<t0::sum5()<<endl;对于除了&& ||的不可以为空
    cout<<boolalpha<<t0::sum6(1,0,0,1)<<endl;
    cout<<boolalpha<<t0::sum6()<<endl;//为空true
    cout<<boolalpha<<t0::sum7(1,0,1,1,1)<<endl;
    cout<<boolalpha<<t0::sum7()<<endl;//为空false
    cout<<t1::count("fasdafas",'f','a','s')<<endl;
    string s("dfs");
    t1::printall(1,2,'d',s);
    /*
    cout<<...<<pack(1,2,d,dfs);
    ((((cout<<1)<<2)<<d)<<dfs)
    */
    t1::getf([](const auto & i){cout<<i;},1,2,3,4);

    /*
    逗号表达式
    (f(),f(),f()...)
    */
    return 0;
}
