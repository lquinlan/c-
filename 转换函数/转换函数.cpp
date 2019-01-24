//ת��Ϊ���
/* 
#include<iostream>
using namespace std;
class fenshu
{
    public:
    fenshu (double f1,double f2=1.0):fz(f1),fm(f2)
    {

    }
    operator double () const 
    {
        return double (fz/fm);
    }
    private:
    double fz;
    double fm;
};
int main ()
{
    fenshu f1(3,4);
    double a=f1+4;
    cout<<a<<endl;
}
*/
//ת��Ϊ�Լ�
/* 
#include<iostream>
#include<algorithm>
#define gcd(a,b) __gcd(a,b)
using namespace std;
class fenshu
{
    public:
   	fenshu (int f1,int f2=1):fz(f1),fm(f2)//���캯������� no_explicit_one grgument�ǿ��Խ�һ����ת��Ϊ,������,������Ϸ����򲻿��� 
    {

    }
 	fenshu operator + (const fenshu &a) const
 	{
 		int tmp1=a.fm*fm/gcd(a.fm,fm);
 		int tmp2=a.fz*(tmp1/a.fm)+fz*(tmp1/fm);
 		return fenshu (tmp2/gcd(tmp1,tmp2),tmp1/gcd(tmp1,tmp2));
 	}
 	friend ostream& operator << (ostream &os,const fenshu& f); 
    private:
    int fz;
   	int fm;
};
ostream& operator << (ostream &os,const fenshu& f)
{
	os<<f.fz<<'/'<<f.fm;
	return os;
} 
int main ()
{
	fenshu f1 (3,4);
	fenshu f2=f1+4;
	cout<<f2<<endl;
}
*/ 
//����Ϊ������� ,����ambigous���� 
#include<iostream>
#include<algorithm>
#define gcd(a,b) __gcd(a,b)
using namespace std;
class fenshu
{
    public:
   	fenshu (int f1,int f2=1):fz(f1),fm(f2)//���캯������� no_explicit_one grgument�ǿ��Խ�һ����ת��Ϊ,������,������Ϸ����򲻿��� 
    {

    }
 	fenshu operator + (const fenshu &a) const
 	{
 		int tmp1=a.fm*fm/gcd(a.fm,fm);
 		int tmp2=a.fz*(tmp1/a.fm)+fz*(tmp1/fm);
 		return fenshu (tmp2/gcd(tmp1,tmp2),tmp1/gcd(tmp1,tmp2));
 	}
 	operator double () const 
    {
        return double (fz*1.0/fm);
    }
 	friend ostream& operator << (ostream &os,const fenshu& f); 
    private:
    int fz;
   	int fm;
};
ostream& operator << (ostream &os,const fenshu& f)
{
	os<<f.fz<<'/'<<f.fm;
	return os;
} 
int main ()
{
	fenshu f1 (3,4);
	double f4=4+f1;//����doubel()ת�� 
	fenshu f2=4.0+f1;//����doubleת��,�ڵ��ù��캯��ת�� 
	fenshu f3=f1+4;//��������֪��������һ�� 
	cout<<f2<<endl;
}
