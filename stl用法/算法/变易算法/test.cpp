#include<iostream>
#include<chrono>
#include<iterator>
#include<random>
#include<functional>
#include<algorithm>
#define _g cout<<'\n';
#define fe(x,f) for_each(x.begin(),x.end(),f)
using namespace std;
using namespace std::placeholders;

using v=vector<int>;
auto f=[](const int i){
	cout<<i<<' ';
};
		
template<class T>
void random (T &va,size_t si,size_t mod=100)
{
	size_t seed=chrono::system_clock::now().time_since_epoch().count();
//	cout<<"seed:"<<seed<<endl;
	static mt19937 g(seed);
	typedef typename iterator_traits<typename T::iterator>::value_type Val;
	for(int i=0;i<si;++i)
	{
		Val t=g()%mod;
		auto it=va.end();
		va.insert(it,t);	
	} 
}
int random(int mod=100)
{
	size_t seed=chrono::system_clock::now().time_since_epoch().count();
	static mt19937 g(seed);
	return static_cast<int>(g())%mod; 
}
//copy
namespace t1
{
	//形式1
	/*
	template<class Init,class Init2>
	inline Init2 copy (Init _first,Init _last, Init2 _dest)
	*/ 
	void test1 ()
	{
		vector<int> vi{1,2,3,4,5,5,2};
		cout<<vi.size()<<vi.capacity()<<endl; 
		vector<int> vi1(vi.size());
		cout<<vi1.size()<<' '<<vi1.capacity()<<endl; 
		auto it=copy(vi.begin(),vi.end(),vi1.begin());
		it=vi1.begin();
		while(it!=vi1.end())
		{
			cout<<*it<<' ';
			++it;
		}
		cout<<endl;
		copy(vi1.begin()+2,vi1.end(),vi1.begin());
		vi1.push_back(99);
		vi1.resize(5);
			cout<<vi1.size()<<' '<<vi1.capacity()<<endl;
		//	vi1.clear(); 
		vi1.shrink_to_fit();
		cout<<vi1.size()<<' '<<vi1.capacity()<<endl; 
	}
	//形式二
	/*
	template< class InputIt, class OutputIt, class UnaryPredicate >
	OutputIt copy_if( InputIt first, InputIt last,
                  OutputIt d_first,
                  UnaryPredicate pred );
	*/ 
	void test2 ()
	{
		vector<int> vi{1,2,3,4,5,5,2};
		vector<int> vj(vi.size());
		auto fun=[](int i)->bool
		{
			function<bool(int)> f=bind(less<int>(),3,_1);
			return f(i);
		};
		copy_if(vi.begin(),vi.end(),vj.begin(),fun);	
		for(auto i:vj)
		{
			cout<<i<<' ';	
		}
		cout<<endl;
		auto si=count_if(vj.begin(),vj.end(),bind(not_equal_to<int>(),0,_1));
		vj.resize(si);
		vj.shrink_to_fit();
		cout<<vj.size()<<' '<<vj.capacity()<<endl;	
	} 
	//形式3
	/*
	template<class T,class U>
	U copy_backward (T first,T second,u d_last)
	{
		while(first!-last)
		{
			*(--d_last)=*(--last)
		}
		return d_last;
	}
	*/ 
	void test3 ()
	{
		vector<int> vi;
		for(int i=0;i<10;i++)
		{
			vi.emplace_back(i);
		}
		vector<int> vj(15);
		copy_backward(vi.begin(),vi.end(),vj.end()-2);
		for_each(vj.begin(),vj.end(),[](const int i){cout<<i<<' ';});
		cout<<endl; 
	}
	//形式4
	/*
	copy_n
	template<class in,class diff,class ou> inline
	ou copy_n (in f,diff n,ou l);  
	*/ 
	void test4 ()
	{
		string tmp="05425353";
		string temp="y";
		copy_n(tmp.begin(),5,back_inserter(temp));
		cout<<temp<<endl;
	}
}
namespace t2
{
	//swap
	//形式1
	/* 
	template< class T >
		inline void swap( T& a, T& b ); 
	*/

		
	void test ()
	{
		vector<int> vi,vj;
		random(vi,10);
		random(vj,16);
	
		int *p1=&vi[0];
		int *p2=&vj[0];
		for_each(vi.begin(),vi.end(),f);
		cout<<endl;
		for_each(vj.begin(),vj.end(),f);
		cout<<endl;
		//clock_t timestart =clock();
		swap(vi,vj);
		//cout<<"move construct mili_second= "<<(clock()-timestart)<<endl;
		*p1=10000;
		*p2=20000;
		for_each(vi.begin(),vi.end(),f);
		cout<<endl;
		for_each(vj.begin(),vj.end(),f);
		cout<<endl;
	}
	//形式2
	//swap_ranges
	/*
	template< class ForwardIt1, class ForwardIt2 >
		ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1,
                        ForwardIt2 first2 );
	*/ 
	void test1 ()
	{
		v vi,vj;
		random(vi,10);
		random(vj,7);
		for_each(vj.begin(),vj.end(),f);
		_g
		for_each(vi.begin(),vi.end(),f);
		_g
		swap_ranges(vj.begin(),vj.end(),vi.begin());
		for_each(vj.begin(),vj.end(),f);
		_g
		for_each(vi.begin(),vi.end(),f);
		_g
	}
}
//transform
namespace t3
{
	//形式1
	//template<class in,class out,class f>
	/*
		inline transform (in f,in l,out d,f fun);
		对于区间[f,l)中的每个元素应用fun(*f),复制到d区间中; 
	*/	
	void test0 ()
	{
		v vi;
		random(vi,10);
		for_each(vi.begin(),vi.end(),f);
		_g
		transform(vi.begin(),vi.end(),vi.begin(),negate<int>());
		for_each(vi.begin(),vi.end(),f);
		_g	
	}
	//形式2
	//template<class in1,class in2,class out,class f>
	/*
		inline transform (in f,in l,in2 f2,out d,f fun);
		对于区间[f,l)和区间[f2.f2+i)中的每个元素应用fun(*f,*f2),复制到d区间中; 
	*/
	void test1 ()
	{
		v vi,vj;
		random(vi,10);
		random(vj,10);
		for_each(vi.begin(),vi.end(),f);
		_g
		for_each(vj.begin(),vj.end(),f);
		_g
		transform(vi.begin(),vi.end(),vj.begin(),vj.begin(),plus<int>());
		for_each(vj.begin(),vj.end(),f);
		_g	
	}	
} 
//replace
namespace t4
{
	//形式1
	/*
	template<class t,class u>
	inline void replace (t f,t l,u o,o n)
	对于区间[f,t),如果o==n,则替换 
	*/ 
	void test0 ()
	{
		v vi;
		random(vi,10,6);
		fe(vi,f);
		_g
		replace (vi.begin(),vi.end(),5,random(6));
		fe(vi,f);
		_g
	 } 
	//形式2
	/*
	template<class t,class u,class p>
	inline void replace_if (t f,t l,p f,o n)
	对于区间[f,t),如果f(*f)==1,则替换 
	*/ 
	void test1 ()
	{
		v vi;
		random(vi,10,50);
		fe(vi,f);
		_g
		replace_if (vi.begin(),vi.end(),bind(less<int>(),_1,30),random(6));
		fe(vi,f);
		_g
	 }
	//形式3
	/*
	template<class t,class u,class d>
	inline void replace_copy (t f,t l,,d _d,u o,u n)
	对于区间[f,t),如果u==o,则copy到_d处 
	*/ 
	void test2 ()
	{
		v vi;
		random(vi,10,10);
		v vj(vi.size()); 
		fe(vi,f);
		_g
		replace_copy (vi.begin(),vi.end(),vj.begin(),5,random(10));
		fe(vj,f);
		_g
	 } 
}

int main ()
{
	t1::test1();
	t1::test2();
	t1::test3();
	t1::test4();
	t2::test ();
	t2::test1();
	t3::test0(); 
	t3::test1();
	t4::test0();
	t4::test1();
	t4::test2();
	return 0;
}
