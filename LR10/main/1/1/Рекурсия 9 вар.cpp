#include <iostream>

using namespace std;

int plusInts(int a, int b);
int minusInts(int a, int b);
int multi(int a, int b);
int power(int a, int b);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	short choice = 0;
	int first = 0, second = 0;
	while (choice != 6)
	{
		cout << "Меню" << endl;
		cout << "1 - Ввести числа" << endl;
		cout << "2 - Сумма чисел" << endl;
		cout << "3 - Разность чисел" << endl;
		cout << "4 - Произведение чисел" << endl;
		cout << "5 - Возведение в степень" << endl;
		cout << "6 - Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Первое число: "; cin >> first;
			cout << "Второе число: "; cin >> second;
			break;
		}
		case 2: {
			cout << "Сумма чисел: " << plusInts(first, second) << endl;
			break;
		}
		case 3: {
			cout << "Разность чисел: " << minusInts(first, second) << endl;
			break;
		}
		case 4: {
			cout << "Произведение чисел: " << multi(first, second) << endl;
			break;
		}
		case 5: {
			cout << "Число а в степени b : " << power(first, second) << endl;
			break;
		}
		case 6: {
			exit(-1); break;
		}
		}
	}
}

int plusInts(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else {
		plusInts(++a, --b);
	}
}

int minusInts(int a, int b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else {
		minusInts(--a, --b);
	}
}

// здесь трабл, ибо например а=5 и b=3, через | показаны шаги
int multi(int a, int b)
{
	if (b == 0 || b == 1)
	{
		return a;
	}
	else {
		--b; // b = 2 | b = 1 
		a = plusInts(a, a); // a = 10 | a = 20
		multi(a, b); // пушта сюда передастся 10, вместо 5
	}
}

int power(int a, int b)
{
	if (b == 0) {
		return 1;
	}
	else if (b == 1)
	{
		return a;
	}
	else {
		--b;
		multi(a, a);
	}
}