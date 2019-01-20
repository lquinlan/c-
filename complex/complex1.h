//�����࣬ģ��ʵ�֣�
/*
    *1.������ģ���ǰ������
        ��Ҫ��ǰ�����template<>������
    *2.���������ⶨ��ĳ�Ա������ȫ����
         �����ⶨ��ĵĳ�Ա������ȫ�����������õ�����ĵط�����Ҫд��class��������<typename>;
    *3.������ģ�����Ԫ����
        *��1����Ԫ����д����ģ���У���������ֵ����⣻
        *��2���������������ⶨ��
            ��1������ǰ������
            ��2�����е���������<t>��ʾ�Ĳ����б�������֮ǰ������һ��ʵ�У�
    *** ����ģ���ʹ���ڡ�c++ prime��16�£�577��������ϸ�Ľ��ܣ��º�񲹣���
	*4.ͬһ����֮��Ķ���Ϊ��Ԫ
    *5.���ڷ��ز����Ǵ�ֵ���Ǵ�����,����Ž���Ķ����Ƿ�ԭ���Ѿ�����
    *6.typename()������ʱ����,��������ֻ�����ڵ�ǰ��
    c++�����﷨���յ�̫��ˣ���Ҫ����?��
*/
//����ʽ������
/*�����ظ�����*/
#ifndef __complex1_h__
#define __complex1_h__
#include<iostream>
using namespace std;
//��Ҫ��ǰ������
template<class T1,class T2>
class com;
template<class T1,class T2>
com<T1,T2>& _dopt (com<T1,T2>*,const com<T1,T2> &);
template<class T1,class T2>
//�������
/*
    ��Ĵ��·���
        1.����ָ�����
            ���ڲ���ָ����࣬���ǲ���̫���⣬�俽�����죬�������ƣ�������Ĭ�ϵĻ����Ϳ�����ɲ�����������ѡ��ĸ��Ʒ�ʽ�ǣ�һ��bitһ��bit����䣩
            ͬ�����û���������������ͬ�����Կ���ϵͳĬ�ϵ�����������
        2.���ڴ�ָ����࣬�����¸������н��н��ܣ�
*/
class com{
    public:
        com<T1,T2> (T1 r,T2 v) :re(r),im(v){}
        com<T1,T2> ():re(0),im(0){}
        //���ڹ��캯����д��
        /*
            �򵥽����ǳ�ʼ���͸�ֵ������
            �ڲ����б���ǳ�ʼ��
            �ں������ڵ��Ǹ�ֵ
            ��������ʵ�ֵ�Ч����Ȼһ�����Ƿ�����ʱ��ͷ�ʽ��ȫ��ͬ
            ���Ǹ����Ƽ�ʹ�ò����б����ָ�������ķ�ʽ���Է�����һЩ����Ҫ�Ĵ���
        */
        com<T1,T2> & operator += (const com<T1,T2>&);
        //���ڷ���ֵ�Ĵ��������û��Ǵ�ֵ
        /*
            ͨ����������õ�Ч��Ҫ���ڴ�ֵ��
            �򵥵���˵�����ڿ��Դ������õ����������ʹ�ô�����
            �����Դ����õ���������صĽ��ʵ�ں���������ʱ���ɵģ�����������£�ֻ�ܴ�ֵ������û�������˵�����Կɴ�����
            ������Щ�����ֻ�ܴ������ã���һЩ����������+/-�ȣ�
        */
        T1 real ()const
        {
            return re;
        }
        T2 imag ()const
        {
            return im;
        }
        //���ڳ���Ա����
        /*
            ���ڳ�Ա����������Ҫ����������ú����Ƿ���޸ģ���Ա������ֵ
            ��������޸ģ�һ��Ҫ+const���߱��������Է�ʹ������ʹ��ʱ��������
        */
    private:
        T1 re;
        T2 im;
    friend com<T1,T2>& _dopt<T1,T2> (com<T1,T2>*,const com<T1,T2>&);
};
template<class T1,class T2>
inline T1 real (const com<T1,T2> & x)
{
    return x.real();
}
template<class T1,class T2>
inline T2 imag (const com<T1,T2>& x)
{
    return x.imag();
}
template<class T1,class T2>
inline com<T1,T2>& _dopt (com<T1,T2> *ths,const com<T1,T2>& r)
{
    ths->re+=r.re;
    ths->im+=r.im;
    return *ths;
}
template<class T1,class T2>
inline com<T1,T2>& com<T1,T2>::operator+=(const com<T1,T2>& r)
{
    return _dopt(this,r);
}
template<class T1,class T2>
inline com<T1,T2> operator+ (const com<T1,T2>& x,const com<T1,T2>& y)
{
    return com<T1,T2>(real(x)+real(y),imag(x)+imag(y));
}
template<class T1,class T2>
inline com<T1,T2> operator + (T1 x,const com<T1,T2>& y)
{
    return com<T1,T2>(real(y)+x,imag(y));
}
template<class T1,class T2>
inline com<T1,T2> operator+ (const com<T1,T2>& x,T1 y)
{
    return com<T1,T2>(real(x)+y,imag(x));
}
template<class T1,class T2>
ostream& operator<< (ostream& os,const com<T1,T2>& x)
{
    os<<"("<<real(x)<<','<<imag(x)<<")";
}
template<class T1,class T2>
inline const com<T1,T2>& operator+ (const com<T1,T2> &x)
{
    return x;
}
template<class T1,class T2>
inline com<T1,T2> operator- (const com<T1,T2> &x)
{
    return com<T1,T2>(-real(x),-imag(x));
}
template<class T1,class T2>
inline bool operator == (const com<T1,T2> & x,const com<T1,T2> y)
{
    return real(x)==real(y)&&imag(x)==imag(y);
}
template<class T1,class T2>
inline com<T1,T2> conj (const com<T1,T2>& x )
{
    return com<T1,T2>(real(x),-imag(x));
}
#endif
