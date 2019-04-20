#include<functional>
#include<iostream>
using namespace std;
class foo
{
	public:
		explicit foo (int _i=0):i(_i){}
		void add (const int& j) const
		{
			cout<<"i+j="<<i+j<<endl;
		}
		int i;
};
void print (const int& num)
{
	cout<<"this is print"<<endl;
	cout<<num<<endl;
}
class print_num
{
	public:
	void operator() (const int & i)
	{
		cout<<"this operator()"<<endl; 
		cout<<i<<endl;	
	}	
};
int main ()
{
	//储存自由函数
	function<void(const int&)> f0=print;
	int n=10;
	f0(n);
	//储存Lambad
	function<bool(int)> f1=[&n](int i)mutable {--n;return n<i;};
	cout<<boolalpha<<f1(10)<<endl;
	//存储到 std::bind 调用的结果
	function<void()> f2=bind(print,123);
	f2();
	//存储到成员函数的调用
	function<void(const foo&,int)> f3=&foo::add;
	foo fo(10);
	f3(fo,100);
	//f3(11,11); error 
	// 存储到数据成员访问器的调用
	std::function<int(foo const&)> f_num = &foo::i;
    std::cout << "num_: " << f_num(fo) << '\n';
    // 存储到成员函数及对象的调用
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &foo::add, fo, _1 );
    f_add_display2(2);
    // 存储到成员函数及对象指针的调用
    std::function<void(int)> f_add_display3 = std::bind( &foo::add, &fo, _1 );
    f_add_display3(2);
    //储存仿函数的调用
	function<void(int)> f4=print_num();
	f4(10);
	 
	return 0; 
}
