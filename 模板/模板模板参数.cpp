#include<iostream>
#include<list>
#include<string>
using namespace std;
template<typename T,template<typename T>
					class con>
class xswl
{
	private:
		con<T> c;
	public:
		xswl ()
		{
		}	
};
//加这一句是因为,list不止一个模板参数,对于只有一个模板参数的存在,可以不用这样声明别名 
template<typename T>
using Lst = list<T, allocator<T>>; 
int main ()
{
	xswl<string,Lst> a;
	return 0;
}
/*
template<typename T, typename Sequence = list<T>>
class stack
{
    private:
        Sequence c;
};
这不是模板模板参数,因为,他的用法是
stack<int,deque<int> 此时已经指定,没有任何模糊的地方 
*/
