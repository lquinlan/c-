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
	cout<<"***********************************"<<"\b Set���� "<<"***************************************"<<endl; 
	cout<<"                           "<<"*********\bϵͳ����*********"<<endl; 
	cout<<"                           "<<"\b        1:ʹ��˵��          "<<endl;
	cout<<"                           "<<"\b        2:Ԫ�ز���         "<<endl;
	cout<<"                           "<<"\b        3:Ԫ��ɾ��          "<<endl;
	cout<<"                           "<<"\b        4:����Ԫ��          "<<endl;
	cout<<"                           "<<"\b        5:���ϴ�С          "<<endl;
	cout<<"                           "<<"\b        6:�������Ԫ��          "<<endl;
	cout<<"                           "<<"\b        7:���ϵĽ�          "<<endl;
	cout<<"                           "<<"\b        8:���ϵĲ�      "<<endl;
	cout<<"                           "<<"\b        9:���ϵĲ�          "<<endl;
	cout<<"                           "<<"\b        0:�˳�          "<<endl;	
	cout<<"                            "<<"\b�����������Ķ�ʹ��˵��" <<endl;
	cout<<"***********************************"<<"***********"<<"*************************************"<<endl; 
}  
int main ()
{
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	Set a,b;
	data (a,b);
	cout<<"\b�����е�ԭʼ���ݲ����������"<<endl;
	cout<<"\b����a�е�Ԫ��:"<<endl;;
	a.print();
	cout<<"\b����b�е�Ԫ��:"<<endl;
	b.print();

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	paint(); 
	while(1)
	{
		cout<<"                           "<<"  ��������Ҫ�����Ĺ��ܣ�          "<<endl;
		int ind;
		cin>>ind; 
		if(ind==1)
			explain ();
		else if(ind==2)
		{
			cout<<"set a \b����1\nset b \b���� 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<"\b����Ҫ�����Ԫ��:"<<endl;
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
				cout<<"\b����Ҫ�����Ԫ��:"<<endl;
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
			cout<<"set a \b����1\nset b \b���� 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<"\b����Ҫɾ����Ԫ��:"<<endl;
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
				cout<<"\b����Ҫɾ����Ԫ��:"<<endl;
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
			cout<<"set a \b����1\nset b \b���� 2:"<<endl;
			int x,y;
			cin>>x;
			if(x==1)
			{
				cout<<"\b����Ҫ���ҵ�Ԫ��:"<<endl;
				cin>>y;
				if(a.contains(y))
				{
					cout<<"\b����!"<<endl; 
				}	
				else
				{
					cout<<"\b������~"<<endl; 
				}
			} 
			else
			{
				cout<<"\b����Ҫ���ҵ�Ԫ��:"<<endl;
				cin>>y;
				if(b.contains(y))
				{
					cout<<"\b����!"<<endl; 
				}	
				else
				{
					cout<<"\b������~"<<endl; 
				}	
			}
		} 
		else if(ind==5)
		{
			cout<<"set a \b����1\nset b \b���� 2:"<<endl;
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
			cout<<"set a \b����1\nset b \b���� 2:"<<endl;
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
			cout<<"\b����a �� ����b�Ľ��:"<<endl;
			ans.print(); 
		}
		else if(ind==8)
		{
			Set ans=a+b;
			cout<<"\b����a �� ����b�Ľ��:"<<endl;
			ans.print(); 
		}
		else if(ind==9)
		{
			Set ans=a-b;
			cout<<"\b����a �� ����b�Ľ��:"<<endl;
			ans.print(); 
		}
		else
		{
			break;
		} 	
	}
	return 0;
	
}
