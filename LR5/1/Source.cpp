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
		cout << "������� ������\n";
		cout << "����� ����� " << i + 1 << endl;
		cout << "����� ������\n";
		cin >> arr[i].Numbertrain;
		cout << "������� ��� ����������\n";
		cout << "1)����������� 2)������� 3)����� 4)������� 5)������� 6)������� 7)�����������\n";
		cin >> d; arr[i].day = (day)d;
		cout << "������� ����� ����������� ( HH:MM ) : ";
		cin >> arr[i].hours; cin >> arr[i].min;
		cout << "������� ����� �������� (HH:MM ) : ";
		cin >> d; cin >> m; arr[i].date.hour = d; arr[i].date.min = m;
		cout << "������� ����� ����������\n";
		cout << "1)��� 2)������ 3)����� 4)�������� 5)������� 6)������\n";
		cin >> m;
		arr[i].punkt = (place)m;
		arr[i].trigger = 1;
	}

	cout << "���� � ����\n";
	cout << "__________________________________________\n\n";
	menu();
}
void menu() {

	int c;
	do
	{
		cout << "__________________________________________\n\n";
		cout << "��� ������ �������?\n";
		cout << "������� �� ������ ���������� - 1\n";
		cout << "������� ��� ������ - 2\n";
		cout << "������� ���� - 3\n";
		cout << "����� - 3\n";
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
			cout << "�� ����� ������." << endl;
			break;
		default:
			cout << "������ �����������, ��������� ����������." << endl;
			break;
			cout << "__________________________________________\n\n";
		}
	}
	while (c != 7);
}
void del()
{
	cout << "__________________��������____________________\n\n";
	int n;
	cout << "������� ����� ����� ������� ������ ������� : ";
	cin >> n;
	arr[n - 1].trigger = 0;
	cout << "���������� ���� ������\n" << endl;
	cout << "______________________________________________\n\n";
}
void out() {
	int num;
	cout << "������� ����� ����� �� 1 �� 3\n\n";
	cin >> num;
	for (int num = 0; num < 3; num++) {
		if (arr[num].trigger == 1) {

			cout << "_______________����� ������_______________\n\n";
			cout << "����� ������" << arr[num].Numbertrain << "\n����� �����������" << arr[num].hours << ":" << arr[num].min << " \n ����� �������� - " << arr[num].date.hour << ":" << arr[num].date.min << ":" << "\n";
			cout << "����� ���������� - "; country(arr[num].punkt);
			cout << "\n ���� ����������- "; data(arr[num].day);
		}
		else
			cout << "���������� ���� �������\n";
		cout << "__________________________________________\n\n";
	}
}
void find() {
	cout << "_______________������� �� ������ ���������_______________\n\n";
	cout << "������� ����� � ������� ����������� ���� (MM)\n";
	cout << "1)��� 2)������ 3)����� 4)�������� 5)������� 6)������\n";
	int minArea;
	cin >> minArea;
	for (int num = 0; num < 3; num++) {
		if (minArea == arr[num].punkt && arr[num].trigger == 1) {
			cout << "_______________����� ������_______________\n\n";
			cout << "����� ������" << arr[num].Numbertrain << "\n����� �����������" << arr[num].hours << ":" << arr[num].min << " \n ����� �������� - " << arr[num].date.hour << ":" << arr[num].date.min << ":" << "\n";
			cout << "����� ���������� - "; country(arr[num].punkt);
			cout << "\n ���� ����������- "; data(arr[num].day);
		}
	}
	menu();

}
void data(int y) {
	if (y == 1)
		cout << "�����������";
	if (y == 2)
		cout << "�������";
	if (y == 3)
		cout << "�����";
	if (y == 4)
		cout << "�������";
	if (y == 5)
		cout << "�������";
	if (y == 6)
		cout << "�������";
	if (y == 7)
		cout << "�����������";
}
void country(int y) {
	if (y == 1)
		cout << "���";
	if (y == 2)
		cout << "������";
	if (y == 3)
		cout << "�����";
	if (y == 4)
		cout << "��������";
	if (y == 5)
		cout << "�������";
	if (y == 6)
		cout << "������";

}