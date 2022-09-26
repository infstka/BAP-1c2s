#include <iostream>

using namespace std;

float f(float x);

float dicho(float a, float b, float e, float x);

void main()
{
	float x, a, b, e;
	setlocale(LC_ALL, "ru");
	cout << "Введите a" << endl;
	cin >> a;
	cout << endl;
	cout << "Введите b" << endl;
	cin >> b;
	cout << endl;
	cout << "Введите e" << endl;
	cin >> e;
	cout << endl;
	if ((f(a) * f(b)) < 0)
	{
		cout << "Ответ:" << dicho(a, b, e, 0);
	}
	else
	{
		cout << "Условие не подходит" << endl;
	}
}

float f(float x)
{
	return (5 * x + 3);
}

float dicho(float a, float b, float e, float x)
{
	x = (a + b) / 2;
	if (abs(f(x)) < e)
	{
		return x;
	}
	else
	{
		if (f(a) * f(x) < 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}

		return dicho(a, b, e, x);
	}
}
