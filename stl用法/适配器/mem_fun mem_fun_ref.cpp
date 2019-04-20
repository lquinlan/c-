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
		void print () const{cout<<_i<<' ';}
	private:
		int _i;	
};
void t(int i,int j)
{
	cout<<"here"<<endl;
	cout<<i<<' '<<j<<endl;
}
int main ()
{
	vector<foo*> vi;
	vector<foo> v2{1,2,3,4,5};
	for(int i=0;i<10;++i)
	{
		vi.push_back(new foo(i));
	}
	for_each(vi.begin(),vi.end(),mem_fn(&foo::print));
	cout<<endl<<"---------------"<<endl;
	for_each(v2.begin(),v2.end(),mem_fun_ref(&foo::print));
	function<void(int,int)> tem=t;
	tem(1,2);
	return 0; 
}
