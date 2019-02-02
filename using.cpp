//using 用法一
namespace ql01
{
	//using namespace 命名空间;
	using namespace std; 
} 
//using 用法二
namespace ql02 
{
	//给某一类型定义别名，和typedef作用一样。
	//using 类型别名=原类型;
	using uint=unsigned int;
	uint i=0;//相当于unsigned int;
}
//using 用法三 
namespace ql03
{
	//当派生类私有继承,基类的public,protected会变成私有,将他们变成共有的方法是:
	//using 类名 :: 变量名
	class A
	{
		public :
			int a;
	} ;
	class B:private A
	{
		public:
		using A::a;
	};
}
//using 用法四 
#include<iostream>
using namespace std;
namespace ql04
{
	/*
	如果基类中成员函数有多个重载版本，派生类可以重定义所继承的 0 个或多个版本，
	但是通过派生类型只能访问派生类中重定义的那些版本，
	所以如果派生类想通过自身类型使用所有的重载版本，则派生类必须要么重定义所有重载版本，要么一个也不重定义。
	有时类需要仅仅重定义一个重载集中某些版本的行为，并且想要继承其他版本的含义，在这种情况下，为了重定义需
	要特化的某个版本而不得不重定义每一个基类版本，可能会令人厌烦。可以在派生类中为重载成员名称提供 using 声明
	（为基类成员函数名称而作的 using 声明将该函数的所有重载实例加到派生类的作用域），使派生类不用重定义所继承的
	每一个基类版本。一个 using 声明只能指定一个名字，不能指定形参表，
	使用using声明将名字加入作用域之后，派生类只需要重定义本类型确实必须定义的那些函数，对其他版本可以使用继
	承的定义。
	*/

class Base
{
public:    
   void menfcn()
  {
     cout<<"Base function"<<endl; 
  }

    void menfcn(int n)
    {
     cout<< cout<<"Base function with int"<<endl; 
    }

};

class Derived : Base
{
public:    
	using Base::menfcn;//using声明只能指定一个名字，不能带形参表    
	int menfcn(int)
	{ 
		cout<< cout<<"Derived function with int"<<endl;
	}
};
void test()
{    
	Base b; 
    Derived d;   
  	b.menfcn();   
  	d.menfcn();
}
}
