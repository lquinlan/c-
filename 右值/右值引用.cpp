/*
右值引用,是c++11新发布的一种语法,他的目的是减少不必要拷贝,特别是在临时变量的拷贝,
右值引是告诉别人,这个变量可以被人用来偷
语法规则:Type &&T;
注意右值引用,在传递的过程中可能,造成类型的改变,所有我们需要forward()函数,和move()函数来维持 
*/
#include<iostream>
using namespace std;
void p (int &&i)
{
	cout<<"右值"<<endl; 
	cout<<i<<endl;
}
void p (int &i)
{
	cout<<"左值"<<endl;
	cout<<i<<endl; 
}
void f(int &&i)
{
	cout<<"f: 右值"<<endl;
	p(i); 
}
void f1 (int &&i)
{
	cout<<"f1 :右值"<<endl;
	p(forward<int>(i)); 
}
template<class T>
void f1 (T &&i)
{
	cout<<"thisi r"<<endl;
}
template<class T>
void f1 (T &i)
{
	cout<<"this l"<<endl;	
} 
int main ()
{
//	p (1);
//	p (10);
	int i=10;
//	p (i);
//	f (10);//我们想传递的是右值,但是在f函数中却调用的是p的左值版本,所有我们需要forward函数来保持,变量的本来模样 
	f1 (forward<int>(i));
	f1 (forward<int&>(i));
	f1 (forward<int&&>(i));
	//f(i);//error,f想要的是右值引用,但是i是左值,我们可以使用move函数改变变量的属性
	//f1(move(i));
	//i=9;
	//cout<<i<<endl; 
	return 0;
} 
