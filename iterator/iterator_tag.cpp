#include <iostream>
#include <vector>
#include <list>
#include <iterator>
//iterator_tag再进行使用时一般是,算法已经定义出,适合不同迭代器进行访问的不同,方式, 在使用时,算法会询问,iterator的traits这是一个什么
//类型 ,让后找到与之对应的重载函数 
//注意因为这五个迭代器类型是一层一层的继承下来的,再没有找到与该类型匹配的函数时,会调用自己父类的 
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
        typename std::iterator_traits<Iter>::iterator_category());//算法询问迭代器的萃取器 
}
 
int main()
{
    std::vector<int> v;
    alg(v.begin(), v.end());
 
    std::list<int> l;
    alg(l.begin(), l.end());
 
//    std::istreambuf_iterator<char> i1(std::cin), i2;
//    alg(i1, i2); // 编译错误：无调用的匹配函数
}
