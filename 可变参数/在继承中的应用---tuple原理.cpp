#include<bits/stdc++.h>
using namespace std;
namespace ql21102
{
	template<typename... Values>
	class tuple;
	template<> class tuple<> {};//�յ�������ֹ�̳�
	template<typename Head,typename... Tail>
	class tuple<Head,Tail...>
		:private tuple<Tail...>//�̳����Լ���Tail��ɵ�tuple 
	{
		using  inherited=tuple<Tail...>;//����inherited Ϊ ��������
		public:
			tuple(){}
			tuple (Head v,Tail... t)
				:m_head(v),inherited(t...){}//��һ����ֵ��m_head,���ഫ������ 
		Head head ()
		{
			return m_head;
		}	
		inherited& tail ()//���ػ������� 
		{
			return *this;
		}
		protected:
			Head m_head;
	};
	template<typename Head, typename... Tail>
	ostream& operator<<(ostream& os, tuple<Head, Tail...>& tm) // ��Ԫ�ظ�������1ʱ���ø÷���
	{
		os <<  tm.head() << ",";
		operator<<(os, tm.tail()); // ��tm�Ļ�����Ϊ����Ķ��� �ݹ�����������
		return os;
	}
	template<typename T>
	ostream& operator<<(ostream& os, tuple<T>& tm) // ��Ԫ�ظ���Ϊ 1 �ǵ��ø÷���
	{
		os<<tm.head();
		return os;
	}
} 
int main ()
{
	ql21102::tuple<int,string,double> my (1,"fg",2.3);
	cout<<my.head()<<endl; 
	cout<<my.tail().head()<<endl;
	cout<<my<<endl;
}
/*
����
  Tuple<int, string, double> �̳��� Tuple<string, double>
  Tuple<string, double> �̳��� Tuple<double>
  Tuple<double> �̳��� Tuple<>
*/
