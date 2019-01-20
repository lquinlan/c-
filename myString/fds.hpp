#ifndef __mystring_h__
#define __mystring_h__
#include<iostream>
#include<cstring>
using namespace std;
class String{
    public :
        String (const char *str=NULL);
        String (const String& str);
        String& operator= (const String& str);
        ~String();
         char* get_str () const
		{
			return my_str;
		}
    private:
        char *my_str;
};
String::String (const char *str)
{
    if(str)
    {
        my_str=new char[strlen(str)+1];
        strcpy(my_str,str);
    }
    else
    {
        my_str=new char[1];
        *my_str='\0';
    }
}
inline String::~String ()
{
    delete[] my_str;
}
inline String::String (const String& str)
{
    my_str=new char[strlen(str.my_str)+1];
    strcpy(my_str,str.my_str);
}
inline String& String::operator= (const String& str)
{
    if(this==&str)
        return *this;
    delete[] my_str;
    my_str=new char[strlen(str.my_str)+1];
    strcpy(my_str,str.my_str);

}
#endif
