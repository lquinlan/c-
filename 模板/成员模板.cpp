#include <string>
#include <iostream>
#include <memory> //shared_ptr
using namespace std;
namespace j01
{
class Base1 { };
class Derived1: public Base1 {  };	
class Base2 {  };
class Derived2: public Base2 {  };
template<class T1,class T2>
class pair{
	public:
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	pair():first(T1()),second(T2()){}
	template<class U1,class U2>
	pair(const pair<U1,U2>& p):first(p.first),second(p.second){}	
};	
void test ()
{
	cout<<"test_member_template()"<<endl;
    pair<Derived1, Derived2> p; 
    pair<Base1, Base2> p2(pair<Derived1, Derived2>());     
    pair<Base1, Base2> p3(p); 
	//子类的对象可以复给父类,父类的对象不可以复制给子类,会发生找不到与之匹配的构造函数;
	 Base1* ptr = new Derived1; 	//up-cast 
	shared_ptr<Base1> sptr(new Derived1); 	//simulate up-cast
    //Note: make sure your environment support C++2.0 at first. 
    /*template<typename _Tp>
    class shared_ptr : public __shared_ptr<_Tp>
    {
    public:
      
       *  @brief  Construct an empty %shared_ptr.
       *  @post   use_count()==0 && get()==0
       
      constexpr shared_ptr() noexcept
      : __shared_ptr<_Tp>() { }

      shared_ptr(const shared_ptr&) noexcept = default;

      
       *  @brief  Construct a %shared_ptr that owns the pointer @a __p.
       *  @param  __p  A pointer that is convertible to element_type*.
       *  @post   use_count() == 1 && get() == __p
       *  @throw  std::bad_alloc, in which case @c delete @a __p is called.
       
      template<typename _Tp1>
	explicit shared_ptr(_Tp1* __p)
        : __shared_ptr<_Tp>(__p) { }
		*/
}
} 
int main ()
{
	j01::test();
	return 0;
} 
