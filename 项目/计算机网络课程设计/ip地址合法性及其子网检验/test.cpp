#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
unsigned int subnet,ip,mask;
string getbin (int a)
{
    string tmp;
    while(a)
    {
        tmp+=(a%2)+'0';
        a/=2;
    }
    while(tmp.size()<8)
    {
        tmp+='0';
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
bool checkformat1 (string &s)
{
    int d=0,p=0;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]>='0'&&s[i]<='9')||s[i]=='/'||s[i]=='.')
        {
            if(s[i]=='/'||s[i]=='.')
            {
                
                if(s[i]=='.')
                {
                    ++d;
                }
                else
                {
                    ++p;
                }
                s[i]=' ';
            }
            continue;
        }
        else
        {
            return false;
        }
    }
    if(d!=3||p!=1)
    {
        return false;
    }
    istringstream str(s);
    int a;
    int cnt=0;
    while(str>>a)
    {
        if(a>=0&&a<=255)
        {
            ++cnt;
        }
        else
        {
            return false;
        }
        if(cnt<5)
        {
            string tmp=getbin(a);
            for(int i=0;i<tmp.size();++i)
            {
                subnet=subnet*2+tmp[i]-'0';
            }
        }
    }
    if(cnt!=5||a>32)
    {
        return false;
    }
    mask=a;
    return true;

}
bool checkformat2 (string &s)
{
    int d=0;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]>='0'&&s[i]<='9')||s[i]=='.')
        {
            if(s[i]=='.')
            {
                
                ++d;
                s[i]=' ';
            }
        }
        else
        {
            return false;
        }
    }
    if(d!=3)
    {
        return false;
    }
    istringstream str(s);
    int a;
    int cnt=0;
    while(str>>a)
    {
        if(a>=0&&a<=255)
        {
            ++cnt;
        }
        else
        {
            return false;
        }
        if(cnt<5)
        {
            string tmp=getbin(a);
            for(int i=0;i<tmp.size();++i)
            {
                ip=ip*2+tmp[i]-'0';
            }
        }
    }
    if(cnt!=4)
    {
        return false;
    }
    return true;

}
char getiptype ()
{
    if(ip>=0&&ip<=2147483647)
    {
        return 'A';
    }
    else if(ip>=2147483648&&ip<=3221225471)
    {
        return 'B';
    }
    else if(ip>=3221225472&&ip<=3758096383)
    {
        return 'C';
    }
    else if(ip>=3758096384&&ip<=4026531839)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
    
}
bool check_ip_sub ()
{
    unsigned int smask=0;
    for(int i=0;i<mask;++i)
    {
        smask^=(1<<(31-i));
    }
    //cout<<smask<<endl;
    if((smask&ip)==subnet)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main (int arg,char *args[])
{
    string a(args[1]),b(args[2]);
    if(!checkformat1(a))
    {
        cerr<<"子网号或子网掩码格式错误"<<endl;
    }
    else
    {
        cout<<"子网号为："<<endl;
        istringstream str(a);
        int i;
        int cnt=0;
        while(str>>i)
        {
            
            ++cnt;
            if(cnt<=3)
            {
                cout<<i<<'.';
            }
            else
            if(cnt==5)
            {
                cout<<"\n子网掩码为：";
                cout<<'\n'<<i<<endl;
            }
            else
            {
                cout<<i;
            }
            
        }
    }
    
    if(!checkformat2(b))
    {
        cerr<<"ip地址格式错误"<<endl;
    }
    else
    {
        cout<<"ip地址为："<<endl;
        istringstream str(b);
        int i;
        int cnt=0;
        while(str>>i)
        {
            cout<<i;
            ++cnt;
            if(cnt<=3)
            {
                cout<<'.';
            }
        }
        cout<<endl;
    }
    
    if(!check_ip_sub())
    {
        cerr<<"该IP地址不属于该子网"<<endl;
    }
    else
    {
        cout<<"该IP地址属于该子网"<<endl;
    }
    cout<<"该IP地址属于"<<getiptype()<<"地址"<<endl;

    return 0;
}
