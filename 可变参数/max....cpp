#include<iostream>
#include<initializer_list>
template<typename P,typename compare>
P _max_element (P _first,P _last,compare cmp) 
{
	if(_first==_last)
	{
		return _first;
	}
	P res=_first;
	while(++_first!=_last)
	{
		if(cmp(res,_first))
		{
			res=_first;
		}
	}
	return res;
}

struct less
{
	template<typename P1,typename P2>
	bool operator () (P1 f,P2 l)
	{
		return *f<*l;
	}
};

less Less ()
{
	return less();
}
template<typename T>
T max_element (T _first,T _last)
{
	return _max_element(_first,_last,Less());
} 
template<typename T>
T max (std::initializer_list<T> l)
{
	return *max_element(l.begin(),l.end());
}
int main ()
{
	std::cout<<max({534,654,3,1321,124,424,13,1,4423,1,4});
	return 0;
} 
