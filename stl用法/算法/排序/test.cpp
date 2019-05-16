#include<iostream>
#include<functional>
#include<algorithm>
#include<random>
#define _g cout<<'\n';
#define fe(x,f) for_each(x.begin(),x.end(),f)
using namespace std;
using namespace std::placeholders;

using v=vector<int>;
auto f=[](const int i){
	cout<<i<<' ';
};
		
template<class T>
void random (T &va,size_t si,int mod=100)
{
	//size_t seed=chrono::system_clock::now().time_since_epoch().count();
//	cout<<"seed:"<<seed<<endl;
    static random_device seed;
	mt19937 g(seed());
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
template<class T>
class fun :public unary_function<T,T>
{
    public:
    bool operator () (const T &i,const T &j)
    {
        return i<j;
    }
};
//sotr
namespace t0
{
    //形式1
    void test0()
    {
        v vi;
        random(vi,10);
        fe(vi,f);
        _g
        sort(vi.begin(),vi.end());
        fe(vi,f);
        _g
    }
    //形式2
    void test1 ()
    {
        v vi;
        random(vi,10);
        fe(vi,f);
        _g
        partial_sort(vi.begin(),vi.begin()+6,vi.end());
        fe(vi,f);
        _g
    }
    //binary_search
    /*
    在已经排好序的容器中,找到true,未找到false
    */
   void test2 ()
   {
       v vi;
       random (vi,15,10);
       fe(vi,f);
       sort(vi.begin(),vi.end());
       _g
       cout<<boolalpha<<binary_search(vi.begin(),vi.end(),random(10));
       _g
   }
   //merge
   /*
   对于排好序的两个序列,合并到一个
   */
  void test3 ()
  {
      v vi,vj;
      random(vi,10);
      random(vj,7);
      sort(vi.begin(),vi.end());
      sort(vj.begin(),vj.end());
      fe(vi,f);
      _g
      fe(vj,f);
      _g
      v res(vi.size()+vj.size());
      merge(vi.begin(),vi.end(),vj.begin(),vj.end(),res.begin());
     fe(res,f);
      _g
    
  }
    //includes
    /*
    对于排好序的元素,检查[first1,last1)中是否包含[first2,last2)
    */
   void test4 ()
   {
       v vi,vj{1,10};
       random(vi,10,15);
       
       sort(vi.begin(),vi.end());
       sort(vj.begin(),vj.end());
       fe(vi,f);
       _g
       fe(vj,f);
        _g
		cout<<boolalpha<<includes(vi.begin(),vi.end(),vj.begin(),vj.end())<<endl;
   }

}
//基于堆的算法
namespace t1
{
	//1.make_heap
	/*将区间[first,last)转换成大根堆*/
	void test ()
	{
		v vi;
		random(vi,10);
		fe(vi,f);
		_g
		//大根堆
		make_heap(vi.begin(),vi.end());
		fe(vi,f);
		_g
		//小根堆
		make_heap(vi.begin(),vi.end(),[](const int i,const int j){return i>j;});
		fe(vi,f);
		_g
		vi.push_back(random());
		push_heap(vi.begin(),vi.end(),[](const int i,const int j){return i>j;});
		pop_heap(vi.begin(),vi.end(),[](const int i,const int j){return i>j;});
		//push_heap(vi.begin(),vi.end());
		sort_heap(vi.begin(),vi.end(),[](const int i,const int j){return i>j;});
		fe(vi,f);
		_g
	}
}
int main ()
{

    t0::test0();
    t0::test1();
    t0::test2();
    t0::test3();
	t0::test4();
	t1::test();
    return 0;
    
}