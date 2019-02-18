#include<iostream>
using namespace std;
namespace ql19216
{
	template<typename T, typename U>
	auto add(T t, U u) -> decltype(t + u) // ��������������ģ���β�
	{
    	return t+u;
	}
	int gettype ();
	void test ()
	{
		int temp1=1;
		decltype(temp1) temp2;//int
		decltype(gettype()) temp3;//int,ֻ���������� 
		cout<<sizeof(temp3)<<endl;  
		const int temp4=5;
		decltype(temp4) temp5=1; //const int ���븳��ֵ 
	//	temp5=temp1; error
		const int *const temp6=&temp1;
		decltype(temp6) temp7=&temp2;//decltype() �ȱ�������const ,Ҳ�����ײ�const 
	//	temp7=&temp1;error
	//	*temp7=9;error
		int& temp8=temp1;
		decltype(temp8) temp9=temp1;//�ƶ�Ϊ�������� 
		temp9=666;
		cout<<temp1<<endl;
		decltype((temp1)) temp10=temp1;//��˫����,��ʾ�������� 
		temp10=999;
		cout<<temp1<<endl;
		int *temp11=&temp1;
		decltype(*temp11) temp12=temp1;//������,�ƶϳ�Ϊ�������� 
		temp12=233;
		cout<<temp1<<endl; 
		const int &temp13=temp1;
		decltype(temp13) temp14=temp1;//const int &
	//	temp14=10; error
	}
} 
int main ()
{
	ql19216::test();
	auto a=ql19216::add(1,3);
	cout<<a<<endl;
	auto f = [](int a, int b) ->decltype(a*b+a+b)//lambda���� 
    {
        return a * b+a+b;
    };
	decltype(f) g=f; // lambda �������Ƕ�����������
    int i=f(2, 2);
    int j=g(3, 3);
    cout<<i<<' '<<j<<endl; 
	return 0;
}
