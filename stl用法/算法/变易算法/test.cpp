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
//fill
namespace t5
{
	//形式1
	/*
	template<class f ,class t> inline
	void fill (f f1,f f2, const t &y);
	将区间[f1,f2)的区间全部复制上y
	*/
	void test0 ()
	{
		v vi;
		random(vi,10);
		fill(vi.begin(),vi.end(),777);
		fe(vi,f);
		_g
	}

}
//generate
namespace t6
{
	//形式1
	/*
	template<class f,class t> inline
	void generate(f f1,f l ,t fun);
	对于区间[f1,l)复上fun()产生的值
	*/
	void test0 ()
	{
		v vi(10);
		//因为randon有重载,所有换个名字
		int(*rdm)(int)=random;
		generate(vi.begin(),vi.end(),bind(rdm,static_cast<int>(10)));
		fe(vi,f);
		_g
	}
} // namespace t6
//remove
namespace t7
{
	//形式1
	/*
		template<class in,class t>
		inline in remove (in first,in out,const T& v);
	*/
	void test0 ()
	{
		v vi{0,1,4,45,2,4,4,3,4,100,0};
		fe(vi,f);
		_g
		cout<<vi.size()<<endl;
		auto iter=remove(vi.begin(),vi.end(),4);
		for_each(vi.begin(),iter,f);
		_g
		for_each(iter,vi.end(),f);
		_g
		cout<<vi.size()<<endl;
		fe(vi,f);
		_g
		vi.resize(iter-vi.begin());
		fe(vi,f);
		_g
		//实现
		/*
				template <class _InputIter, class _OutputIter, class _Tp>
		_OutputIter remove_copy(_InputIter __first, _InputIter __last,
								_OutputIter __result, const _Tp& __value) {
		for ( ; __first != __last; ++__first)
			if (*__first != __value) {
			*__result = *__first;
			++__result;
			}
		return __result;
		}
		template <class _ForwardIter, class _Tp>
		_ForwardIter remove(_ForwardIter __first, _ForwardIter __last,
							const _Tp& __value) {
		__first = find(__first, __last, __value);
		_ForwardIter __i = __first;
		return __first == __last ? __first 
								: remove_copy(++__i, __last, __first, __value);
		}
		*/
	}
	//形式2
	/*
	template<class in,class pre> inline
	in remove_if(in first,in last,pre _pre);
	*/
	void test1 ()
	{
		v vi{0,1,4,45,2,4,4,3,4,100,0};
		fe(vi,f);
		_g
		cout<<vi.size()<<endl;
		auto iter=remove_if(vi.begin(),vi.end(),bind(less<int>(),_1,5));
		for_each(vi.begin(),iter,f);
		_g
		for_each(iter,vi.end(),f);
		_g
		cout<<vi.size()<<endl;
		fe(vi,f);
		_g
		vi.resize(iter-vi.begin());
		fe(vi,f);
		_g
	}

} // namespace t7
//unique
namespace t8
{
	//形式1
	/*
	template<clss in> inline
	in unique(in first,in last);
	去除[first,last)区间中重复的元素
	*/
	void test0 ()
	{
		v vi;
		random(vi,20,10);
		fe(vi,f);
		_g
		auto iter=unique(vi.begin(),vi.end());
		fe(vi,f);
		//unique是消除区间内连续的重复元素;
		_g
		sort(vi.begin(),vi.end());
		iter=unique(vi.begin(),vi.end());
		fe(vi,f);
		_g
		vi.erase(iter,vi.end());
		fe(vi,f);
		_g
	}
}
//reverse
namespace t9
{
	//形式1
	/*
	template<class in>
	inline void reverse (in first,in last);
	对于区间[first,last)交换first+i,last-1-i),0<=i<=(last-first)/2
	*/
	void test0 ()
	{
		cout<<"t9::test0"<<endl;
		v vi;
		random(vi,10);
		fe(vi,f);
		_g
		reverse(vi.begin(),vi.end());
		fe(vi,f);
		_g;
	}


}
//rotate
namespace t10
{
	//自己实现版本
	template<class T>
	void swap (T &a,T &b)
	{
		T tmp;
		tmp=a;
		a=b;
		b=tmp;
	}
	template<class iter>
	inline iter rotate (iter first,iter mid,iter last)
	{
		if(first==mid)
		{
			return last;
		}
		if(last==mid)
		{
			return first;
		}
		iter first2=mid;
		while(first2!=last)
		{
			swap(*first++,*first2++);
			if(first==mid)
				mid=first2;
		}
		iter new_mid=first;
		first2=mid;
		while(first2!=last)
		{
			swap(*first++,*first2++);
			if(first==mid)
				mid=first2;
			else if(first2==last)
			{
				first2=mid;
			}
		}
		return new_mid;
	}
	void test0 ()
	{
		v vi;
		random(vi,10);
		fe(vi,f);
		_g
		t10::rotate(vi.begin(),vi.begin()+4,vi.end());
		fe(vi,f);
		_g
	}
	void test1 ()
	{
		v vi;
		random(vi,10);
		fe(vi,f);
		_g
		std::rotate(vi.begin(),vi.begin()+4,vi.end());
		fe(vi,f);
		_g
	}
}
//random_shuffle
namespace t11
{
	//形式1
	/*
	template<class T>
	inline void random_shuffle(T fi,T la);
	返回N!的一种形式
	*/
	void test0 ()
	{
		v vi;
		for(int i=0;i<10;++i)
			vi.emplace_back(i);
		fe(vi,f);
		_g
		random_shuffle(vi.begin(),vi.end());
		fe(vi,f);
		_g
	}
} // namespace t11
//partition
#include<iterator>
namespace t12
{
	void test0 ()
	{
		v vi;
		random(vi,10);
		copy(vi.begin(),vi.end(),ostream_iterator<int>(cout," "));
		_g
		auto it=std::partition(vi.begin(),vi.end(),bind(less<int>(),_1,40));
		copy(vi.begin(),it,ostream_iterator<int>(cout," "));
		cout<<"*"<<' ';
		copy(it,vi.end(),ostream_iterator<int>(cout," "));
		_g
		fe(vi,f);
		_g
	}
	//可能实现
	template<class iter,class pre> inline iter
	partition (iter first,iter last,pre p)
	{
		auto _first=find_if_not(first,last,p);
		if(_first==last)
		{
			return _first;
		}
		for(iter i=next(_first);i!=last;++i)
		{
			if(p(*i))
			{
				swap(*i,*_first);
				++_first;
			}
		}
		return _first;
	}
	void test1 ()
	{
		v vi;
		random(vi,10);
		fe(vi,f);
		_g
		auto it=t12::partition(vi.begin(),vi.end(),bind(less<int>(),_1,40));
		cout<<*it<<endl;
		fe(vi,f);
		_g
	}
	//借由partition实现的quicksort
	template<class iter> inline void 
	quicksort (iter first,iter last)
	{
		if(first==last) return;
		auto p=*next(first,distance(first,last)/2);
		auto mid1=t12::partition(first,last,[p](const auto &it){return it<p;});
		auto mid2=t12::partition(first,last,[p](const typename iterator_traits<iter>::value_type & it){return it<=p;});
		quicksort(first,mid1);
		quicksort(mid2,last);
	}
	void test2 ()
	{
		v vi;
		random(vi,10);
		fe(vi,f);
		_g
		t12::quicksort(vi.begin(),vi.end());
		fe(vi,f);
		_g
	}
} // namespace t12

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
	t5::test0();
	t6::test0();
	t7::test0();
	t7::test1();
	t8::test0();
	t9::test0();
	t10::test0();
	t10::test1();
	t11::test0();
	t12::test0();
	t12::test1();
	t12::test2();
	cout<<__cplusplus<<endl;
	return 0;
}
