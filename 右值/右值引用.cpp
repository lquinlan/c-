/*
��ֵ����,��c++11�·�����һ���﷨,����Ŀ���Ǽ��ٲ���Ҫ����,�ر�������ʱ�����Ŀ���,
��ֵ���Ǹ��߱���,����������Ա�������͵
�﷨����:Type &&T;
ע����ֵ����,�ڴ��ݵĹ����п���,������͵ĸı�,����������Ҫforward()����,��move()������ά�� 
*/
#include<iostream>
using namespace std;
void p (int &&i)
{
	cout<<"��ֵ"<<endl; 
	cout<<i<<endl;
}
void p (int &i)
{
	cout<<"��ֵ"<<endl;
	cout<<i<<endl; 
}
void f(int &&i)
{
	cout<<"f: ��ֵ"<<endl;
	p(i); 
}
void f1 (int &&i)
{
	cout<<"f1 :��ֵ"<<endl;
	p(forward<int>(i)); 
}
int main ()
{
	p (1);
	p (10);
	int i=10;
	p (i);
	f (10);//�����봫�ݵ�����ֵ,������f������ȴ���õ���p����ֵ�汾,����������Ҫforward����������,�����ı���ģ�� 
	f1 (11);
	//f(i);//error,f��Ҫ������ֵ����,����i����ֵ,���ǿ���ʹ��move�����ı����������
	f1(move(i));
	//i=9;
	cout<<i<<endl; 
	return 0;
} 
