#include<vector>
#include<iostream>
using namespace std;

//����
namespace ql01
{
	void test()
	{
			vector<int> vi{0,1,3,3,4,5,6,7,8,9};
		//ɾ��vector�е�����,���Ǵ������,ԭ����,��erase��,ɾ��Ԫ��,�ᵼ��������Ԫ��ǰ��,��ʱ,��Ӧ���ƶ� 
	//	for(int i=0;i<vi.size();i++)
	//	{
	//		if(vi[i]&1)
	//		{
	//			vi.erase(vi.begin()+i);
	//		}
	//	}
	//��ȷд��1:
	//	for(int i=0;i<vi.size();++i)
	//	{
	//		if(vi[i]&1)
	//		{
	//			vi.erase(vi.begin()+i);
	//			--i;
	//		}
	//	} 
	//��ȷд��2:
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
	//ͬ����Ҫע�����ÿ��,insert����Ҫ�������� 
		for(int i:vi)
		{
			cout<<i<<' ';
		}
		cout<<endl;	
	}	
} 

//vector����������reserve����
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
			pointer tmp=static_cast<T*>(::operator new (n));
			cout<<"memeroy address="<<tmp<<endl;
			return tmp;
		} 
		void deallocate (pointer p,size_t n)
		{
			cout<<"deallocate:"<<n*sizeof(T)<<"bytes"<<endl;
			::operator delete(p); 
		}
		void construct (pointer p,const T &val)
		{
			cout<<"construct p="<<p<<endl;
			new(p)T(val);
		}	
		//ע:δдconstruct��destroyû�й�ϵ,��stl_construct�ļ����ṩ��һ��Ĭ�ϵ� 
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
	struct foo{
		int id;
		foo ():id(0)
		{
			cout<<"dau alot this="<<this<<"id="<<id<<endl;
		}
		foo (int i):id(i)
		{
			cout<<"alot this="<<this<<"id="<<id<<endl;
		}
		foo (const foo& T):id(T.id)
		{
			cout<<"T address"<<&T<<endl;
			cout<<"copy alot this="<<this<<"id="<<id<<endl;
		}
		void operator= (const foo &T)
		{
			cout<<"T address"<<&T<<endl;
			cout<<"= alot this="<<this<<"id="<<id<<endl;
			id=T.id;
		}
		~foo ()
		{
			cout<<"deal this="<<this<<"id="<<id<<endl;
		}
	};
	void test ()
	{
		const int size=10;
		cout<<"using reserve"<<endl;
		{
			vector<foo,qlalloc<foo>> vi;
			vi.reserve(size);
			for(int i=0;i<size;++i) 
			{
				vi.emplace_back(i);
			}
		}
		cout<<"unusing reserve"<<endl;
		{
			vector<foo,qlalloc<foo>> vi;
			//vi.reserve(size);
			for(int i=0;i<size;++i) 
			{
				vi.emplace_back(i);
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
		//����:
		/*
		emplace_back���push_back�����Ż���Ը������,emplace_backʹ��placement newֱ������ӵĵط�
		���촦Ҫ��ӵĶ���,��push_back��Ҫ���Ȱ�Ҫ��ʼ�������ݳ�ʼ����һ������������,�ٿ�����Ҫ��ӵĵط�,����
		���ڻ��ж���ĺ�ʱ 
		*/ 
	}
}

int main ()
{
	freopen("out.txt","w",stdout);
	ql02::test();
	//ql03::test();
	//string tem("dfs");
//	f(tem);
	return 0;
} 
