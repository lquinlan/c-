#include"Set.h"
#include<bits/stdc++.h>
using namespace std;
void explain ()
{
	char buffer[256];
    ifstream examplefile("set.txt");
    if (! examplefile.is_open())
    {
        cout << "Error opening file"; exit (1);
    }
    while (!examplefile.eof())
    {
        examplefile.getline(buffer,100);
        cout<<buffer<<endl;
    }
    return;
}
void data (Set &a,Set &b)
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator (seed);
  int n=generator()%100; 
  for(int i=0;i<n;i++)
  {
  	int a1=generator()%100;
  	if(i<=n/2)
  	{

  		a.add(a1);
  	}
  	else
  	{

		b.add(a1);
  	}

  }

}
void paint ()
{
	cout<<"***********************************"<<"\b Set工具 "<<"***************************************"<<endl; 
	cout<<"                           "<<"*********\b系统功能*********"<<endl; 
	cout<<"                           "<<"\b        1:使用说明          "<<endl;
	cout<<"                           "<<"\b        2:元素插入         "<<endl;
	cout<<"                           "<<"\b        3:元素删除          "<<endl;
	cout<<"                           "<<"\b        4:查找元素          "<<endl;
	cout<<"                           "<<"\b        5:集合大小          "<<endl;
	cout<<"                           "<<"\b        6:输出集合元素          "<<endl;
	cout<<"                           "<<"\b        7:集合的交          "<<endl;
	cout<<"                           "<<"\b        8:集合的并      "<<endl;
	cout<<"                           "<<"\b        9:集合的差          "<<endl;
	cout<<"                           "<<"\b        0:退出          "<<endl;	
	cout<<"                            "<<"\b其他功能请阅读使用说明" <<endl;
	cout<<"***********************************"<<"***********"<<"*************************************"<<endl; 
}  
int main ()
{
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	Set a,b;
	data (a,b);
	cout<<"\b集合中的原始数据采用随机生成"<<endl;
	cout<<"\b集合a中的元素:"<<endl;;
	a.print();
	cout<<"\b集合b中的元素:"<<endl;
	b.print();

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	paint(); 
	while(1)
	{
		cout<<"                           "<<"  请输入你要操作的功能：          "<<endl;
		int ind;
		cin>>ind; 
		if(ind==1)
			explain ();
		else if(ind==2)
		{
			cout<<"set a \b输入1\nset b \b输入 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<"\b输入要插入的元素:"<<endl;
				cin>>y;
				if(a.add(y))
				{
					cout<<"true"<<endl;
				}
				else
				{
					cout<<"false"<<endl;
				}
			} 
			else
			{
				cout<<"\b输入要插入的元素:"<<endl;
				cin>>y;
				if(b.add(y))
				{
					cout<<"true"<<endl;
				}
				else
				{
					cout<<"false"<<endl;
				}
			}
		}
		else if(ind==3)
		{
			cout<<"set a \b输入1\nset b \b输入 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<"\b输入要删除的元素:"<<endl;
				cin>>y;
				if(a.remove(y))
				{
					cout<<"true"<<endl;
				}
				else
				{
					cout<<"false"<<endl;
				}
			} 
			else
			{
				cout<<"\b输入要删除的元素:"<<endl;
				cin>>y;
				if(b.remove(y))
				{
					cout<<"true"<<endl;
				}
				else
				{
					cout<<"false"<<endl;
				}	
			}
		}
		else if(ind==4)
		{
			cout<<"set a \b输入1\nset b \b输入 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<"\b输入要查找的元素:"<<endl;
				cin>>y;
				if(a.contains(y))
				{
					cout<<"\b存在!"<<endl; 
				}	
				else
				{
					cout<<"\b不存在~"<<endl; 
				}
			} 
			else
			{
				cout<<"\b输入要查找的元素:"<<endl;
				cin>>y;
				if(b.contains(y))
				{
					cout<<"\b存在!"<<endl; 
				}	
				else
				{
					cout<<"\b不存在~"<<endl; 
				}	
			}
		} 
		else if(ind==5)
		{
			cout<<"set a \b输入1\nset b \b输入 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<a.Size()<<endl;	
			} 
			else
			{
				cout<<b.Size()<<endl;	
			}
		}
		else if(ind==6)
		{
			cout<<"set a \b输入1\nset b \b输入 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				a.print();	
			} 
			else
			{
				b.print();	
			}
		}
		else if(ind==7)
		{
			Set ans=a&&b;
			cout<<"\b集合a 交 集合b的结果:"<<endl;
			ans.print(); 
		}
		else if(ind==8)
		{
			Set ans=a+b;
			cout<<"\b集合a 并 集合b的结果:"<<endl;
			ans.print(); 
		}
		else if(ind==9)
		{
			Set ans=a-b;
			cout<<"\b集合a 差 集合b的结果:"<<endl;
			ans.print(); 
		}
		else
		{
			break;
		} 	
	}
	return 0;
	
}
