/*
	*目的在于将无法匹配的的函数套接成可以匹配的类型 
	*如在 vector<int> vi{0,0,0,0,0,0,11,3,1};
	*我们想匹配到第一个非零的数,也许我们想借用find_if和
	*not_equal_to写成这样的形式
	*auto it=find_if(vi.begin(),vi.end(),not_equal_to<int>(0));
	*但实际上不行,因为not_equal_to的仿函数接受的是两个,参数,而在这里
	*你只给了第一个参数,编译器会无法匹配到着函数
	*而这个时候函数适配器就有了作用,你可以写成这样的形式
	*auto it=find_if(vi.begin(),vi.end(),bind1st(not_equal_to<int>(),0); 
	*原理见适配器文件夹
	*很不幸上诉所分析的在c++11之后被弃用(原因的不定参数对于c++程序的巨大,影响,现在已经由,bind
	*进行替代,bind可以绑定,任意个数的成员
	*使用时需要using namespace std::placeholders;
	*其中_1,_2,_3,..._N是占位符,表示这些没有绑定的变量,调用的参数是,如何绑定,如第一个给出的实参
	*绑定所以出现_1的地方,以此类推 
	*用法:https://zh.cppreference.com/w/cpp/utility/functional/bind
	*限于本人目前,水平低下,暂时无力解释新版的原理,以后有能力进行补充; 
	
*/
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std::placeholders;
using namespace std;
class foo
{
	public:
		foo (int i=0,int j=0):_i(i),_j(j){}
		void print (int t) const{cout<<_i+t<<' ';}
		int _j; 
	private:
		int _i;	
};
int main ()
{
	vector<int> vi{0,0,0,0,0,0,0,0,12,232};
	//auto it=find_if(vi.begin(),vi.end(),bind1st(not_equal_to<int>(),0));
	auto it=find_if(vi.begin(),vi.end(),bind(not_equal_to<int>(),_1,0));
	//auto it1=find_if(vi.begin(),vi.end(),bind2nd(greater<int>(),0));
	auto it1=find_if(vi.begin(),vi.end(),bind(greater<int>(),_1,0));
	cout<<*it<<endl; 
	cout<<*it1<<endl;
	foo fo;
	auto f=bind(&foo::print,fo,_1);
	f(10);
	auto f1=bind(&foo::_j,_1);
	cout<<f1(fo)<<endl;
	auto f2=[](int i,int j){
		return i<j;
	} ;
	auto f3=bind(f2,_1,2);
	cout<<boolalpha<<f3(11)<<endl;
	function<bool(int,int)> f4=f2;
	auto f5=bind(f4,_1,2);
	cout<<boolalpha<<f5(11)<<endl;	
	return 0;
}

