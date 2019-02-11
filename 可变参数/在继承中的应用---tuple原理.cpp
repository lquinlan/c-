#include<bits/stdc++.h>
using namespace std;
namespace ql21102
{
	template<typename... Values>
	class tuple;
	template<> class tuple<> {};//空的用来终止继承
	template<typename Head,typename... Tail>
	class tuple<Head,Tail...>
		:private tuple<Tail...>//继承自自己的Tail组成的tuple 
	{
		using  inherited=tuple<Tail...>;//定义inherited 为 基类类型
		public:
			tuple(){}
			tuple (Head v,Tail... t)
				:m_head(v),inherited(t...){}//第一个赋值给m_head,其余传给基类 
		Head head ()
		{
			return m_head;
		}	
		inherited& tail ()//返回基类引用 
		{
			return *this;
		}
		protected:
			Head m_head;
	};
	template<typename Head, typename... Tail>
	ostream& operator<<(ostream& os, tuple<Head, Tail...>& tm) // 当元素个数大于1时调用该方法
	{
		os <<  tm.head() << ",";
		operator<<(os, tm.tail()); // 将tm的基类作为输出的对象 递归调用输出函数
		return os;
	}
	template<typename T>
	ostream& operator<<(ostream& os, tuple<T>& tm) // 当元素个数为 1 是调用该方法
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
其中
  Tuple<int, string, double> 继承自 Tuple<string, double>
  Tuple<string, double> 继承自 Tuple<double>
  Tuple<double> 继承自 Tuple<>
*/
