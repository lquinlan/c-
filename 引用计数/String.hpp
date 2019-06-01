/*
    ���ü�����c++���õ�һ�ָ�Ч���ڴ�����ʩ,Ҳ�Ǳ�׼����õ��ڴ�����ʩ;
    ����ί�����,�ڱ�����ֻ��ƽӿ�,����������,ʵ�ֹ���,������ָ�����,ͬʱ������
    ��һ�����ü���count,��¼�ж��ٸ���ͬ������,����һ���ڴ�,ֻ�е���Ҫ�޸�ʱ,�Ż�
    ����copy by writer,ʵʱ����,c++string ,���������ִ�ʩ.
    һ�������ֻ�п�������������ü���
    
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
    struct strbref//���ü���
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
        m_str=new char[1];//������ʽ�ϵ�һ��
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
    m_str=nullptr;//�ͷź�ֵΪnullptrʱ��ϰ��
}
inline String::String(const char* initvalue):value(new strbref(initvalue)){}
inline String::String(const String& str):value(str.value){//���ڿ�������ֻ��Ҫ���ü�1,��Ч����
    ++value->ref;
}
inline String& String::operator=(const String &str)
{
    if(this->value==str.value)//����Ƿ����Ҹ���,�������
    {
        return *this;
    }
    if(--value->ref==0)//�����ü�һ
    {
        delete value;
    }
    value=str.value;
    ++value->ref;//�����ü�һ
    return *this;
}
inline String::~String ()
{
    if(--value->ref==0)//��������Ϊ0ʱ�ͷŵ�
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
    //��Ϊ��
    if(str.value->m_str[0]=='\0')
    {
        value =new strbref(value->m_str);
        return *this;
    }
    //��Ϊ��
    if(value->m_str[0]=='\0')
    {
        value =new strbref(str.value->m_str);
        return *this;
    }
    //����Ϊ��
    char *tmp=new char[strlen(value->m_str)+strlen(str.value->m_str)+1];
    strcpy(tmp,value->m_str);
    strcat(tmp,str.value->m_str);
    value=new strbref(tmp);
    return *this;
}
inline String String::operator+(const String& str){
//��ʱ����,����+=ʵ�ֲ���,�򻯴���
	return String(*this) += str;

}
inline bool String::operator==(const String&str)
{
    return strcmp(value->m_str,str.value->m_str)==0?true:false;
}
//���const [],�ͷ�const [],������const string ,�ͷ�const string
inline const char& String::operator[](int index) const{
    if(index<strlen(value->m_str))
    {
        return value->m_str[index];
    }
}
//���ڷ�const string�ٶ���һ�����޸��ַ���,����,����һ��,�ٽ��в���
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
