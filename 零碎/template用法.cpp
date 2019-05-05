/*
看标准库中有关于Template的这种用法,不知道叫什么名字,先提前记录一下 
通过看编译器的报错这应该是一个用来,指明后面所属的类,是一个模板类 
*/
#include<iostream>
using namespace std;
template <class T>
class A
{
	template <class U>
	class B
	{
		typedef A<U> other;
	};
};
template<class T1,class T2>
class test
{
	typedef typename T1:: template B<T2>::other t1_type;
};
int main ()
{
	
}
