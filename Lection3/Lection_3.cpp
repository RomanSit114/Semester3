#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
class Send1
{
public:virtual void send(char* z, int len) {};
};
class Send2 :public Send1
{
public:
	void send(char* z, int x)
	{
		for (int i = 0; i < x && z[i] != '\0'; i++)
		{
		bitset<8> x(z[i]);
		cout << x << ' ';
		}
	}
};
class Send3 :public Send1
{
public:
	void send(char* z, int x)
	{
	for (int i = 0; z[i] != '\0'; i++)
	cout << "0x" << hex << (int)(z[i] & 0xff) << ' ';
	}
};
void sendAll(Send1** a, int protocols_num)
{
	char strng[50];
	cout << "Enter string" << "\n";
	cin >> strng;
	for (int i = 0; i < protocols_num; i++)
	{
	cout << "Line " << i + 1 << ": ";
	a[i]->send(strng, 50);
	cout << endl;
	}
}
void Zadanie()
{
	string text = "task3.txt", line;
	vector <string> protocols;
	fstream file;
	file.open(text);
	while (file >> line)
	{
	protocols.push_back(line);
	}
	file.close();
	Send1** a = new Send1 * [protocols.size()];
	for (int i = 0; i < protocols.size(); i++)
	{
	if (protocols[i] == "Send3")
		{
	a[i] = new Send3;
		}
	else if (protocols[i] == "Send2")
		{
	a[i] = new Send2;
		}
	else
		{
	cout << "Error";
	exit(0);
		}
	}
	sendAll(a, protocols.size());
	delete[] a;
}
int main()
{
	Zadanie();
}