/*
=default 使用编译器提供的默认版本,只声明,函数体由编译器自动进行生成; 
=delete  尽用当前函数 
这两个函数一般只使用在,构造函数内,拷贝构造,复制函数,析构函数,搬移函数中;
对于一般的函数,=default不能使用,因为没有编译器提供的默认版本,=delete可以使用,但意义不大,既然不想使用,为什么还要写; 
之所以使用这两个关键字主要还是在,继承的过程中,需要调用父类的构造函数,这些都是编译器自动帮忙加上的. 
*/
#include<iostream> 
using namespace std;
namespace ql19215
{
class foo
{
	public :
		foo (int i): _i(i){} 
		foo ()=default;//需要默认的版本 
		foo (const foo& x):_i(x._i){}
//		foo (const foo& )=default;error,你自己已经写了,却还有编译器给,报错是,不可以重载
//		foo (const foo& )=delete;error,明明已经写了,却不要,报错,还是不能重载
		foo& operator = (const foo& x)
		{
			_i=x._i;
			return *this;
		} 
//		foo& operator = (const foo& )=delete;error
//		foo& operator = (const foo& x)=default;error;
//		void f ()=default;error
		void f ()=delete;
		~foo ()=default;
//		~foo ()=delete;可以但是不能创建静态对象,只能动态申请; 
	private :
		int _i;
};
} 
int main ()
{
	ql19215::foo f1; 
	ql19215::foo f2(f1);
	ql19215::foo f3;
	f3=f2;  
	return 0;
}
