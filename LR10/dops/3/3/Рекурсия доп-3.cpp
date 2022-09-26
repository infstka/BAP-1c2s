#include<iostream>
#include<string.h>
using namespace std;
char c[50] = {};
int tr[50] = {};
int count = 0;
void perebor(string s, int count) 
{
	if (count == strlen(c)) { cout << s << endl; return; }
	for (int i = 0; i < strlen(c); i++) 
	{
		if (!tr[i]) {
			count++;
			string safe = s;
			s += c[i];
			tr[i] = 1;
			perebor(s, count);
			//возврат в исходные данные
			count--;
			s = safe;
			tr[i] = 0;
		}
	}
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	for (int i = 0; i < 5; i++) {
		cout << "Введите число : ";
		cin >> c;
		cout << "Все перестановки : " << endl;
		perebor("", 0);
	}
}