#include<bits/stdc++.h>
namespace ql211
{
	
	void print ()//终止函数 
	{
		
	}
	template<typename T,typename... Ts>
	void print(const T& first,const Ts&... args)//特化 ,一个和一包 
	{
		std::cout<<first<<std::endl;
		print(args...); //剩下的一包继续被分解位,一个和一包递归下去; 
	}
	template<typename... Ts>
	void print(const Ts&... args)//泛化 
	{
		/*...*/
	} 
} 
