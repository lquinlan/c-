/*
在c++17之前编译器,只可以进行函数类型的推断,不能进行类模板类型的推断,c++从17开始支持
*/
/*
代码来自:
作者：@zwvista
出处：https://www.cnblogs.com/zwvista/p/7748363.html
*/
#include<iostream>
#include<vector>
#include<functional>
#include<map>
#include<algorithm>
using namespace std;

//比如pair
/*
在c++17之前我们无法写出这样的东西
std::pair p{1,"ds"};
因为编译器无法根据构造函数推测出类的模板类型,无法实例化它
所以我们需要选择一个折中的办法
auto p=make_pair(1,"ds");
编译器根据函数参数的类型推测出类模板的类型
但是现在我们可以像函数一样使用
*/
template<typename T>
struct foo
{
    foo (T* ptr){cout<<1<<endl;}//1
    foo(const T&v){cout<<2<<endl;}//2
    foo (T& v){cout<<3<<endl;}//3
    template<typename D>
    foo (T* ptr,D & de){cout<<4<<endl;}//4
    /* data */
};
struct de {};

template<typename T>
struct Traits { using type = T; };
 
template<typename T>
struct Container
{
    // 参数类型是嵌套类型，无法进行自动推导
    Container(typename Traits<T>::type v) {}
};
 
// 指明推断向导
template<typename T>
Container(T) -> Container<T>;
int main()
{
    vector a = {1, 2, 3};  // C++17
//  vector<int> a = {1, 2, 3};  // C++14
    function f = [](int a){return a + 1;};  // C++17
//  function<int(int)> f = [](int a){return a + 1;};  // C++14
    tuple t{1, 2,5, "a"s};  // C++17
//  tuple<int, double, string> t{1, 2,5, "a"s};  // C++14
//  auto t = make_tuple(1, 2,5, "a"s);  // C++14
    sort(a.begin(), a.end(), greater{}); // C++17
//  sort(a.begin(), a.end(), greater<>{});  // C++14
//  sort(a.begin(), a.end(), greater<int>{});  // C++11
 
//  map m = {{1, "a"s}, {2, "b"s}}; // {1, "a"s} 这种使用大括号的初始化列表没有类型
                                    // 所以编译器无法自动推导 map 类模板的参数类型
    map m = {pair{1, "a"s}, {2, "b"s}}; // C++17
//  map<int, string> m = {{1, "a"s}, {2, "b"s}}; // C++14
    foo c{(int*)0}; // 调用构造器 1
    int x; foo c2{x}; // 调用构造器 3
    foo c3{0}; // 调用构造器 2
    de d;
    foo c4{(int*)0, d}; // 调用构造器 4
//  以上编译器自动推导的结果都是 foo<int>
    Container c1{0}; //  编译器自动推导的结果是 Container<int>
}
