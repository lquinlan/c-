#include <iostream>
#include <vector>
#include <list>
#include <iterator>
//iterator_tag�ٽ���ʹ��ʱһ����,�㷨�Ѿ������,�ʺϲ�ͬ���������з��ʵĲ�ͬ,��ʽ, ��ʹ��ʱ,�㷨��ѯ��,iterator��traits����һ��ʲô
//���� ,�ú��ҵ���֮��Ӧ�����غ��� 
//ע����Ϊ�����������������һ��һ��ļ̳�������,��û���ҵ��������ƥ��ĺ���ʱ,������Լ������ 
template< class BDIter >
void alg(BDIter, BDIter, std:: input_iterator_tag)
{
    std::cout << "alg() called for input iterator\n";
}
template< class DIter >
void alg(DIter, DIter, std:: bidirectional_iterator_tag)
{
    std::cout << "alg() called for bidirectional iterator\n";
}
template <class RAIter>
void alg(RAIter, RAIter, std::random_access_iterator_tag)
{
    std::cout << "alg() called for random-access iterator\n";
}
 
template< class Iter >
void alg(Iter first, Iter last)
{
    alg(first, last,
        typename std::iterator_traits<Iter>::iterator_category());//�㷨ѯ�ʵ���������ȡ�� 
}
 
int main()
{
    std::vector<int> v;
    alg(v.begin(), v.end());
 
    std::list<int> l;
    alg(l.begin(), l.end());
 
//    std::istreambuf_iterator<char> i1(std::cin), i2;
//    alg(i1, i2); // ��������޵��õ�ƥ�亯��
}
