#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;
int i = 0;

struct Student {
	string nameinfo;
	int numberofexams;
	int ratings[10];
};
Student person[100];
void feeling() {
	cin.clear();
	while (cin.get() != '\n');
	cout << "������� ��� �������� : ";
	getline(cin, person[i].nameinfo);
	cout << "������� ���������� ��������� : ";
	cin >> person[i].numberofexams;
	cout << "������ �� �������� : " << endl;
	for (int j = 0; j < person[i].numberofexams; j++)
	{
		cout << "������ �" << j + 1 << " :";
		cin >> person[i].ratings[j];
	}

}
void line() {
	cout << "<<<--------------------------->>>" << endl;
}
void conclusion() {
	int n;
	string fixed;
	cout << "������� ������ �� ��������� �������� - 1 , 2 - ��� ���������� >>";
	cin >> n;
	switch (n)
	{
	case 1:
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ��� �������� : ";
		getline(cin, fixed);
		for (int j = 0; j < i; j++)
		{
			if (fixed == person[j].nameinfo)
			{
				line();
				cout << "��� : " << person[j].nameinfo << endl;
				cout << "���������� ��������� : " << person[j].numberofexams << endl;
				cout << "������ �� �������� : ";
				for (int k = 0; k < person[j].numberofexams; k++)
				{
					cout << person[j].ratings[k] << " ";
				}
				cout << endl;
				line();
			}
		}
		break;
	case 2:
		for (int j = 0; j < i; j++)
		{
			line();
			cout << "��� : " << person[j].nameinfo << endl;
			cout << "���������� ��������� : " << person[j].numberofexams << endl;
			cout << "������ �� �������� : ";
			for (int k = 0; k < person[j].numberofexams; k++)
			{
				cout << person[j].ratings[k] << " ";
			}
			line();
		}
		break;
	default:
		break;
	}


}
void checked() {
	string fixed;
	int h = 0, k1 = 0;
	cin.clear();
	while (cin.get() != '\n');
	cout << "������� ��� �������� : ";
	getline(cin, fixed);
	for (int j = 0; j < i; j++)
	{
		if (fixed == person[j].nameinfo)
		{
			for (int k = 0; k < person[j].numberofexams; k++)
			{
				if (person[j].ratings[k] == 5 || person[j].ratings[k] == 4)
				{
					h++;
					if (h == person[j].numberofexams)
					{
						cout << " ������ ������� ����������� � �����" << endl;
						line();
						break;
					}

				}
				else {
					if (k1 == 0) {
						cout << "������ ������� �� ����������� � �����" << endl;
						k1++;
					}
				}
			}

		}

	}

}
void characteristic() {
	int h = 0;
	int h1 = 0;//������� ������������� ����������
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < person[j].numberofexams; k++)
		{
			if (person[j].ratings[k] == 5 || person[j].ratings[k] == 4)
			{
				h++;
				if (h == person[j].numberofexams)
				{
					h1++;	//������������� ��������
				}

			}
			else {
				//�� ������������� ��������
			}

		}
		h = 0;
	}
	double  x = (double)h1;
	double y = (double)i;
	cout << "�������������� ������������ ��������� = [" << ((x / y) * 100) << "%]" << endl;




}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int j = 1;
	int choise;
	while (j == 1) {
		cout << "1 - ���� ������ \n 2 - ����� ������ \n 3 - �������� �� �������� ����� ��������� \n 4 - ���������� �������������� >> ";
		cin >> choise;
		switch (choise)
		{
		case 1:feeling(); i++; break;
		case 2:conclusion(); break;
		case 3:checked(); break;
		case 4:characteristic(); break;
		default:
			break;
		}
		cout << "������� ���������� , 1 - �� , 2 - ��� ";
		cin >> j;
	}

}
