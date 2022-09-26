#include <iostream>
#include <fstream>
void menu(), out(), del(), find(), country(int), data(int);
using namespace std;
struct date
{
	unsigned hour : 5;	//				| 31    11111
	unsigned min : 5;
};

enum place {
	Am = 1, Ru, Kz, Bl, Kr, Tt
};
enum day {
	pn = 1, vt, sr, cht, pyat, sub, voskr
};
struct train
{
	int Numbertrain;
	day day;
	int hours;
	int min;
	date date;
	place punkt;
	int trigger;
};
struct train arr[3];
int main(void) {
	setlocale(LC_ALL, "RUS");
	for (int i = 0; i < 3; i++) {
		int d, m;
		cout << "__________________________________________\n\n";
		cout << "Введите данные\n";
		cout << "Номер рейса " << i + 1 << endl;
		cout << "Номер поезда\n";
		cin >> arr[i].Numbertrain;
		cout << "Введите дни следования\n";
		cout << "1)Понедельник 2)Вторник 3)Среда 4)Четверг 5)Пятница 6)Суббота 7)Воскресенье\n";
		cin >> d; arr[i].day = (day)d;
		cout << "Введите время отправления ( HH:MM ) : ";
		cin >> arr[i].hours; cin >> arr[i].min;
		cout << "Введите время прибытия (HH:MM ) : ";
		cin >> d; cin >> m; arr[i].date.hour = d; arr[i].date.min = m;
		cout << "Введите пункт назначения\n";
		cout << "1)США 2)Россия 3)Литва 4)Беларусь 5)Украина 6)Польша\n";
		cin >> m;
		arr[i].punkt = (place)m;
		arr[i].trigger = 1;
	}

	cout << "Вход в меню\n";
	cout << "__________________________________________\n\n";
	menu();
}
void menu() {

	int c;
	do
	{
		cout << "__________________________________________\n\n";
		cout << "Что хотите сделать?\n";
		cout << "Выборка по пункту назначения - 1\n";
		cout << "Вывести все данные - 2\n";
		cout << "Удалить рейс - 3\n";
		cout << "Выход - 3\n";
		cin >> c;
		switch (c)
		{
		case 1:
			find();
			break;
		case 2:
			out();
			break;
		case 3:
			del();
			break;
		case 4:
			cout << "До новых встреч." << endl;
			break;
		default:
			cout << "Запрос неккоректен, повторите пожалуйста." << endl;
			break;
			cout << "__________________________________________\n\n";
		}
	}
	while (c != 7);
}
void del()
{
	cout << "__________________УДАЛЕНИЕ____________________\n\n";
	int n;
	cout << "Введите номер рейса который хотите удалить : ";
	cin >> n;
	arr[n - 1].trigger = 0;
	cout << "Информация была удалёна\n" << endl;
	cout << "______________________________________________\n\n";
}
void out() {
	int num;
	cout << "Введите номер рейса от 1 до 3\n\n";
	cin >> num;
	for (int num = 0; num < 3; num++) {
		if (arr[num].trigger == 1) {

			cout << "_______________ВЫВОД ДАННЫХ_______________\n\n";
			cout << "Номер поезда" << arr[num].Numbertrain << "\nВремя отправления" << arr[num].hours << ":" << arr[num].min << " \n Время прибытия - " << arr[num].date.hour << ":" << arr[num].date.min << ":" << "\n";
			cout << "Пункт назначения - "; country(arr[num].punkt);
			cout << "\n день следования- "; data(arr[num].day);
		}
		else
			cout << "Информация была удалена\n";
		cout << "__________________________________________\n\n";
	}
}
void find() {
	cout << "_______________ВЫБОРКА ПО ПУНКТУ НАЗНАЧЕНИ_______________\n\n";
	cout << "Введите пункт в который планируется рейс (MM)\n";
	cout << "1)США 2)Россия 3)Литва 4)Беларусь 5)Украина 6)Польша\n";
	int minArea;
	cin >> minArea;
	for (int num = 0; num < 3; num++) {
		if (minArea == arr[num].punkt && arr[num].trigger == 1) {
			cout << "_______________ВЫВОД ДАННЫХ_______________\n\n";
			cout << "Номер поезда" << arr[num].Numbertrain << "\nВремя отправления" << arr[num].hours << ":" << arr[num].min << " \n Время прибытия - " << arr[num].date.hour << ":" << arr[num].date.min << ":" << "\n";
			cout << "Пункт назначения - "; country(arr[num].punkt);
			cout << "\n день следования- "; data(arr[num].day);
		}
	}
	menu();

}
void data(int y) {
	if (y == 1)
		cout << "Понедельник";
	if (y == 2)
		cout << "Вторник";
	if (y == 3)
		cout << "Среда";
	if (y == 4)
		cout << "Четверг";
	if (y == 5)
		cout << "Пятница";
	if (y == 6)
		cout << "Суббота";
	if (y == 7)
		cout << "Воскресенье";
}
void country(int y) {
	if (y == 1)
		cout << "США";
	if (y == 2)
		cout << "Россия";
	if (y == 3)
		cout << "Литва";
	if (y == 4)
		cout << "Беларусь";
	if (y == 5)
		cout << "Украина";
	if (y == 6)
		cout << "Польша";

}