/*
���ַ�ʽ,using #define typedef
����#defineֻ�Ǽ򵥵��ַ������滻; 
typedef ���Զ������͵ı���,��ͬ��#define,���ڱ���ʱ����м��
using ��Ϊǿ��,���������Զ������͵ı��������Զ���ģ�廯��;
ע��,ģ�����Ҫ������ȫ�ֵĵط� 
typedef ����ȡ��
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
 
