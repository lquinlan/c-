/*
����׼�����й���Template�������÷�,��֪����ʲô����,����ǰ��¼һ�� 
ͨ�����������ı�����Ӧ����һ������,ָ��������������,��һ��ģ���� 
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
