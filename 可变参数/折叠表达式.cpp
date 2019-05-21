#include<iostream>
#include<algorithm> 
using namespace std;
//c++17�¼���Ĺ���,Ϊ���Ż��ɱ��������ʹ��,���ٵݹ�ĵ���
/*
�۵����ʽ֧�� 32 ��������: +, -, *, /, %, ^, &, |, =, <, 
>, <<, >>, +=, -=, *=, /=, %=, ^=, &=, |=, <<=, 
>>=,==, !=, <=, >=, &&, ||, ,, .*, ->*.
*/
namespace t0
{
    //c++11�ľɰ汾
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
    //c++17�°汾
    //����+ *���۵������۵�������
    //1Ԫ
    template<typename... T>
    auto sum2 (T&&... args)
    {
        //���۵�((((1+2)+3)+...)+n)
        return (...+args);

    }
    template<typename... T>
    auto sum3 (T&&... args)
    {
        //���۵�(1+(2+(3+(...+n))))
        return (args+...);

    }
    //2Ԫ
    template<typename... T,typename T2>
    auto sum4 (T2&& t,T&&... args)
    {
        //3) ��Ԫ���۵� (E op ... op I) ��Ϊ (E1 op (... op (EN?1 op (EN op I))))
        return (args+...+t);

    }
    template<typename... T,typename T2>
    auto sum5 (T2&& t,T&&... args)
    {
        //4) ��Ԫ���۵� (I op ... op E) ��Ϊ ((((I op E1) op E2) op ...) op EN)
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
//����
namespace t1
{
    //���Ҹ����������������������Ŀ
    template<typename va,typename... Ar>
    auto count (va && v,Ar&&... args)
    {
        return (std::count(std::begin(v),std::end(v),args)+...);
    }
    //��ӡ
    template<typename... T>
    void printall (T&&... args)
    {
        (cout<<...<<args)<<endl;
    }
    //����
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
    //cout<<t0::sum5()<<endl;���ڳ���&& ||�Ĳ�����Ϊ��
    cout<<boolalpha<<t0::sum6(1,0,0,1)<<endl;
    cout<<boolalpha<<t0::sum6()<<endl;//Ϊ��true
    cout<<boolalpha<<t0::sum7(1,0,1,1,1)<<endl;
    cout<<boolalpha<<t0::sum7()<<endl;//Ϊ��false
    cout<<t1::count("fasdafas",'f','a','s')<<endl;
    string s("dfs");
    t1::printall(1,2,'d',s);
    /*
    cout<<...<<pack(1,2,d,dfs);
    ((((cout<<1)<<2)<<d)<<dfs)
    */
    t1::getf([](const auto & i){cout<<i;},1,2,3,4);

    /*
    ���ű��ʽ
    (f(),f(),f()...)
    */
    return 0;
}
