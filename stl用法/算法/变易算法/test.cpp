#include<iostream>
#include<chrono>
#include<iterator>
#include<random>
#include<functional>
using namespace std;
using namespace std::placeholders;

template<class T>
void random (T &va,size_t si,size_t mod=10)
{
	size_t seed=chrono::system_clock::now().time_since_epoch().count();
	mt19937 g(seed);
	typedef typename iterator_traits<typename T::iterator>::value_type Val;
	for(int i=0;i<si;++i)
	{
		Val t=g()%mod;
		auto it=va.end();
		va.insert(it,t);	
	} 
}
int random(int mod=10)
{
	size_t seed=chrono::system_clock::now().time_since_epoch().count();
	mt19937 g(seed);
	return (int)g()%mod; 
}
//copy
namespace t1
{
	//ÐÎÊ½1
	/*
	template<class Init,class Init2>
	inline Init2 copy (Init _first,Init _last, Init2 _dest)
	*/ 
	void test1 ()
	{
		vector<int> vi{1,2,3,4,5,5,2};
		vector<int> vi1(vi.size());
		auto it=copy(vi.begin(),vi.end(),vi1.begin());
		it=vi1.begin();
		while(it!=vi1.end())
		{
			cout<<*it<<' ';
			++it;
		}
		cout<<endl;
	}
}
int main ()
{
	t1::test1();
	return 0;
}
