#include<iostream>
using namespace std;
int a[7]={1,2,3,4,5,6,7};
//����һ:ʹ�ñ��� 
typedef int arr1[7];
using arr2=int[7];
arr1* test0 ()
{
	return &a;
}
arr1& test1 ()
{
	return a;
}
//������
int (*test2())[7] 
{
	return &a;
}
int (&test3())[7]
{
	return a;
}
//������
auto test4 ()->int(*)[7]
{
	return &a;	
} 
auto test5 ()->int(&)[7]
{
	return a;
}
//������
decltype(a) *test6 ()
{
	return &a;
}
decltype(a) &trst7 ()
{
	return a;
}
int main ()
{
	int (*p)[7]=test6();
	cout<<sizeof(*p)<<endl;
	cout<<(*p)[6]<<endl;
}
