/*
	*在c++11之后应该尽量使用新改变的版本mem_fn,源代码解释使用的时mem_fun 
	*这俩个仿函数适配器是用来匹配成员函数的 
*/
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
class foo
{
	public:
		foo (int i=0):_i(i){}
		void print () {cout<<_i<<' ';}
	private:
		int _i;	
};
int main ()
{
	vector<foo*> vi;
	for(int i=0;i<10;++i)
	{
		vi.push_back(new foo(i));
	}
	for_each(vi.begin(),vi.end(),mem_fun(&foo::print));
	return 0; 
}
