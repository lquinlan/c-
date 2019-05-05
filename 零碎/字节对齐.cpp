/*
字节对齐原因:
为提高cpu的存储速度,编译器会对struct,class的存储进行优化
对齐方式:
字节对齐标准就是他们中所含成员的最大字节数
struct 中字节对齐需要满足的条件：

    1、某个变量存放的起始位置相对于结构的起始位置的偏移量是该变量字节数的整数倍；

    2、结构所占用的总字节数是结构种字节数最长的变量的字节数的整数倍。 
*/
//int char double,4+1+3+8
struct Struct
{
    double d1; 
    char d2;
    int d3;
}a;
//sizeof(a) = 8 + 1 + 3 + 4 = 16。其中补上的 3 个字节是为了让 int 型数据的起始位置相对于结构起始位置的偏移量为 4 的整数倍。
struct Struct
{
    char d1;
    double d2;
    int d3;
}b;
//sizeof(b) = 1 + 7 + 8 + 4 = 20。 20 / 8 = 2 …… 4，所以需要再补上 4 个字节，使之成为 8 的 整数倍
#include <iostream>
using namespace std;

typedef struct A
{
    char aChar;
    int aInt_2;
    short aInt;
}TypeA;

typedef struct B
{
    char bChar[3];
    TypeA bA;
    double bDouble;
}TypeB;

int main()
{
    TypeA a;
    TypeB b;
    cout << sizeof(a) << endl << sizeof(b) << endl;
    return 0;
}
/*
输出为 12 24

解析：

由上述对字节对齐问题的讨论很容易便可以得出此题的答案。
sizeof(TypeA) = 1 + 3 + 4 + 2 = 10。 10 / 4 = 2 …… 2，故需要再补上 2 个字节，即 sizeof(TypeA) = 12;
sizeof(TypeB) = 3 + 1 + 12 + 8 = 24。之所以补上 1 个字节是因为 TypeA 类型在 struct TypeB 中的默认对齐方式
是 4 个字节（即 int 的字节大小，也即 struct TypeA 中最长的字节）。

*/ 
