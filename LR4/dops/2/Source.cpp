#include <iostream>
#include<string>
#include<windows.h>
int i = 0;
using namespace std;

//2. ������� ��������� � ������ TRAIN, ���������� ����
//: �������� ������ ����������, ����� ������, ����� �����������.�������� ���������, 
//����������� ���� � ���������� ������ � ������, ��������� �� ������ ��������� ���� TRAIN(������ ������ 
//���� ��������� � ���������� ������� �� ��������� ������� ����������); ����� �� ����� ���������� � �������,
//�������������� ����� ���������� � ���������� �������(���� ����� ������� ���, �� ������� �� - ������� �� ����
struct traininfo {
	char place[80];
	int numbertrain;
	int hours;
	int minute;
};

traininfo train[8];
void line()
{
	cout << "<-------------------------------->" << endl;
}
void feeling()
{
	cin.clear();
	while (cin.get() != '\n');
	cout << "������� ����� ���������� : ";
	gets_s(train[i].place);
	cout << endl << "������� ����� ������ : ";
	cin >> train[i].numbertrain;
	cout << "������� ����� � ������� ��:�� : ";
	cin >> train[i].hours; cin.get();
	cin >> train[i].minute;
	//�������� �� ������������� �������
	if (train[i].hours <= 24 && train[i].hours >= 0)
	{
		if (train[i].minute < 60 && train[i].minute >= 0)
		{

		}
		else {
			goto x;
		}
	}
	else {
	x:		cout << "������������ ����, ��������� ������� ������ !" << endl;
		feeling();
	}
	line();
}

void sort()
{
	for (int i = 0; i < 7; i++)
		for (int j = i + 1; j < 8; j++) {
			if (strcmp(train[i].place, train[j].place) > 0)
			{
				swap(train[i].place, train[j].place);
				swap(train[i].numbertrain, train[j].numbertrain);
				swap(train[i].hours, train[j].hours);
				swap(train[i].minute, train[j].minute);
			}
		}
	cout << "<<���������� ���������!>>" << endl;
}
void conclusion()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "����� ���������� : " << train[i].place << endl;
		cout << "����� ������ : " << train[i].numbertrain << endl;
		cout << "����� ����������� : " << train[i].hours << ":" << train[i].minute << endl;
		line();
	}
	cout << endl;
}
void search()
{
	int h, m;
	cout << "������� ��������� ����� � ������� XX:XX : ";
	cin >> h; cin.get(); cin >> m;
	for (int i = 0; i < 8; i++)
	{
		if (train[i].hours >= h && train[i].minute >= m)
		{
			cout << "����� ���������� : " << train[i].place << endl;
			cout << "����� ������ : " << train[i].numbertrain << endl;
			cout << "����� ����������� : " << train[i].hours << ":" << train[i].minute << endl;
			line();
		}
	}
}
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise, j = 1;
	while (j == 1) {
		cout << "1-���� ��������� ��������� � ���������� \n2-��������� ���������� \n3-������� �� ����� \n 4 - ����� ������� ����� ���������� �������" << endl;
		cout << ">>>>";
		cin >> choise;
		switch (choise)
		{
		case 1:
			if (i < 8)
			{
				feeling(); i++; line(); break;
			}
			else
			{
				cout << "���� ��������" << endl;
				break;
			}
			;
		case 2: sort(); break; line();
		case 3: conclusion(); line(); break;
		case 4: search(); line(); break;
		default:
			break;
		}
		cout << "������� ����������. 1 - �� , 2 - ��� ---> " << endl;
		cin >> j;
	}

}