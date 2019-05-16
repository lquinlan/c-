#include<iostream>
using namespace std;
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
static void* myalloc (size_t size)
{
	return malloc(size);
}
static void myfree(void* ptr)
{
	return free(ptr); 
}
static void* operator new (size_t size,long siz)
{
	cout<<"gghp new"<<endl;
	return myalloc(size+siz);
}
static void* operator new [] (size_t size)
{
	cout<<"gghp new[]"<<endl;
	return myalloc(size);
}
static void operator delete (void* ptr)
{
	cout<<"gghp delete"<<endl;
	return myfree(ptr);
}
static void operator delete[] (void* ptr)
{
	cout<<"gghp delete[]"<<endl;
	return myfree(ptr);
}	
};
int main ()
{
	foo *p,*q;
	p=new(100) foo();

	delete p;

	return 0;
}
