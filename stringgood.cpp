/************************************************
 * @FileName:    stringgood.cpp
 * @Author:      Guohao.Chen
 * @Date:        2018.12.05
 * @Description: String class methods
************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "stringgood.h"
using std::cin;
using std::cout;

// initializing static class number
int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
// construct String from C string
String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;  
}
// default constructor
String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
// Copy String
String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}
// destructor
String::~String()
{
    --num_strings;
    delete [] str;
}


// overloaded operator methods
// assign a String to a String
String & String::operator=(const String & st)
{
    // 检查自我复制
    if(this == &st)
        return *this;
    // 等号两边不同时, 先释放接收对象this的str指向的内存
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-white char access for NON-const String
char & String::operator[](int i)
{
    return str[i];
}

// read-only char access for CONST String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
