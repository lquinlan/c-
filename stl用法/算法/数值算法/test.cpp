#include<iostream>
#include<functional>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<iterator>
#include<chrono> 
#include<random>
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
	static mt19937 g(seed);
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
    //形式1
    /*
        template<class iter,class init> inline T accumulate (iter first,iter last,init v);
    */
   void test0 ()
   {
	   v vi(100);
	   iota(vi.begin(),vi.end(),1);//累增
	   auto ans=accumulate(vi.begin(),vi.end(),0);
	   cout<<"ans="<<ans<<endl;
   }
	//形式2
    /*
        template<class iter,class init,class fun> inline T accumulate (iter first,iter last,init v,fun op);
		it=op(*it,res);
    */
   void test1 ()
   {
	   v vi(10);
	   iota(vi.begin(),vi.end(),1);//累增
	   auto ans=accumulate(vi.begin(),vi.end(),1,multiplies{});
	   cout<<"ans="<<ans<<endl;
   }
}
//inner_product
namespace t1
{
	//形式1
	/*
	template<class it1,class it2,class init> inline 
	init inner_product (it1 first1,it1 last1,it2 first2,init v);
	res=res+*it1*(f2+(it-f1))
	*/
	void test0 ()
	{
		v vi,vj;
		random(vi,10);
		random(vj,10);
		fe(vi,f);
		_g
		fe(vj,f);
		_g
		auto ans=inner_product(vi.begin(),vi.end(),vj.begin(),0);
		cout<<"ans="<<ans<<endl;
	}
	//形式2
	/*
	template<class it1,class it2,class init,class fun1,class fun2> inline 
	init inner_product (it1 first1,it1 last1,it2 first2,init v,fun1 op1,fun2 op2);
	res=op1(res,op2(it1,(f2+(it-f1)))
	*/
	void test1 ()
	{
		v vi,vj;
		random(vi,3);
		random(vj,3);
		fe(vi,f);
		_g
		fe(vj,f);
		_g
		auto ans=inner_product(vi.begin(),vi.end(),vj.begin(),0,plus{},multiplies{});
		cout<<"ans="<<ans<<endl;
	}
}

//partial_sum
namespace t2
{
	//形式1
	/*
	template<class fir,class dis>
	inline dis partial_sum (fir f1,fir last,dis d1);
	*/
	void test0 ()
	{
		v vi;
		random(vi,6);
		fe(vi,f);
		_g
		partial_sum(vi.begin(),vi.end(),vi.begin());
		fe(vi,f);
		_g
	}
	//形式1
	/*
	template<class fir,class dis,class op>
	inline dis partial_sum (fir f1,fir last,dis d1,op fun);
	*/
	void test1 ()
	{
		v vi;
		random(vi,6);
		fe(vi,f);
		_g
		partial_sum(vi.begin(),vi.end(),vi.begin(),minus{});
		fe(vi,f);
		_g
	}
}
//adjacent_difference
namespace t3
{
	//形式1
	/*
	template<class init,class out> inline
	out adjacent_difference (init first,init lat,out dis);
	res=*first,对于it [first+1,last-1],(*res+first+i)=*it-*(it-1)
	*/
	void test0 ()
	{
		v vi;
		random(vi,6);
		fe(vi,f);
		_g
		adjacent_difference(vi.begin(),vi.end(),vi.begin());
		fe(vi,f);
		_g
	}
		//形式2
	/*
	template<class init,class out,class op> inline
	out adjacent_difference (init first,init lat,out dis,op fun);
	*/
	void test1 ()
	{
		v vi;
		random(vi,6);
		fe(vi,f);
		_g
		adjacent_difference(vi.begin(),vi.end(),vi.begin(),plus{});
		fe(vi,f);
		_g
	}
}
int main ()
{
	t0::test0();
	t0::test1();
	t1::test0();
	t1::test1();
	t2::test0();
	t2::test1();
	t3::test0();
	t3::test1();
	return 0;
}
