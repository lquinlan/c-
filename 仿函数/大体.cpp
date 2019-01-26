/*没有怎么使用过大体还不会用,简单几个例子
1.拥有和函数一样的功能,但比函数更快,理论上不占空间,实际只占一个字节,效率上高于函数指针
2.需要重载operator()函数,必须是非静态的成员函数.
3.一般应用与stl中 
4. 一般继承于这两个类binary_function<_Ty, _Ty, bool>//两个参数的,struct unary_function//一元参数,类中只有几个声明,没有函数和变
量 
5.可以作为模板参数中的比较器来使用 
*/ 
#include<iostream>
#include<queue> 
#include<string> 
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
class A{
	
	public: 
	A (int aa=0) :a(aa)
	{
	} 	
	 bool operator () (const A& a,const A &b)
	{
		return a.a>b.a;
	}
	int a;
	friend ostream& operator<< (ostream& os,const A& a);

};

ostream& operator<< (ostream& os,const A& a)
{ 
	os<<a.a;
	return os; 
} 
int main ()
{
	priority_queue<A,vector<A> ,A> q;
	
	q.push(A(2));
	q.push(A(24));
	q.push(A(6));
	q.push(A(1));
	//sort(q.begin(),q.end(),A());
//	for(int i=0;i<q.size();i++)
//	{
//		cout<<q[i].a<<' ';
//	}
while(q.size())
{
	//A aa=q.top();
	cout<<q.top()<<' '; 
	q.pop();
}
		
}
 
