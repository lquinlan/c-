/*
=default ʹ�ñ������ṩ��Ĭ�ϰ汾,ֻ����,�������ɱ������Զ���������; 
=delete  ���õ�ǰ���� 
����������һ��ֻʹ����,���캯����,��������,���ƺ���,��������,���ƺ�����;
����һ��ĺ���,=default����ʹ��,��Ϊû�б������ṩ��Ĭ�ϰ汾,=delete����ʹ��,�����岻��,��Ȼ����ʹ��,Ϊʲô��Ҫд; 
֮����ʹ���������ؼ�����Ҫ������,�̳еĹ�����,��Ҫ���ø���Ĺ��캯��,��Щ���Ǳ������Զ���æ���ϵ�. 
*/
#include<iostream> 
using namespace std;
namespace ql19215
{
class foo
{
	public :
		foo (int i): _i(i){} 
		foo ()=default;//��ҪĬ�ϵİ汾 
		foo (const foo& x):_i(x._i){}
//		foo (const foo& )=default;error,���Լ��Ѿ�д��,ȴ���б�������,������,����������
//		foo (const foo& )=delete;error,�����Ѿ�д��,ȴ��Ҫ,����,���ǲ�������
		foo& operator = (const foo& x)
		{
			_i=x._i;
			return *this;
		} 
//		foo& operator = (const foo& )=delete;error
//		foo& operator = (const foo& x)=default;error;
//		void f ()=default;error
		void f ()=delete;
		~foo ()=default;
//		~foo ()=delete;���Ե��ǲ��ܴ�����̬����,ֻ�ܶ�̬����; 
	private :
		int _i;
};
} 
int main ()
{
	ql19215::foo f1; 
	ql19215::foo f2(f1);
	ql19215::foo f3;
	f3=f2;  
	return 0;
}
