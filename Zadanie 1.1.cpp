// 2 вариант
#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int Num(char a[30]) {
	int number;
	number = abs(static_cast<int>(a[0])) % 2 + 1;
	return number;
}

int main()
{
	cout << "Enter your surname: ";
	char dlinafamilii[15];//длина фамилии
	cin >> dlinafamilii;
	cout << Num(dlinafamilii)<<endl;
}