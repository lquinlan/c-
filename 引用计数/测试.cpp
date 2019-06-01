#include"String.hpp"
using std::cout;
using std::endl;
int main ()
{
	String a("123"),b(a),c;
	a+=c;
	cout<<b.getref()<<endl;;
	cout<<a<<endl;
} 
