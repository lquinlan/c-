#include<iostream>
#include<initializer_list>
using namespace std;
//����������Ϊ����
namespace ql32401
{
	template<typename T,typename comp>
	T max (initializer_list<T> t,comp cmp)
	{
		auto st=t.begin();
		auto se=t.end();
		T maxn=*st;
		while(st!=se)
		{
			if(cmp(maxn,*st))
			{
				maxn=*st;
			}
			++st;
		}
		return maxn;
	}
}
//����ָ��������Ϊ����,��ͬ�ڵ�һ��, 
namespace ql32402
{
	template<typename T>
	T max (initializer_list<T> t,bool (*cmp) (const T& s1,const T& s2))
	{
		auto st=t.begin();
		auto se=t.end();
		T maxn=*st;
		while(st!=se)
		{
			if(cmp(maxn,*st))
			{
				maxn=*st;
			}
			++st;
		}
		return maxn;
	}
}
//����� typedef��������ģ��,�Ͳ���ʾ�� 
namespace ql32403 
{
	template<typename T>
	using cp=bool(const T& ,const T&); 
	template<typename T>
	T max (initializer_list<T> t,cp<T> cmp)
	{
		auto st=t.begin();
		auto se=t.end();
		T maxn=*st;
		while(st!=se)
		{
			if(cmp(maxn,*st))
			{
				maxn=*st;
			}
			++st;
		}
		return maxn;
	}
}
//������ʽ�Ķ��� 
namespace ql32404
{
	bool cmp (const int& t1,const int &t2)
	{
		return t1<t2;	
	} 
	typedef decltype(cmp) f;
}
//��������Ϊ����ָ��,�����Ҫע��,�����������Զ�����ת���ɺ���ָ��,������Ҫ��ȷ����,���Ǻ���ָ�� 
//�����ʹ�ñ���,���ߺ��÷�������+decltype,ʹ��decltypeʱ��Ҫ��ʾ�ļ���*,�����֪�����غ����������
//Ҳ����ֱ��ʹ��decltype,ͬ����Ҫ��ʾ�ļ���* 
#include<string> 
namespace ql32405
{
	size_t sum1 (const string& s1)
	{
		size_t sum=0;
		for(auto i:s1)
		{
			sum+=static_cast<size_t>(i);
		}
		return sum;
	}
	using ff=size_t (const string&) ;
	auto f ()-> decltype(&sum1)
	{
		
	}
	decltype(sum1) *ff1()
	{
		
	} 
}
bool cmp (const string& t1,const string &t2)
{
	return t1<t2;
}
int main ()
{
	cout<<ql32401::max({"abc","asdfs","zs","asda"},cmp)<<endl;
	cout<<ql32402::max<string>({"abc","asdfs","zs","asda"},cmp)<<endl;
	cout<<ql32402::max<string>({"abc","asdfs","zs","asda"},&cmp)<<endl;//������������ͬ,�������Զ���������ת���ɺ���ָ�� 
	cout<<ql32403::max<string>({"abc","asdfs","zs","asda"},cmp)<<endl;
	return 0;
}
