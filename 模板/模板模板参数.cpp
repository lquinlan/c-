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
//����һ������Ϊ,list��ֹһ��ģ�����,����ֻ��һ��ģ������Ĵ���,���Բ��������������� 
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
�ⲻ��ģ��ģ�����,��Ϊ,�����÷���
stack<int,deque<int> ��ʱ�Ѿ�ָ��,û���κ�ģ���ĵط� 
*/
