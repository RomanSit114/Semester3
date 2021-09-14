#include <iostream>
#include <Windows.h> 
#include <string.h>
#include <stdlib.h>
using namespace std;
int const M = 40;
class FooString
{
private:
    char* fb;
public:
    FooString();
    ~FooString();
    void show();
    int length();
    int testInput();
    void testData();
};
FooString::FooString()
{
 fb = new char[M];
    testData();
}
FooString::~FooString()
{
    delete[]fb;
}
void FooString::testData()
{
cout << "Enter your line: ";
cin.getline(fb, M);
}
void FooString::show()
{
    int l = length();
    cout << "Array size: " << l << endl;
    for (int i = 0; i < l; i++)
        cout << fb[i];
}
int FooString::length()
{
int i = 0;
    while (true)
    {
     if (fb[i] == '\0')
     break;
     else
     i++;
    }
    i++;
    return i;
}
int FooString::testInput()
{
    if (cin.fail())
    {
     cin.clear();
     cin.ignore(32767, '\n');
     cout << "Error" << endl;
     return -1;
    }
}
int main()
{
    FooString mas;
    if (mas.testInput() == -1)
    return -1;
    mas.show();
}