/*
�ֽڶ���ԭ��:
Ϊ���cpu�Ĵ洢�ٶ�,���������struct,class�Ĵ洢�����Ż�
���뷽ʽ:
�ֽڶ����׼����������������Ա������ֽ���
struct ���ֽڶ�����Ҫ�����������

    1��ĳ��������ŵ���ʼλ������ڽṹ����ʼλ�õ�ƫ�����Ǹñ����ֽ�������������

    2���ṹ��ռ�õ����ֽ����ǽṹ���ֽ�����ı������ֽ������������� 
*/
//int char double,4+1+3+8
struct Struct
{
    double d1; 
    char d2;
    int d3;
}a;
//sizeof(a) = 8 + 1 + 3 + 4 = 16�����в��ϵ� 3 ���ֽ���Ϊ���� int �����ݵ���ʼλ������ڽṹ��ʼλ�õ�ƫ����Ϊ 4 ����������
struct Struct
{
    char d1;
    double d2;
    int d3;
}b;
//sizeof(b) = 1 + 7 + 8 + 4 = 20�� 20 / 8 = 2 ���� 4��������Ҫ�ٲ��� 4 ���ֽڣ�ʹ֮��Ϊ 8 �� ������
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
���Ϊ 12 24

������

���������ֽڶ�����������ۺ����ױ���Եó�����Ĵ𰸡�
sizeof(TypeA) = 1 + 3 + 4 + 2 = 10�� 10 / 4 = 2 ���� 2������Ҫ�ٲ��� 2 ���ֽڣ��� sizeof(TypeA) = 12;
sizeof(TypeB) = 3 + 1 + 12 + 8 = 24��֮���Բ��� 1 ���ֽ�����Ϊ TypeA ������ struct TypeB �е�Ĭ�϶��뷽ʽ
�� 4 ���ֽڣ��� int ���ֽڴ�С��Ҳ�� struct TypeA ������ֽڣ���

*/ 
