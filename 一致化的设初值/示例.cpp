#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;
namespace ql1921401 
{
	void test ()
	{
		int v[] {123,34,5,54};
		for(auto i:v)
		{
			cout<<i<<' ';
		}
		cout<<endl;
		vector<string> s{"dsfds","sad","dsad"}; 
		for(auto i:s)
		{
			cout<<i<<' ';
		}
		cout<<endl;
		cout<<max({342,234,131424,2352,5234,1242,3}); 
		int i{19} ;
		int j{0.5};//应该是error,但GCC只报warning 
	}
}
int main ()
{
	ql1921401::test();
	return 0; 
}
/*
原理:
	编译器会形成一个initialization list的东西,initialiaztion list背后依赖一种array的东西
	如果构造函数有传initialization list编译器就直接传着一包东西,否则编译器将他们分解成一个
	,一个,传到相应的构造函数,如果没有对应个数的构造函数,编译器会报错; 
*/ 
 
