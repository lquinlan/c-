/*
	*��c++11֮��Ӧ�þ���ʹ���¸ı�İ汾mem_fn,Դ�������ʹ�õ�ʱmem_fun 
	*�������º���������������ƥ���Ա������ 
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
