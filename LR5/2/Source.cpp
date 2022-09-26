#include<iostream>
#include<stdio.h>
using namespace std;
#define size  10
struct date
{
	unsigned day : 5;	//				| 31    11111
	unsigned month : 4;	//	������� ����| 12    1100
	unsigned year : 12;	//				| 2100	100000110100
};
union unic
{
	int var;
	char str[50];
	char sign;
} var;
struct people
{
	char fname[50];
	char sname[50];
	char lname[50];
	char clasc[50];
	int mark1;
	int mark2;
	int mark3;
	int mark4;
	int Srmark;
	date date;
	bool trigger = 0;
}arr[size];
void menu();//+
void show_all();//+
void add_men();//+
void search_of_post();//+
void main()
{
	setlocale(LC_CTYPE, "Russian");
	menu();
}
void add_men()
{
	cout << "<-------------------ENTER------------------------>" << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].trigger == 0) {
			cout << "������� ��� ������� : ";
			cin >> var.str;
			strcpy_s(arr[i].fname, var.str);
			cin >> var.str;
			strcpy_s(arr[i].sname, var.str);
			cin >> var.str;
			strcpy_s(arr[i].lname, var.str);
			cout << "������� ������ 1: ";
			cin >> var.var;
			arr[i].mark1 = var.var;
			cout << "������� ������ 2: ";
			cin >> var.var;
			arr[i].mark2 = var.var;
			cout << "������� ������ 3: ";
			cin >> var.var;
			arr[i].mark3 = var.var;
			cout << "������� ������ 4: ";
			cin >> var.var;
			arr[i].mark4 = var.var;
			cout << "������� ���� \n";
			arr[i].Srmark = (arr[i].mark1 + arr[i].mark2 + arr[i].mark3 + arr[i].mark4);
			cout << "������� ����� : ";
			cin >> var.str;
			strcpy_s(arr[i].clasc
				, var.str);
			cout << "������� ���� �������� ( DD:MM:YYYY ) : ";
			cin >> var.var;
			arr[i].date.day = var.var;
			cin >> var.sign;
			cin >> var.var;
			arr[i].date.month = var.var;
			cin >> var.sign;
			cin >> var.var;
			arr[i].date.year = var.var;
			arr[i].trigger = 1;
			break;
		}
	}
	cout << "<------------------------------------------------>" << endl;
}



////////////////////////////
void menu()
{
	int c;
	do
	{
		cout << "��� ������ �������?\n";
		cout << "�������� ������ ������� - 1\n";
		cout << "������� ����  - 2\n";
		cout << "������� �� �������- 3\n";
		cout << "��������� ������ - 4\n";
		cin >> c;
		switch (c)
		{
		case 1:
			add_men();
			break;
		case 2:
			show_all();
			break;
		case 3:
			search_of_post();
			break;
		case 4:
			cout << "�� ����� ������." << endl;
			break;
		default:
			cout << "������ �����������, ��������� ����������." << endl;
			break;
		}

	}

	while (c != 4);

}
//////////////////////////
void show_all()
{
	int count = 0;
	cout << "<-------------------SHOW ALL---------------------->" << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].trigger == 1) {
			count++;
			cout << "������ ����� - " << count << '.' << endl;
			cout << "���: " << arr[i].fname << ' ' << arr[i].sname << ' ' << arr[i].lname << endl;
			cout << "������ " << arr[i].mark1 << ' ' << arr[i].mark2 << ' ' << arr[i].mark3 << endl << arr[i].mark3 << endl;
			cout << "������� ���� " << arr[i].Srmark << endl;
			cout << "���� �������� : " << arr[i].date.day << ':' << arr[i].date.month << ':' << arr[i].date.year << endl;
		}

	}
	if (count == 0) { cout << "� ������ �������� �� ����������." << endl; };
	cout << "<------------------------------------------------>" << endl;
}
////////////////////////
void search_of_post()
{
	cout << "<-----------------SEARCH MEN--------------------->" << endl;
	int trigger = 0;
	int fac;
	cout << "������� ������� : ";
	cin >> var.str;
	for (int i = 0; i < size; i++)
	{
		if (strlen(var.str) == strlen(arr[i].fname))
		{
			int counter = 0;
			for (int j = 0; j < strlen(var.str); j++)
			{
				if (arr[i].fname[j] == var.str[j])
				{
					counter++;
				}
			}
			if (counter == strlen(var.str))
			{
				trigger = 1;
				cout << "���: " << arr[i].fname << ' ' << arr[i].sname << ' ' << arr[i].lname << endl;
				cout << "������ " << arr[i].mark1 << ' ' << arr[i].mark2 << ' ' << arr[i].mark3 << endl << arr[i].mark3 << endl;
				cout << "������� ���� " << arr[i].Srmark << endl;
				cout << "���� �������� : " << arr[i].date.day << ':' << arr[i].date.month << ':' << arr[i].date.year << endl;
			}
		}
	}
	if (trigger == 0) { cout << "������� � ����� �������� ���������� �� ����." << endl; }

	cout << "<------------------------------------------------>" << endl;
}
