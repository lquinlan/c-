/*
lambda表达式是c++11新引入的一项新功能,让你可以创建匿名函数,可以代替仿函数的功能,但是更加的方便
lambda表达式格式:
[捕获外界参数] (函数参数列表) mutable throws ->rettype {}
1.[]两种方式
	1.传值
	格式:
		int a=1;
		[a]mutable{...}
		如果不加 mutable 内部不可以修改改制 
		大致实现原理:
		class fun
		{
			private :
				int m_v;
			public :
				fun (int v):m_v(v){}
				void operator (){...} 
		};
		[=] mutable{},默认所有的外界变量均有传值
	2.传引用
	格式: 
		int a=1;
		[&a](){...}
		[&](){...} ,默认所有外界变量均是传引用
2.()
	如普通函数一样,没有参数可以忽略不写
3.throws
	抛出异常
4.retype
	因为每一个lambda函数的格式所限,所有可以采用 ->dectype(...),或者->int等在后面表明;
5.使用方式
 [](){} ();
 auto f=[](){};
 因为每一个lambda函数的类型都是独一无二的,但是可以让编译器自己去推
*/ 
#include<iostream>
#include<algorithm> 
#include<queue>
#include<vector>
using namespace std;
namespace ql19218
{
	void test1 ()//传值 
	{
		int a=3;
		auto f=[a]()mutable 
		{
			cout<<"a="<<a<<endl;
			++a;
		};
		a=54;
		f();
		f();
	}
	void test2 ()//传引用 
	{
		int a=3;
		auto f=[&a]()->void
		{
			cout<<"a="<<a<<endl;
			++a;
		};
		a=54;
		f();
		f();
	} 
	void test3 ()
	{
	
		auto cmp=[] (const int &a,const int &b)->bool
		{
			return a<b;
		};
		priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
		/*写法原因:参照c++源码
			 template<typename _Tp, typename _Sequence = vector<_Tp>,
	   typename _Compare  = less<typename _Sequence::value_type> >
	    explicit
      priority_queue(const _Compare& __x = _Compare(),
		     const _Sequence& __s = _Sequence())
      : c(__s), comp(__x)
      { std::make_heap(c.begin(), c.end(), comp); }
      因为lambda没有默认构造函数,所有需要写上 
		*/ 
		q.push(342);
		q.push(23);
		q.push(3432);
		q.push(434);
		while(!q.empty())
		{
			int i=q.top();
			q.pop();
			cout<<i<<' ';
		} 
		cout<<endl;
	}
	void test4 ()
	{
		vector<int> V{22,453,345,24,13,234,5,1,423,1,1314,90};
		sort(V.begin(),V.end(),[](int a,int b){return a<b;});
		for(auto i:V)
		{
			cout<<i<<' ';
		}
		cout<<endl;
		int x=10;
		int y=100;
		auto cmp =[x,y](int i)
		{
			return i>=x&&i<=y;
		};
		V.erase(remove_if(V.begin(),V.end(),cmp),V.end()); 
		for(auto i:V)
		{
			cout<<i<<' ';
		}
		cout<<endl;
	}
}
int main ()
{
	ql19218::test1();
	ql19218::test2();
	ql19218::test3();
	ql19218::test4();
	return 0;
}	 
