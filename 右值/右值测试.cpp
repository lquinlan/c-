/*
一般情况下:位于赋值符号的左边的是左值,位于赋值符号右边的是右值
另外,临时变量都是右值,右值是不能出现在赋值号左边,但是,c++自定义的类型,可能并完全符合 
一般情况下,左值是由内存的,右值仅仅代表值
 
*/ 
#include<iostream>
#include<string>
#include<complex>
using namespace std;
int main ()
{
	int a,b;
	a=10;//a是左值,10是右值 
	b=11;//b是左值,11是右值
	//a+b=19;//error,错误,a+b是右值,不能出现在左边 
	string s("sdd");
	string c("3424");
	s+c={"243"};//虽然s+c应该是右值,但是因为是自己定义的对象,所有没有严格的遵循,左值,右值的定义 
	cout<<s<<' '<<c<<endl;
	return 0; 
}
