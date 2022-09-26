#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
void task1();
void task2();
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "rus");
	int c;
	do
	{
		cout << endl;
		cout << "Введите" << endl;
		cout << "1-задание 1" << endl;
		cout << "2-задание 2" << endl;
		cout << "3-выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: break;
		}
	} while (c != 3);
}
void task1()
{
	int N1, N2;
	cout << "Введите промежуток N1 - N2 :";
	cin >> N1 >> N2;
	ifstream fin("FILE1.txt");
	ofstream fout("FILE2.txt");
	char str[100];
	int l = 1;
	while (fin.getline(str, 100)) 
	{
		if (l >= N1 && l <= N2) 
		{
			if (str[0] == 'C') { fout << str<<endl; }
		}
		l++;
	}
	fin.close();
	fout.close();
	ifstream fiin("FILE2.txt");
	fiin.getline(str, 100);
	l = 0;
	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[i] == ' ') { l++; }
	}
	
	cout << "Количество слов в первой строке FILE2 - " << l<<endl;
	fiin.close();
}
void task2()
{
	char str[100];
	if (cin.getline(str, 100)) { cin.getline(str, 100); }
	ofstream fout("file.txt");
	fout << str;
	fout.close();

	ifstream fin("file.txt");
	fin.getline(str, 100);
	fin.close();
	str[strlen(str)] = ' ';
	int l = 0;
	int left_side = 0;
	int right_side = 0;
	string s = "sukableatkurrrwa";
	int size = 1000;
	for (int i = 1; i < strlen(str); i++) 
	{
		if (str[i] == ' ') {
			right_side = i - 1;
			if (size > right_side - left_side + 1) 
			{
				s = "";
				for (int j = left_side; j <= right_side; j++) 
				{
					s += str[j];
				}
				size = right_side - left_side + 1;
			}
							}
		if (str[i - 1] == ' ') 
		{
			left_side = i;
		}
	}
	cout << "Самое короткое слово - " << s<<endl;
	cout << "Его длинна - " << size << endl;
}