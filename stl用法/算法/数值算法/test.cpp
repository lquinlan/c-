#include<iostream>
#include<functional>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<iterator>
#define _g cout<<'\n';
#define fe(x,f) for_each(x.begin(),x.end(),f)

using namespace std;
using namespace std::placeholders;
using v=vector<int>;

auto f=[](const int& i){
	cout<<i<<' ';
};
		
template<class T>
void random (T &va,size_t si,int mod=100)
{
	size_t seed=chrono::system_clock::now().time_since_epoch().count();
//	cout<<"seed:"<<seed<<endl;
    //static random_device seed;
	mt19937 g(seed);
	typedef typename iterator_traits<typename T::iterator>::value_type Val;
	for(int i=0;i<si;++i)
	{
		Val t= static_cast<int>(g())%mod;
		auto it=va.end();
		va.insert(it,t);	
	} 
}
int random(int mod=100)
{
	//size_t seed=chrono::system_clock::now().time_since_epoch().count();
    static random_device seed;
	static mt19937 g(seed());
	return static_cast<int>(g())%mod; 
}

//accumulate
namespace t0
{
    //–Œ Ω1
    /*
        
    */
}