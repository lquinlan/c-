#include<iostream>
using namespace std;
void printf (const char *s)
{
	while(*s)
	{
		if(*s=='%'&&*(++s)!='%')
		{
			throw "invalid format string: missing arguments";
		}
		cout<<*s++;
	}
} 
template<typename T,typename... types>
void printf (const char *s,T v,const types&... args)
{
	while(*s)
	{
		if(*s=='%'&&*(++s)!='%')
		{
			cout<<v;
			printf(++s,args...);
			return;
		} 
		cout<<*s++;
	}
	throw "extra arguments provided to printf";
}
int main ()
{
	printf("%d %s %f %d\n",23,"gf",6.8,34);
	return 0;
}
