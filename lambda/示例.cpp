/*
lambda���ʽ��c++11�������һ���¹���,������Դ�����������,���Դ���º����Ĺ���,���Ǹ��ӵķ���
lambda���ʽ��ʽ:
[����������] (���������б�) mutable throws ->rettype {}
1.[]���ַ�ʽ
	1.��ֵ
	��ʽ:
		int a=1;
		[a]mutable{...}
		������� mutable �ڲ��������޸ĸ��� 
		����ʵ��ԭ��:
		class fun
		{
			private :
				int m_v;
			public :
				fun (int v):m_v(v){}
				void operator (){...} 
		};
		[=] mutable{},Ĭ�����е����������д�ֵ
	2.������
	��ʽ: 
		int a=1;
		[&a](){...}
		[&](){...} ,Ĭ���������������Ǵ�����
2.()
	����ͨ����һ��,û�в������Ժ��Բ�д
3.throws
	�׳��쳣
4.retype
	��Ϊÿһ��lambda�����ĸ�ʽ����,���п��Բ��� ->dectype(...),����->int���ں������;
5.ʹ�÷�ʽ
 [](){} ();
 auto f=[](){};
 ��Ϊÿһ��lambda���������Ͷ��Ƕ�һ�޶���,���ǿ����ñ������Լ�ȥ��
*/ 
#include<iostream>
#include<algorithm> 
#include<queue>
#include<vector>
using namespace std;
namespace ql19218
{
	void test1 ()//��ֵ 
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
	void test2 ()//������ 
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
		/*д��ԭ��:����c++Դ��
			 template<typename _Tp, typename _Sequence = vector<_Tp>,
	   typename _Compare  = less<typename _Sequence::value_type> >
	    explicit
      priority_queue(const _Compare& __x = _Compare(),
		     const _Sequence& __s = _Sequence())
      : c(__s), comp(__x)
      { std::make_heap(c.begin(), c.end(), comp); }
      ��Ϊlambdaû��Ĭ�Ϲ��캯��,������Ҫд�� 
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
