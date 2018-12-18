/************************************************
 * @FileName:    sayings2.cpp
 * @Author:      Guohao.Chen
 * @Date:        2018.12.18
 * @Description: using pointers to objects
 * 使用指向对象的指针，
************************************************/
#include <iostream>
#include "stringgood.h"
#include <cstdlib>
#include <ctime>

const int ArSize = 10;
const int MaxLen = 81;

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];

    // temporary string storage
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
        {
            break;
        }
        else
        {
            sayings[i] = temp; // 重载赋值 String = C string
        }
    }
    int total = i;

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
        {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }

        // 使用指向对象的指针去寻找最短和最前的字符串
        String * shortest = &sayings[0];
        String * first = &sayings[0];

        for (int i = 0; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
            {
                shortest = &sayings[i];
            }
            if (sayings[i] < *first)
            {
                first = &sayings[i];
            }
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;

        // 使用new去初始化一个String对象
        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;
    }
    else
    {
        cout << "No input! Bye.\n";
    }
    return 0;
}