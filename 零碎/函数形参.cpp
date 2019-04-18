#include<iostream>
#include<initializer_list>
using namespace std;
//函数类型作为参数
namespace ql32401
{
	template<typename T,typename comp>
	T max (initializer_list<T> t,comp cmp)
	{
		auto st=t.begin();
		auto se=t.end();
		T maxn=*st;
		while(st!=se)
		{
			if(cmp(maxn,*st))
			{
				maxn=*st;
			}
			++st;
		}
		return maxn;
	}
}
//函数指针类型作为参数,等同于第一种, 
namespace ql32402
{
	template<typename T>
	T max (initializer_list<T> t,bool (*cmp) (const T& s1,const T& s2))
	{
		auto st=t.begin();
		auto se=t.end();
		T maxn=*st;
		while(st!=se)
		{
			if(cmp(maxn,*st))
			{
				maxn=*st;
			}
			++st;
		}
		return maxn;
	}
}
//起别名 typedef不能用于模板,就不演示了 
namespace ql32403 
{
	template<typename T>
	using cp=bool(const T& ,const T&); 
	template<typename T>
	T max (initializer_list<T> t,cp<T> cmp)
	{
		auto st=t.begin();
		auto se=t.end();
		T maxn=*st;
		while(st!=se)
		{
			if(cmp(maxn,*st))
			{
				maxn=*st;
			}
			++st;
		}
		return maxn;
	}
}
//其他形式的定义 
namespace ql32404
{
	bool cmp (const int& t1,const int &t2)
	{
		return t1<t2;	
	} 
	typedef decltype(cmp) f;
}
//返回类型为函数指针,这个需要注意,编译器不会自动将其转换成函数指针,所以需要明确表明,他是函数指针 
//最好是使用别名,或者后置返回类型+decltype,使用decltype时需要显示的加上*,如果在知道返回函数的情况下
//也可以直接使用decltype,同样需要显示的加上* 
#include<string> 
namespace ql32405
{
	size_t sum1 (const string& s1)
	{
		size_t sum=0;
		for(auto i:s1)
		{
			sum+=static_cast<size_t>(i);
		}
		return sum;
	}
	using ff=size_t (const string&) ;
	auto f ()-> decltype(&sum1)
	{
		
	}
	decltype(sum1) *ff1()
	{
		
	} 
}
bool cmp (const string& t1,const string &t2)
{
	return t1<t2;
}
int main ()
{
	cout<<ql32401::max({"abc","asdfs","zs","asda"},cmp)<<endl;
	cout<<ql32402::max<string>({"abc","asdfs","zs","asda"},cmp)<<endl;
	cout<<ql32402::max<string>({"abc","asdfs","zs","asda"},&cmp)<<endl;//二三种做法等同,编译器自动将函数名转化成函数指针 
	cout<<ql32403::max<string>({"abc","asdfs","zs","asda"},cmp)<<endl;
	return 0;
}
