#include<iostream>
#include"complex1.h"
int main ()
{
    com<int,double> s1(1,1.4),s2(2,4.5);
    
    _dopt(&s1,s2);s1+=s2;
    cout<<s1<<endl;
    cout<<(+s2)<<endl;
    cout<<(s1==s2)<<endl;
    return 0;
}
