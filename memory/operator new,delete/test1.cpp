#include<iostream>
#include<utility>
using namespace std;
void* myalloc (size_t size)
{
	return malloc(size);
}
void myfree(void* ptr)
{
	return free(ptr); 
}
inline void* operator new (size_t size)
{
	cout<<"gghp new"<<endl;
	return myalloc(size);
}
inline void* operator new [] (size_t size)
{
	cout<<"gghp new[]"<<endl;
	return myalloc(size);
}
inline void operator delete (void* ptr)
{
	cout<<"gghp delete"<<endl;
	return myfree(ptr);
}
inline void operator delete[] (void* ptr)
{
	cout<<"gghp delete[]"<<endl;
	return myfree(ptr);
}
class foo
{
	private:
	int i,j;
	public :
	foo ():i(0),j(0){cout<<"default ctor"<<endl;}
	foo (int _i,int _j):i(_i),j(_j){cout<<"ctor"<<endl;}
	pair<int,int> get ()
	{
		return make_pair(i,j);
	}
		
};
int main ()
{
	foo* p;
	p=new foo(88,432);
	cout<<p<<endl;
	cout<<p->get().first<<endl;
	delete p;
	return 0;
}
