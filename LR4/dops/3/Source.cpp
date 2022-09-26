#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;
int i = 0;
struct sanatorium_info {
	char name[20];
	char place[40];
	string medical_profile;
	int numberofinvited;

};
sanatorium_info hospital[10];
void line()
{
	cout << "<<<-------------------->>>" << endl;
}
void feeling()
{
	cin.clear();
	while (cin.get() != '\n');
	cout << "Введите название санатория : ";
	gets_s(hospital[i].name);
	cout << "Введите его месторасположение : ";
	gets_s(hospital[i].place);
	cout << "Введите лечебный профиль : ";
	getline(cin, hospital[i].medical_profile);
	cout << "Введите количество путевок : ";
	cin >> hospital[i].numberofinvited;
}
void conclusion_table() {
	string a;
	int c = 1;
	cin.clear();
	while (cin.get() != '\n');
	cout << "Введите лечебный профиль >>";
	getline(cin, a);
	for (int j = 0; j < 10; j++)
	{
		if (a == hospital[j].medical_profile)
		{
			if (c == 1)
			{
				cout << "Лечебный профиль : " << hospital[i].medical_profile << endl;
				cout << "| Название |\t" << "| Местораположение |\t" << "| Количество путевок |\t " << endl;
				c++;
			}
			cout << "|" << hospital[j].name << "\t " << hospital[j].place << " \t " << " \t \t \t " << hospital[j].numberofinvited << endl;


		}
	}
}


void search() {
	string name;
	cin.clear();
	while (cin.get() != '\n');
	cout << "Введите название санатория : ";
	getline(cin, name);
	for (int j = 0; j < 10; j++)
	{
		if (name == hospital[j].name)
		{
			cout << "Название : " << hospital[j].name << endl;
			cout << "Месторасположение :" << hospital[j].place << endl;
			cout << "Лечебный профиль : " << hospital[j].medical_profile << endl;
			cout << "Количество путевок : " << hospital[j].numberofinvited << endl;

		}
	}
}
void sort()
{

	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(hospital[i].name, hospital[j].name) > 0)
			{
				swap(hospital[i].name, hospital[j].name);
				swap(hospital[i].medical_profile, hospital[j].medical_profile);
				swap(hospital[i].place, hospital[j].place);
				swap(hospital[i].numberofinvited, hospital[j].numberofinvited);
			}
		}
	cout << "<<Сортировка выполнена!>>" << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choise, j = 1;
	while (j == 1) {
		cout << "1-ВВОД ЭЛЕМЕНТОВ С КЛАВИАТУРЫ \n2-ИНФОРМАЦИЯ В ВИДЕ ТАБЛИЦЫ(ПО ЛЕЧЕБНЫМ ПРОФИЛЯМ) \n3-ВЫПОЛНИТЬ СОРТИРОВКУ \n 4 - ПОИСК" << endl;
		cout << ">>>>";
		cin >> choise;
		switch (choise)
		{
		case 1:
			if (i < 10)
			{
				feeling(); i++; line(); break;
			}
			else
			{
				cout << "Ввод завершен" << endl;
				break;
			}
			;
		case 2: conclusion_table(); break;
		case 3:sort(); break;
		case 4:search(); break;
		default:
			break;
		}
		cout << "Желаете продолжить. 1 - Да , 2 - Нет ---> " << endl;
		cin >> j;
	}

}