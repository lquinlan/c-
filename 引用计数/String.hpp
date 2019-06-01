/*
    引用计数是c++采用的一种高效的内存管理措施,也是标准库采用的内存管理措施;
    采用委托设计,在本垒中只设计接口,在其他类中,实现功能,用引用指向该类,同时该类中
    有一个引用计数count,记录有多少个相同的内容,共用一块内存,只有当需要修改时,才会
    采用copy by writer,实时复制,c++string ,即采用这种措施.
    一般情况下只有拷贝构造采用引用计数
    
*/
//string.h
#ifndef __String_h_
#define __String_h_
#include<iostream>
#include<cstring>
class String{
public:
    String (const char * initvalue="");
    String (const String &str);
    String& operator= (const String& str);
    ~String();
    String operator +(const String& str);
    String& operator+= (const String &str);
    const char& operator [](int index) const;
    char& operator [](int index);
    bool operator == (const String& str);
    int getlength ();
    int getref();
    friend std::istream& operator>> (std::istream &in,const String &str);
    friend std::ostream& operator<< (std::ostream &os,const String &str);
private:
    struct strbref//引用计数
    {
        int ref;
        char *m_str;
        strbref (const char* initvalue);
        ~strbref ();
    };
    strbref* value;
};
inline String::strbref::strbref(const char* initvalue=nullptr):ref(1)
{
    if(initvalue==nullptr)
    {
        m_str=new char[1];//保持形式上的一致
        m_str[0]='\0';
    }
    else{
        m_str=new char[strlen(initvalue)+1];
        strcpy(m_str,initvalue);
    }
}
inline String::strbref::~strbref()
{
    delete[] m_str;
    m_str=nullptr;//释放后赋值为nullptr时好习惯
}
inline String::String(const char* initvalue):value(new strbref(initvalue)){}
inline String::String(const String& str):value(str.value){//对于拷贝构造只需要引用加1,高效快速
    ++value->ref;
}
inline String& String::operator=(const String &str)
{
    if(this->value==str.value)//检测是否自我复制,避免出错
    {
        return *this;
    }
    if(--value->ref==0)//左引用减一
    {
        delete value;
    }
    value=str.value;
    ++value->ref;//右引用加一
    return *this;
}
inline String::~String ()
{
    if(--value->ref==0)//当引用数为0时释放掉
    {
        delete value;
    }
}
inline String& String::operator+= (const String &str)
{
    if(--value->ref==0)
    {
        delete value;
    }
    //右为空
    if(str.value->m_str[0]=='\0')
    {
        value =new strbref(value->m_str);
        return *this;
    }
    //左为空
    if(value->m_str[0]=='\0')
    {
        value =new strbref(str.value->m_str);
        return *this;
    }
    //都不为空
    char *tmp=new char[strlen(value->m_str)+strlen(str.value->m_str)+1];
    strcpy(tmp,value->m_str);
    strcat(tmp,str.value->m_str);
    value=new strbref(tmp);
    return *this;
}
inline String String::operator+(const String& str){
//临时变量,借用+=实现操作,简化代码
	return String(*this) += str;

}
inline bool String::operator==(const String&str)
{
    return strcmp(value->m_str,str.value->m_str)==0?true:false;
}
//设计const [],和非const [],适用于const string ,和非const string
inline const char& String::operator[](int index) const{
    if(index<strlen(value->m_str))
    {
        return value->m_str[index];
    }
}
//对于非const string假定他一定会修改字符串,所以,复制一份,再进行操作
inline char& String::operator[](int index)
{
    if(value->ref>1)
    {
        --value->ref;
        value=new strbref(value->m_str);
    }
    if(index<strlen(value->m_str))
    {
        return value->m_str[index];
    }
}
inline int String::getlength ()
{
    return strlen(value->m_str);
}
inline int String::getref ()
{
    return value->ref;
}
inline std::istream& operator>> (std::istream& in,const String& str)
{
    in>>str.value->m_str;
    return in;
}
inline std::ostream& operator<< (std::ostream& os,const String& str)
{
    os<<str.value->m_str;
    return os;
}
#endif // !__String_h_
