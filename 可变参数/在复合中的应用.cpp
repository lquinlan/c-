#include<iostream>
#include<string>
using namespace std;
template<typename... va>
class tup;
template<> class tup<>{};
template<typename Head,typename... tail>
class tup<Head,tail...>
{
	using com=tup<tail...>;
	protected:
	Head M_head;
	com M_tail;
	public:
	tup(){}
	tup (Head v,tail... vi):
		M_tail(vi...),M_head(v){}
	Head head (){ return M_head;}
	com& rtail ()
	{
		return M_tail;
	}
};
int main ()
{
	tup<int,int,string,double> m(1,678,"43",5.6);
	cout<<m.head()<<endl;
	cout<<m.rtail().head()<<endl;
	cout<<m.rtail().rtail().head()<<endl;
	return 0;
}
