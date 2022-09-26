#include<stdio.h>
#include<algorithm>
#include<iostream>
int task1();
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


int task1() {
	FILE* f;
	FILE* f1;
	errno_t err;
	err = fopen_s(&f, "fileA.txt", "r");
	if (err != NULL)//Проверка открытия файла
	{
		printf("Ошибка открытия файла\n"); return -1;
	}

	fopen_s(&f1, "fileB.txt", "w");
	int n;
	int a[100];//массив, в который поместим данные из файла для дальнейшей работы с ними

	fscanf_s(f, "%d", &n);//кол-во элементов

	for (int i = 0; i < n; i++)
	{
		fscanf_s(f, "%d", &a[i]);//выводим данные из файла в массив
	}
	sort(a, a + n);//без сортировки будет работать неправильно

	int l = 1;//счетчик одинаковых чисел

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1]) { l++; }
		else { fprintf_s(f1, "%d ", a[i]); }//подсчет количества одинаковых элементов в отсортированном массиве
		//и запись всего одного числа
	}
fprintf_s(f1, "%d ", a[n - 1]);//проверка для последних элементов
	printf("Данные записаны в файл fileB.txt\n");
	fclose(f);
	fclose(f1);
	return 0;
}

void task2() {
	FILE* F1, * F2;
	char str[100];
	fopen_s(&F1, "F1.txt", "w");
	for (int i = 1; i <= 4; i++) {
		cout << "Введите строку номер " << i << ":";
		cin >> str;//вводим строки
		fputs(str, F1); fputs("\n", F1);//помещаем строки в файл
	}
	fclose(F1);
	int n;
	cout << "Введите число n : ";
	cin >> n;

	fopen_s(&F1, "F1.txt", "r");//для чтения
	fopen_s(&F2, "F2.txt", "w");//для записи
	for (int i = 0; i < 4; i++) {
		fgets(str, sizeof(str), F1);//выводим строку в массив
		if (strlen(str) - 1 > n) { fputs(str, F2); }//сравниваем размер строки с количеством n, записываем строку во второй файл
	}
	printf("Данные записаны в файл F2.\n");
	fclose(F1);
	fclose(F2);
}