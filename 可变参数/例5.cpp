#include<iostream>
#include<utility>
#include<tuple>
using namespace std;
template<int ind,int max,typename... args>
struct print_tuple{
	static void print (ostream &os,const tuple<args...>& t)
	{
		os<<get<ind>(t)<<(ind+1==max?"":",");
		print_tuple<ind+1,max,args...>::print(os,t);
	}
};
template<int max,typename... args>
struct print_tuple<max,max,args...>{
	static void print (ostream &os,const tuple<args...>& t)
	{
	}
};
template<typename... args>
ostream& operator<< (ostream &os,const tuple<args...>& t)
{
	os<<"[";
	print_tuple<0,sizeof...(args),args...>::print(os,t);
	os<<"]";
	return os;
}
int main ()
{
	cout<<make_tuple(34,54,234,234.1231,"ghj¹ú·þ",'s')<<endl;
	return 0; 
} 
