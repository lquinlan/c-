//using �÷�һ
namespace ql01
{
	//using namespace �����ռ�;
	using namespace std; 
} 
//using �÷���
namespace ql02 
{
	//��ĳһ���Ͷ����������typedef����һ����
	//using ���ͱ���=ԭ����;
	using uint=unsigned int;
	uint i=0;//�൱��unsigned int;
}
//using �÷��� 
namespace ql03
{
	//��������˽�м̳�,�����public,protected����˽��,�����Ǳ�ɹ��еķ�����:
	//using ���� :: ������
	class A
	{
		public :
			int a;
	} ;
	class B:private A
	{
		public:
		using A::a;
	};
}
//using �÷��� 
#include<iostream>
using namespace std;
namespace ql04
{
	/*
	��������г�Ա�����ж�����ذ汾������������ض������̳е� 0 �������汾��
	����ͨ����������ֻ�ܷ������������ض������Щ�汾��
	���������������ͨ����������ʹ�����е����ذ汾�������������Ҫô�ض����������ذ汾��Ҫôһ��Ҳ���ض��塣
	��ʱ����Ҫ�����ض���һ�����ؼ���ĳЩ�汾����Ϊ��������Ҫ�̳������汾�ĺ��壬����������£�Ϊ���ض�����
	Ҫ�ػ���ĳ���汾�����ò��ض���ÿһ������汾�����ܻ������ᷳ����������������Ϊ���س�Ա�����ṩ using ����
	��Ϊ�����Ա�������ƶ����� using �������ú�������������ʵ���ӵ�������������򣩣�ʹ�����಻���ض������̳е�
	ÿһ������汾��һ�� using ����ֻ��ָ��һ�����֣�����ָ���βα�
	ʹ��using���������ּ���������֮��������ֻ��Ҫ�ض��屾����ȷʵ���붨�����Щ�������������汾����ʹ�ü�
	�еĶ��塣
	*/

class Base
{
public:    
   void menfcn()
  {
     cout<<"Base function"<<endl; 
  }

    void menfcn(int n)
    {
     cout<< cout<<"Base function with int"<<endl; 
    }

};

class Derived : Base
{
public:    
	using Base::menfcn;//using����ֻ��ָ��һ�����֣����ܴ��βα�    
	int menfcn(int)
	{ 
		cout<< cout<<"Derived function with int"<<endl;
	}
};
void test()
{    
	Base b; 
    Derived d;   
  	b.menfcn();   
  	d.menfcn();
}
}
