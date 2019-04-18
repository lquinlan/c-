#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
	vector<int> vi;
	generate_n(back_insert_iterator<vector<int>>(vi),10,
				[n=0]()mutable {return ++n;});
	for(auto i:vi)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	return 0;
	 
}
