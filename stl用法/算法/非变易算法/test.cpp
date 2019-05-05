#include<iostream>
#include<algorithm>
#include<functional>
#include<chrono>
#include<random>
#include<iterator>
using namespace std;
using namespace std::placeholders;
template<class T>
void random (T &va,size_t si,int mod=10)
{
	typedef typename iterator_traits<typename T::iterator>::value_type Val;
	size_t seed=chrono::system_clock::now().time_since_epoch().count();
	mt19937 g(seed);
	for(size_t i=0;i<si;++i)
	{
		auto it=va.end();
		Val v=g();
		va.insert(it,v%mod);
	}
}
//for_each
namespace t1
{
	//形式
	/*
	template<class Init,class fn1>
	inline for_each (Init _first,Init _last,fn1 _func)  
	*/ 
	void test ()
	{
		vector<int> va;
		random(va,15);
		for_each(va.begin(),va.end(),
		bind([](int &m,int &n)
		{
			if(less<int>()(m,n))
			{
				cout<<n<<' ';	
			}	
		},0,_1
		) );
		cout<<endl;
	}
}
//find形式 
namespace t2
{
	//形式1
	/*
		template<class Init,class Ty>
		inline Init find (Init _first,Init _last,const Ty& _va)
	*/ 
	void test1 ()
	{
		vector<int> va{1,23,34,435,242,25,24,453,-1,-324,24,-324,-3235};
		int t=-324;
		vector<int>::iterator it=find(va.begin(),va.end(),t);
		cout<<*it<<endl;
	}
	//形式2
	/*
	template<class Init,class _pr>
	inline Init find_if(Init _first,Init _last,_pr _pred) 
	*/ 
	void test2 ()
	{
		vector<int> va{1,23,34,435,242,25,24,24,453,-1,-324,24,-324,-3235};
		vector<int>::iterator it=find_if(va.begin(),va.end(),bind(greater<int>(),0,_1));
		cout<<*it<<endl;
	}
	//adjacent_find()形式1 
	/*
	作用,如果*it==*(it+1),返回it 
	*/
	void test3 ()
	{
		vector<int> va{1,23,34,435,242,25,24,24,453,-1,-324,24,-324,-3235};
		vector<int>::iterator it=adjacent_find(va.begin(),va.end());
		cout<<va[it-va.begin()]<<' '<<va[it-va.begin()+1]<<endl; 
	}
	//adjacent_find()形式2
	/*
	template<class Init,class _pr>
	inline Init adjacent_find(Init _first,Init _last,_pr pred) 
	对于 it 属于 [_first,_last),如果pred(*it,*(it+1))==true,则返回
	it,没有返回_last 
	*/ 
	void test4 ()
	{
		vector<int> va{1,23,34,435,242,25,24,24,453,-1,-324,24,-324,-3235};
		vector<int>::iterator it=adjacent_find(va.begin(),va.end(),equal_to<int>());
		cout<<va[it-va.begin()]<<' '<<va[it-va.begin()+1]<<endl; 
	}
	//find_first_of(1)
	/*
	形式template<class Init1,class Init2>
	Init1 find_first_of(Init1 _first1,Init1 _last1,Init2 _first2,Init2 _last)
	 
	*/
	void test5 ()
	{
		vector<int> va{1,23,34,435,242,25,24,24,453,-1,-324,24,-324,-3235};
		vector<int> vb{5,24,1,24,453,-1,-324,24,-324,-3235};
		vector<int>::iterator it=find_first_of(va.begin(),va.end(),vb.begin(),vb.end());
		cout<<va[it-va.begin()]<<' '<<endl; 
	}
	//find_first_of(2)
	/*
	形式template<class Init1,class Init2,class _pr>
	Init1 find_first_of(Init1 _first1,Init1 _last1,Init2 _first2,Init2 _last,_pr pred)
	 
	*/
	void test6 ()
	{
		vector<int> va{1,23,34,435,242,25,24,24,453,-1,-324,24,-324,-3235};
		vector<int> vb{5,24,1,24,453,-1,-324,24,-324,-3235};
		vector<int>::iterator it=find_first_of(va.begin(),va.end(),vb.begin(),vb.end(),equal_to<int>());
		cout<<va[it-va.begin()]<<' '<<endl; 
	}
	
}
//count
namespace t3
{
	//形式1-count
	/*
	template<class Init,class T>
	inline typename iterator_traits<Init>::difference_type
	count (Init _first,Init _last,const T& va)
	返回区间*it==va的个数 
	*/ 
	void test1 ()
	{
		vector<int> va;
		random(va,100,30);
		size_t cnt=count(va.begin(),va.end(),6);
		cout<<"count:"<<cnt<<endl;
	}
	//形式2:count_if
	/*
	template<class Init ,class _pr>
	inline typename iterator_traits<Init>::difference_type
	count_if(Init _first,Init _last,_pr pred); 
	*/ 
	void test2 ()
	{
		vector<int> va;
		random(va,100,40);
		size_t cnt=count_if(va.begin(),va.end(),[](int &m){return m<20;});
		cout<<"cnt:"<<cnt<<endl;	
	} 
}
//mismatch
namespace t4
{
	//形式1 注:在新版本中,第二个区间,只需要,传区间的开始,不需要传区间的结束,没有必要
	/*
	template<class Init1,class Init2>
	inline pair<Init1,Init2> mismatch(Init1 _first1,Init1 _last1,Init2 _first2) 
	*/ 
	void test1()
	{
		vector<int> va1{1,2,3,4,5,6,100,32,42};
		vector<int> va2{1,2,3,4,5,324,324,32};
		typedef vector<int>::iterator iter;
		pair<iter,iter> p=mismatch(va1.begin(),va1.end(),va2.begin());
		cout<<*get<0>(p)<<' '<<*get<1>(p)<<endl; 
	}
	//形式2 
	/*
	template<class Init1,class Init2,class _pr>
	inline pair<Init1,Init2> mismatch(Init1 _first1,Init1 _last1,Init2 _first2,Init _last ,_pr pred); 
	*/ 
	void test2()
	{
		vector<int> va1{1,2,3,4,5,6,100,32,42};
		vector<int> va2{1,2,3,4,5,324,324,32};
		typedef vector<int>::iterator iter;
		pair<iter,iter> p=mismatch(va1.begin(),va1.end(),va2.begin(),not_equal_to<int>());
		cout<<*get<0>(p)<<' '<<*get<1>(p)<<endl; 
	}
}
//equal
namespace t5
{
	//形式1 
	/*
	template<class Init1,class Init2>
	inline bool mismatch(Init1 _first1,Init1 _last1,Init2 _first2) 
	*/ 
	void test1()
	{
		vector<int> va1{1,2,3,4,5,6,};
		vector<int> va2{1,2,3,4,5,6};
		bool ans=equal(va1.begin(),va1.end(),va2.begin());
		cout<<boolalpha<<ans<<endl;
	}
	//形式2
	/*
	template<class Init1,class Init2,class _pr>
	inline bool mismatch(Init1 _first1,Init1 _last1,Init2 _first2,_pr pred) 
	*/ 
	void test2()
	{
		vector<int> va1{1,2,3,4,5,6,};
		vector<int> va2{2,3,4,5,6,7};
		bool ans=equal(va1.begin(),va1.end(),va2.begin(),less<int>());
		cout<<boolalpha<<ans<<endl;
	}		
}
//search
namespace t6
{
	//形式1 
	/*
	template<class Init1,class Init2>
	inline bool search(Init1 _first1,Init1 _last1,Init2 _first2,Init2 _last2) 
	*/ 
	void test1()
	{
		vector<int> va1{1,2,3,4,5,6,};
		vector<int> va2{2,3,4,5};
		auto it=search(va1.begin(),va1.end(),va2.begin(),va2.end());
		cout<<*it<<' '<<*(it+va2.size()-1)<<endl;
	}	
	//形式2 
	/*
	template<class Init1,class Init2,class _pr>
	inline bool search(Init1 _first1,Init1 _last1,Init2 _first2,Init2 _last2,_pr pred) 
	*/ 
	void test2()
	{
		vector<int> va1{1,2,3,4,5,6,};
		vector<int> va2{2,3,4,5};
		auto it=search(va1.begin(),va1.end(),va2.begin(),va2.end(),less<int>());
		cout<<*it<<' '<<*(it+va2.size()-1)<<endl;
	}	
}
int main ()
{
	t1::test();
	t2::test1();
	t2::test2();
	t2::test3();
	t2::test4(); 
	t2::test5();
	t2::test6();
	t3::test1();
	t3::test2();
	t4::test1();
	t4::test2();
	t5::test1();
	t5::test2();
	t6::test1();
	t6::test2();
	return 0;
}
