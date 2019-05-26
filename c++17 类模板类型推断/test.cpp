/*
��c++17֮ǰ������,ֻ���Խ��к������͵��ƶ�,���ܽ�����ģ�����͵��ƶ�,c++��17��ʼ֧��
*/
/*
��������:
���ߣ�@zwvista
������https://www.cnblogs.com/zwvista/p/7748363.html
*/
#include<iostream>
#include<vector>
#include<functional>
#include<map>
#include<algorithm>
using namespace std;

//����pair
/*
��c++17֮ǰ�����޷�д�������Ķ���
std::pair p{1,"ds"};
��Ϊ�������޷����ݹ��캯���Ʋ�����ģ������,�޷�ʵ������
����������Ҫѡ��һ�����еİ취
auto p=make_pair(1,"ds");
���������ݺ��������������Ʋ����ģ�������
�����������ǿ�������һ��ʹ��
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
    // ����������Ƕ�����ͣ��޷������Զ��Ƶ�
    Container(typename Traits<T>::type v) {}
};
 
// ָ���ƶ���
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
 
//  map m = {{1, "a"s}, {2, "b"s}}; // {1, "a"s} ����ʹ�ô����ŵĳ�ʼ���б�û������
                                    // ���Ա������޷��Զ��Ƶ� map ��ģ��Ĳ�������
    map m = {pair{1, "a"s}, {2, "b"s}}; // C++17
//  map<int, string> m = {{1, "a"s}, {2, "b"s}}; // C++14
    foo c{(int*)0}; // ���ù����� 1
    int x; foo c2{x}; // ���ù����� 3
    foo c3{0}; // ���ù����� 2
    de d;
    foo c4{(int*)0, d}; // ���ù����� 4
//  ���ϱ������Զ��Ƶ��Ľ������ foo<int>
    Container c1{0}; //  �������Զ��Ƶ��Ľ���� Container<int>
}
