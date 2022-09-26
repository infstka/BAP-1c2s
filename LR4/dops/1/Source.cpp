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
	cout << "Введите ФИО студента : ";
	getline(cin, person[i].nameinfo);
	cout << "Введите количество экзаменов : ";
	cin >> person[i].numberofexams;
	cout << "Оценки за экзамены : " << endl;
	for (int j = 0; j < person[i].numberofexams; j++)
	{
		cout << "Оценка №" << j + 1 << " :";
		cin >> person[i].ratings[j];
	}

}
void line() {
	cout << "<<<--------------------------->>>" << endl;
}
void conclusion() {
	int n;
	string fixed;
	cout << "Вывести данные об отдельном студенте - 1 , 2 - вся информация >>";
	cin >> n;
	switch (n)
	{
	case 1:
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ФИО студента : ";
		getline(cin, fixed);
		for (int j = 0; j < i; j++)
		{
			if (fixed == person[j].nameinfo)
			{
				line();
				cout << "ФИО : " << person[j].nameinfo << endl;
				cout << "Количество экзаменов : " << person[j].numberofexams << endl;
				cout << "Оценки за экзамены : ";
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
			cout << "ФИО : " << person[j].nameinfo << endl;
			cout << "Количество экзаменов : " << person[j].numberofexams << endl;
			cout << "Оценки за экзамены : ";
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
	cout << "Введите ФИО студента : ";
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
						cout << " Данный студент преуспевает в учебе" << endl;
						line();
						break;
					}

				}
				else {
					if (k1 == 0) {
						cout << "Данный студент не преуспевает в учебе" << endl;
						k1++;
					}
				}
			}

		}

	}

}
void characteristic() {
	int h = 0;
	int h1 = 0;//подсчет преуспевающих студентовы
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < person[j].numberofexams; k++)
		{
			if (person[j].ratings[k] == 5 || person[j].ratings[k] == 4)
			{
				h++;
				if (h == person[j].numberofexams)
				{
					h1++;	//преуспевающие студенты
				}

			}
			else {
				//не преуспевающие студенты
			}

		}
		h = 0;
	}
	double  x = (double)h1;
	double y = (double)i;
	cout << "Характеристика успеваемости студентов = [" << ((x / y) * 100) << "%]" << endl;




}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int j = 1;
	int choise;
	while (j == 1) {
		cout << "1 - ввод данных \n 2 - вывод данных \n 3 - проверка на отличную сдачу экзаменов \n 4 - вычисление характеристики >> ";
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
		cout << "Желаете продолжить , 1 - да , 2 - нет ";
		cin >> j;
	}

}
