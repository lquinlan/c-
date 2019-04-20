/*
	*Ŀ�����ڽ��޷�ƥ��ĵĺ����׽ӳɿ���ƥ������� 
	*���� vector<int> vi{0,0,0,0,0,0,11,3,1};
	*������ƥ�䵽��һ���������,Ҳ�����������find_if��
	*not_equal_toд����������ʽ
	*auto it=find_if(vi.begin(),vi.end(),not_equal_to<int>(0));
	*��ʵ���ϲ���,��Ϊnot_equal_to�ķº������ܵ�������,����,��������
	*��ֻ���˵�һ������,���������޷�ƥ�䵽�ź���
	*�����ʱ��������������������,�����д����������ʽ
	*auto it=find_if(vi.begin(),vi.end(),bind1st(not_equal_to<int>(),0); 
	*ԭ����������ļ���
	*�ܲ�����������������c++11֮������(ԭ��Ĳ�����������c++����ľ޴�,Ӱ��,�����Ѿ���,bind
	*�������,bind���԰�,��������ĳ�Ա
	*ʹ��ʱ��Ҫusing namespace std::placeholders;
	*����_1,_2,_3,..._N��ռλ��,��ʾ��Щû�а󶨵ı���,���õĲ�����,��ΰ�,���һ��������ʵ��
	*�����Գ���_1�ĵط�,�Դ����� 
	*�÷�:https://zh.cppreference.com/w/cpp/utility/functional/bind
	*���ڱ���Ŀǰ,ˮƽ����,��ʱ���������°��ԭ��,�Ժ����������в���; 
	
*/
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std::placeholders;
using namespace std;
class foo
{
	public:
		foo (int i=0,int j=0):_i(i),_j(j){}
		void print (int t) const{cout<<_i+t<<' ';}
		int _j; 
	private:
		int _i;	
};
int main ()
{
	vector<int> vi{0,0,0,0,0,0,0,0,12,232};
	//auto it=find_if(vi.begin(),vi.end(),bind1st(not_equal_to<int>(),0));
	auto it=find_if(vi.begin(),vi.end(),bind(not_equal_to<int>(),_1,0));
	//auto it1=find_if(vi.begin(),vi.end(),bind2nd(greater<int>(),0));
	auto it1=find_if(vi.begin(),vi.end(),bind(greater<int>(),_1,0));
	cout<<*it<<endl; 
	cout<<*it1<<endl;
	foo fo;
	auto f=bind(&foo::print,fo,_1);
	f(10);
	auto f1=bind(&foo::_j,_1);
	cout<<f1(fo)<<endl;
	auto f2=[](int i,int j){
		return i<j;
	} ;
	auto f3=bind(f2,_1,2);
	cout<<boolalpha<<f3(11)<<endl;
	function<bool(int,int)> f4=f2;
	auto f5=bind(f4,_1,2);
	cout<<boolalpha<<f5(11)<<endl;	
	return 0;
}

