#include<vector>
#include<iostream>
using namespace std;
int main ()
{
	vector<int> vi{0,1,3,3,4,5,6,7,8,9};
	//ɾ��vector�е�����,���Ǵ������,ԭ����,��erase��,ɾ��Ԫ��,�ᵼ��������Ԫ��ǰ��,��ʱ,��Ӧ���ƶ� 
//	for(int i=0;i<vi.size();i++)
//	{
//		if(vi[i]&1)
//		{
//			vi.erase(vi.begin()+i);
//		}
//	}
//��ȷд��1:
//	for(int i=0;i<vi.size();++i)
//	{
//		if(vi[i]&1)
//		{
//			vi.erase(vi.begin()+i);
//			--i;
//		}
//	} 
//��ȷд��2:
	vector<int>::iterator it=vi.begin();
	while(it!=vi.end())
	{
		if((*it)&1)
		{
			vi.erase(it);
		}
		else
		{
			++it;
		}
	} 
//ͬ����Ҫע�����ÿ��,insert����Ҫ�������� 
	for(int i:vi)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	return 0;
} 
