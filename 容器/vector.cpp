#include<vector>
#include<iostream>
using namespace std;

//经验
namespace ql01
{
	void test()
	{
			vector<int> vi{0,1,3,3,4,5,6,7,8,9};
		//删除vector中的奇数,这是错误代码,原因是,在erase中,删除元素,会导致其他的元素前移,此时,不应该移动 
	//	for(int i=0;i<vi.size();i++)
	//	{
	//		if(vi[i]&1)
	//		{
	//			vi.erase(vi.begin()+i);
	//		}
	//	}
	//正确写法1:
	//	for(int i=0;i<vi.size();++i)
	//	{
	//		if(vi[i]&1)
	//		{
	//			vi.erase(vi.begin()+i);
	//			--i;
	//		}
	//	} 
	//正确写法2:
		vector<int>::iterator it=vi.begin();
		while(it!=vi.end())
		{
			if((*it)&1)
			{
				vi.erase(it);
			}
			else
			{
				++it;
			}
		} 
	//同样需要注意的是每次,insert后需要后移两个 
		for(int i:vi)
		{
			cout<<i<<' ';
		}
		cout<<endl;	
	}	
} 

//vector增长测试于reserve函数
namespace ql02
{
	template<class T>
	class qlalloc{
		public:
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef int difference_type; 
		template<class u>
		struct rebind{
			typedef qlalloc<u> other;
		}; 
		qlalloc()=default;
		template<class t>
		qlalloc(const qlalloc<t> &){}
		pointer allocate (size_t n)
		{
			n*=sizeof(T);
			cout<<"allocate"<<' '<<n<<"bytes"<<endl; 
			return static_cast<T*>(::operator new (n));	
		} 
		void deallocate (pointer p,size_t n)
		{
			cout<<"deallocate:"<<n*sizeof(T)<<"bytes"<<endl;
			::operator delete(p); 
		}
		//注:未写construct和destroy没有关系,在stl_construct文件中提供了一套默认的 
	};
	template<class u,class t>
	bool operator == (const qlalloc<u>&,const qlalloc<t>&)
	{
		return (true);
	}
	template<class u,class t>
	bool operator != (const qlalloc<u>&,const qlalloc<t>&)
	{
		return (false);
	}
	void test ()
	{
		const int size=100;
		cout<<"using reserve"<<endl;
		{
			vector<int,qlalloc<int>> vi;
			vi.reserve(size);
			for(int i=0;i<size;++i) 
			{
				vi.push_back(i);
			}
		}
		cout<<"unusing reserve"<<endl;
		{
			vector<int,qlalloc<int>> vi;
			//vi.reserve(size);
			for(int i=0;i<size;++i) 
			{
				vi.push_back(i);
			}	
		} 
	}
}
//push_back,emplace_back
namespace ql03
{
	class pre{
		public:
			string name;
			string coun;
			int y;
		public:
			pre (string& na,string& co,int _y):name(move(na)),coun(move(co)),y(_y){cout<<"cotr"<<endl;}
			pre (pre&& p):name(move(p.name)),coun(move(p.coun)),y(p.y){cout<<"copy cotr"<<endl;}
			pre& operator=(const pre& other)=default; 
			friend ostream& operator<< (ostream& os,const pre& p);
			

	};
			ostream& operator<< (ostream& os,const pre& p)
			{
				os<<p.coun<<' '<<p.name<<endl;
				return os;	
			} 
	template<class T>
	using v=vector<T>;
	void test()
	{
		v<pre> vi;
		string tem("fdsf");
		vi.reserve(2);
		vi.emplace_back(tem,tem,10);
		//auto p1=tem.begin();
		//auto p2=vi[0].name.begin();
		//cout<<' '<<<<endl;
//		tem[0]='d';
//		cout<<tem<<endl;
//		cout<<vi[0];
		vi.push_back({tem,tem,10}); 
		//分析:
		/*
		emplace_back相比push_back性能优化的愿意在于,emplace_back使用placement new直接在添加的地方
		构造处要添加的对象,而push_back则要把先把要初始化的内容初始化到一个临死对象中,再拷贝到要添加的地方,所有
		对于会有多余的耗时 
		*/ 
	}
}

int main ()
{
//	ql02::test();
	ql03::test();
	string tem("dfs");
//	f(tem);
	return 0;
} 
