/*
三种方式,using #define typedef
其中#define只是简单的字符串的替换; 
typedef 可以定义类型的别名,不同于#define,他在编译时会进行检查
using 最为强大,它不仅可以定义类型的别名还可以定义模板化名;
注意,模板别名要定义在全局的地方 
typedef 中萃取器
template<class T>
typedef typename iterator_traits<typename T::iterator>::value_type V; 
*/
#include<iostream>
#include<vector>
template<typename T>
using Vec=std::vector<T,std::allocator<T>>;

int main ()
{
	using  p=int[5];
	typedef int p1[5];
	using p2=int*;
	typedef int* p3;
	using f=void (*)(int,int);
	typedef void (*f)(int,int);
	Vec<int> v;
	return 0;
} 
 
