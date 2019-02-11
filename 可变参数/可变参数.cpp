#include<iostream>
#include<cstdarg> 
#include<initializer_list>
using namespace std;
namespace ql01
{
int sum (int count,...)
{
	va_list ap;  //声明一个va_list变量
	va_start(ap, count);  //第二个参数表示形参的个数
 
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(ap, int);   //第二个参数表示形参类型
	}
	
	va_end(ap);  //用于清理
 
	return sum;

}

}
namespace ql02
{
	
int sum(initializer_list<int> il) 
{
   
	int sum = 0;
 
	for (auto ptr = il.begin(); ptr != il.end(); ptr++)  //类似于容器的操作
	{
		sum += *ptr;
	}
	return sum;
}
}
namespace ql03
{
	int sum ()//递归终止函数,必须有,负责编译不过 
	{
		return 0;
	}
	template<typename T,typename... Ts>
	int sum ( const T& f,const Ts&... args)//分成一个和一包,递归调用 
	{
//		cout<<sizeof...(args)<<endl; 
//		if(sizeof...(args)==0)
//		return 0;
		int s=f+sum(args...);
		return s;
	}
	
}  
int main ()
{
	int s1=ql01::sum(3,1,2,3);
	int s2=ql02::sum({1,2,3});
	int s3=ql03::sum(1,2,3);
	cout<<"s1="<<s1<<'\n'<<"s2="<<s2<<'\n'<<"s3="<<s3<<endl;
	return 0;
}
