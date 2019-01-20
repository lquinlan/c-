#include"String.hpp"
using std::cout;
using std::endl;
int main ()
{
	String a("123"),b(a);
	a+=b;
	cout<<b.getref()<<endl;;
	cout<<a<<" "<<b<<endl;
} 
