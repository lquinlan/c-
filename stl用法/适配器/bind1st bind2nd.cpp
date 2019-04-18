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
	
*/
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std;
int main ()
{
	vector<int> vi{0,0,0,0,0,0,0,0,12,232};
	auto it=find_if(vi.begin(),vi.end(),bind1st(not_equal_to<int>(),0));
	auto it1=find_if(vi.begin(),vi.end(),bind2nd(greater<int>(),0));
	cout<<*it<<endl; 
	cout<<*it1<<endl;
	return 0;
}

