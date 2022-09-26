#include <iostream>
#include<string>
#include<windows.h>
int i = 0;
using namespace std;

//2. Описать структуру с именем TRAIN, содержащую поля
//: названия пункта назначения, номер поезда, время отправления.Написать программу, 
//выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN(записи должны 
//быть размещены в алфавитном порядке по названиям пунктов назначения); вывод на экран информации о поездах,
//отправляющихся после введенного с клавиатуры времени(если таких поездов нет, то вывести со - общение об этом
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
	cout << "Введите пункт назначения : ";
	gets_s(train[i].place);
	cout << endl << "Введите номер поезда : ";
	cin >> train[i].numbertrain;
	cout << "Введите время в формате ХХ:ХХ : ";
	cin >> train[i].hours; cin.get();
	cin >> train[i].minute;
	//ПРОВЕРКА НА ДОСТОВЕРНОСТЬ ВРЕМЕНИ
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
	x:		cout << "Некорректный ввод, повторите попытку заново !" << endl;
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
	cout << "<<Сортировка выполнена!>>" << endl;
}
void conclusion()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "Пункт назначения : " << train[i].place << endl;
		cout << "Номер поезда : " << train[i].numbertrain << endl;
		cout << "Время отправления : " << train[i].hours << ":" << train[i].minute << endl;
		line();
	}
	cout << endl;
}
void search()
{
	int h, m;
	cout << "Введите указанное время в формате XX:XX : ";
	cin >> h; cin.get(); cin >> m;
	for (int i = 0; i < 8; i++)
	{
		if (train[i].hours >= h && train[i].minute >= m)
		{
			cout << "Пункт назначения : " << train[i].place << endl;
			cout << "Номер поезда : " << train[i].numbertrain << endl;
			cout << "Время отправления : " << train[i].hours << ":" << train[i].minute << endl;
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
		cout << "1-ввод элементов структуры с клавиатуры \n2-выполнить сортировку \n3-вывести на экран \n 4 - поиск поездов после указанного времени" << endl;
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
				cout << "Ввод завершен" << endl;
				break;
			}
			;
		case 2: sort(); break; line();
		case 3: conclusion(); line(); break;
		case 4: search(); line(); break;
		default:
			break;
		}
		cout << "Желаете продолжить. 1 - Да , 2 - Нет ---> " << endl;
		cin >> j;
	}

}