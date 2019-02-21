#include<iostream>
using namespace std;
int maxnum(int x)
{
	return x;
} 
template<typename... Args>
int maxnum(int x,const Args&... arg)
{
	return std::max(x,maxnum(arg...));
}
int main ()
{
	std::cout<<maxnum(1,2,3,4,5,6)<<std::endl;
	return 0;
}
