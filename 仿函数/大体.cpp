/*û����ôʹ�ù����廹������,�򵥼�������
1.ӵ�кͺ���һ���Ĺ���,���Ⱥ�������,�����ϲ�ռ�ռ�,ʵ��ֻռһ���ֽ�,Ч���ϸ��ں���ָ��
2.��Ҫ����operator()����,�����ǷǾ�̬�ĳ�Ա����.
3.һ��Ӧ����stl�� 
4. һ��̳�����������binary_function<_Ty, _Ty, bool>//����������,struct unary_function//һԪ����,����ֻ�м�������,û�к����ͱ�
�� 
5.������Ϊģ������еıȽ�����ʹ�� 
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
 
