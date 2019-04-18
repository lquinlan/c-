#include<vector>
#include<iostream>
using namespace std;
int main ()
{
	vector<int> vi{0,1,3,3,4,5,6,7,8,9};
	//删除vector中的奇数,这是错误代码,原因是,在erase中,删除元素,会导致其他的元素前移,此时,不应该移动 
//	for(int i=0;i<vi.size();i++)
//	{
//		if(vi[i]&1)
//		{
//			vi.erase(vi.begin()+i);
//		}
//	}
//正确写法1:
//	for(int i=0;i<vi.size();++i)
//	{
//		if(vi[i]&1)
//		{
//			vi.erase(vi.begin()+i);
//			--i;
//		}
//	} 
//正确写法2:
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
//同样需要注意的是每次,insert后需要后移两个 
	for(int i:vi)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	return 0;
} 
