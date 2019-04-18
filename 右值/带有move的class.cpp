/*
һ��ʼһֱ��copy construct ��Ϊ,һ��ʼһֱ��Ϊ�Ǵ���д��������,֮��һֱ��������Դ���������,����Ӧ�����Լ��ı������汾,��
vector,�ɳ�������,���õ��ǿ�������,��û��move�汾,��֮��������,������֮������ȫ������ 
*/ 
#include<bits/stdc++.h>
using namespace std;
namespace ql1938
{
	class mystring
	{
		public:
		static size_t Dctor;//�ۼ�default_ctor���� 
		static size_t Ctor;//�ۼ�ctor���� 
		static size_t Cctor;//�ۼ�copy_ctor���д��� 
		static size_t Casgn;//�ۼ�copy_asgn���д��� 
		static size_t Mctor;//�ۼ�move_ctor���� 
		static size_t Masgn;//�ۼ�move_asgn���� 
		static size_t Dtor;//�ۼ�dtor����
		private :
			char *_data;
			size_t _len;
			void init_data (const char *s)
			{
				_data=new char[_len+1];
				memcpy(_data,s,_len);
				_data[_len]='\0';
			} 
		public:
		mystring ():_data(nullptr),_len(0) { ++Dctor;}
		mystring (const char *p):_len(strlen(p))
		{
			++Ctor;
			init_data(p); 
		} 
		mystring (const mystring &str):_len(str._len)
		{
			++Cctor;
			init_data(str._data);
		}
		mystring (mystring &&str) noexcept //����Ҫд������߱�����û���쳣,��Ȼ����������ʹ�� 
		:_data(str._data),_len(str._len) 
		{
			++Mctor;
			str._len=0;
			str._data=nullptr;//��仰������Ҫ; 
		} 
		mystring& operator = (const mystring &str)
		{
			++Casgn;
			if(this==&str)
			{
				return *this;
			} 
			else
			{
				if(_data!=nullptr)
					delete _data;
				_len=str._len;
				init_data(str._data);
				return *this;
			}
		}
		mystring& operator = (mystring &&str) noexcept
		{
			++Masgn;
			if(this==&str)
			{
				return *this;
			} 
			else
			{
				if(_data!=nullptr)
					delete _data;
				_len=str._len;
				_data=str._data;
				str._len=0;
				str._data=nullptr;
				return *this;
			}
		}
		virtual ~mystring ()
		{
			++Dtor; 
			if(_data)
			{
				delete _data;
			}
		} 
		bool operator < (const mystring &rhs) const
		{
			return string (this->_data)<string (rhs._data);
		}
		bool operator == (const mystring &rhs) const
		{
			return string (this->_data)==string (rhs._data);
		}
		char* get () const {return _data;}
	};
	size_t mystring::Dctor=0;//�ۼ�default_ctor���� 
	size_t mystring::Ctor=0;//�ۼ�ctor���� 
	size_t mystring::Cctor=0;//�ۼ�copy_ctor���д��� 
	size_t mystring::Casgn=0;//�ۼ�copy_asgn���д��� 
	size_t mystring::Mctor=0;//�ۼ�move_ctor���� 
	size_t mystring::Masgn=0;//�ۼ�move_asgn���� 
	size_t mystring::Dtor=0;//�ۼ�dtor����
	class nmystring
	{
		public:
		static size_t Dctor;//�ۼ�default_ctor���� 
		static size_t Ctor;//�ۼ�ctor���� 
		static size_t Cctor;//�ۼ�copy_ctor���д��� 
		static size_t Casgn;//�ۼ�copy_asgn���д��� 
		static size_t Mctor;//�ۼ�move_ctor���� 
		static size_t Masgn;//�ۼ�move_asgn���� 
		static size_t Dtor;//�ۼ�dtor����
		private :
			char *_data;
			size_t _len;
			void init_data (const char *s)
			{
				_data=new char[_len+1];
				memcpy(_data,s,_len);
				_data[_len]='\0';
			} 
		public:
		nmystring ():_data(nullptr),_len(0) { ++Dctor;}
		nmystring (const char *p):_len(strlen(p))
		{
			++Ctor;
			init_data(p); 
		} 
		nmystring (const nmystring &str):_len(str._len)
		{
			++Cctor;
			init_data(str._data);
		}
//		nmystring (nmystring &&str) noexcept //����Ҫд������߱�����û���쳣,��Ȼ����������ʹ�� 
//		:_data(str._data),_len(str._len) 
//		{
//			++Mctor;
//			str._len=0;
//			str._data=nullptr;//��仰������Ҫ; 
//		} 
		nmystring& operator = (const nmystring &str)
		{
			++Casgn;
			if(this==&str)
			{
				return *this;
			} 
			else
			{
				if(_data!=nullptr)
					delete _data;
				_len=str._len;
				init_data(str._data);
				return *this;
			}
		}
//		nmystring& operator = (nmystring &&str) noexcept
//		{
//			++Masgn;
//			if(this==&str)
//			{
//				return *this;
//			} 
//			else
//			{
//				if(_data!=nullptr)
//					delete _data;
//				_len=str._len;
//				_data=str._data;
//				str._len=0;
//				str._data=nullptr;
//				return *this;
//			}
//		}
		virtual ~nmystring ()
		{
			++Dtor; 
			if(_data)
			{
				delete _data;
			}
		} 
		bool operator < (const nmystring &rhs) const
		{
			return string (this->_data)<string (rhs._data);
		}
		bool operator == (const nmystring &rhs) const
		{
			return string (this->_data)==string (rhs._data);
		}
		char* get () const {return _data;}
	};
	size_t nmystring::Dctor=0;//�ۼ�default_ctor���� 
	size_t nmystring::Ctor=0;//�ۼ�ctor���� 
	size_t nmystring::Cctor=0;//�ۼ�copy_ctor���д��� 
	size_t nmystring::Casgn=0;//�ۼ�copy_asgn���д��� 
	size_t nmystring::Mctor=0;//�ۼ�move_ctor���� 
	size_t nmystring::Masgn=0;//�ۼ�move_asgn���� 
	size_t nmystring::Dtor=0;//�ۼ�dtor����
}
namespace std
{
	template<>
	struct hash<ql1938::mystring>
	{
		size_t operator() (const ql1938::mystring &rhs) const noexcept
		{
			return hash<string> ()(string(rhs.get()));
		} 	
	};
} 
namespace std
{
	template<>
	struct hash<ql1938::nmystring>
	{
		size_t operator() (const ql1938::nmystring &rhs) const noexcept
		{
			return hash<string> ()(string(rhs.get()));
		} 	
	};
} 
void output_static (const  ql1938::mystring &r)
{
	cout<<"Dctor"<<ql1938::mystring::Dctor<<endl; 
	cout<<"Ctor"<<ql1938::mystring::Ctor<<endl; 
	cout<<"Cctor"<<ql1938::mystring::Cctor<<endl; 
	cout<<"Casgn"<<ql1938::mystring::Casgn<<endl; 
	cout<<"Mctor"<<ql1938::mystring::Mctor<<endl; 
	cout<<"Masgn"<<ql1938::mystring::Masgn<<endl; 
	cout<<"Dtor"<<ql1938::mystring::Dtor<<endl; 
	ql1938::mystring::Dctor=0;
	ql1938::mystring::Ctor=0;
	ql1938::mystring::Cctor=0;
	ql1938::mystring::Casgn=0;
	ql1938::mystring::Mctor=0;
	ql1938::mystring::Masgn=0;
	ql1938::mystring::Dtor=0;
}
void output_static1 (const  ql1938::nmystring &r)
{
	cout<<"Dctor"<<ql1938::nmystring::Dctor<<endl; 
	cout<<"Ctor"<<ql1938::nmystring::Ctor<<endl; 
	cout<<"Cctor"<<ql1938::nmystring::Cctor<<endl; 
	cout<<"Casgn"<<ql1938::nmystring::Casgn<<endl; 
	cout<<"Mctor"<<ql1938::nmystring::Mctor<<endl; 
	cout<<"Masgn"<<ql1938::nmystring::Masgn<<endl; 
	cout<<"Dtor"<<ql1938::nmystring::Dtor<<endl; 
//	ql1938::mystring::Dctor=0;
//	ql1938::mystring::Ctor=0;
//	ql1938::mystring::Cctor=0;
//	ql1938::mystring::Casgn=0;
//	ql1938::mystring::Mctor=0;
//	ql1938::mystring::Masgn=0;
//	ql1938::mystring::Dtor=0;
}
template<typename M,typename M1>
void test_c (M t,M1 t1,long long val)
{
	char buf[10];
	typedef typename iterator_traits<typename M::iterator>::value_type Vty;
	clock_t timestart =clock();
	for(long long i=0;i<val;i++)
	{
		snprintf(buf,10,"%d",rand());
		auto ite=t.end();
		t.insert(ite,Vty(buf));
		
	}	
	cout<<"move construct mili_second= "<<(clock()-timestart)<<endl;
	cout<<"size="<<t.size()<<endl;
	output_static(*(begin(t)));
	timestart = clock();
	typedef typename iterator_traits<typename M1::iterator>::value_type Vty1;
	for(long long i=0;i<val;i++)
	{
		snprintf(buf,10,"%d",rand());
		auto ite=t1.end();
		//Vty1 tem(buf);
		t1.insert(ite,Vty1(buf));
		
	}	
	cout<<"copy construct mili_second= "<<(clock()-timestart)<<endl;
	cout<<"size="<<t1.size()<<endl;
	output_static1(*(begin(t1)));
	timestart = clock();	
	M c1(t);						
	cout << "copy, milli-seconds : " << (clock()-timestart) << endl;
	timestart = clock();	
	M c12(move(c1));						
	cout << "move copy, milli-seconds : " << (clock()-timestart) << endl;	
}

int main ()
{
	test_c(unordered_set<ql1938::mystring> (),unordered_set<ql1938::nmystring> (),3000000);
	test_c(vector<ql1938::mystring> (),vector<ql1938::nmystring> (),30000);
	test_c(set<ql1938::mystring> (),set<ql1938::nmystring> (),1000000);
	return 0;
}

