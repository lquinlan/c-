#include<iostream>
using namespace std;
class A
{
	public :
	A ()
	{
		cout<<"this is A"<<endl;
	}	
} ;
class B
{
	public :
	B ()
	{
		cout<<"this is B"<<endl;
	}	
} ;
class C :public B
{
	public :
	C ()
	{
		cout<<"this is c"<<endl;
	}	
	A b;
};
int main ()
{
	C c;
}

