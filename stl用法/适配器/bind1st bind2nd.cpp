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
	
*/
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std;
int main ()
{
	vector<int> vi{0,0,0,0,0,0,0,0,12,232};
	auto it=find_if(vi.begin(),vi.end(),bind1st(not_equal_to<int>(),0));
	auto it1=find_if(vi.begin(),vi.end(),bind2nd(greater<int>(),0));
	cout<<*it<<endl; 
	cout<<*it1<<endl;
	return 0;
}

