#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;
namespace ql1921401 
{
	void test ()
	{
		int v[] {123,34,5,54};
		for(auto i:v)
		{
			cout<<i<<' ';
		}
		cout<<endl;
		vector<string> s{"dsfds","sad","dsad"}; 
		for(auto i:s)
		{
			cout<<i<<' ';
		}
		cout<<endl;
		cout<<max({342,234,131424,2352,5234,1242,3}); 
		int i{19} ;
		int j{0.5};//Ӧ����error,��GCCֻ��warning 
	}
}
int main ()
{
	ql1921401::test();
	return 0; 
}
/*
ԭ��:
	���������γ�һ��initialization list�Ķ���,initialiaztion list��������һ��array�Ķ���
	������캯���д�initialization list��������ֱ�Ӵ���һ������,��������������Ƿֽ��һ��
	,һ��,������Ӧ�Ĺ��캯��,���û�ж�Ӧ�����Ĺ��캯��,�������ᱨ��; 
*/ 
 
