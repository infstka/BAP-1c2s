#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;

//Ввести массивы А и В. В массив С перенести четные элементы массива А и нечетные элемента массива В. Массив С отсортировать по убыванию, используя алгоритмы сортировок: «пузырек», сортировка подсчетом. 

void shellsort(int x[], int n)         
{
	int i, j, k, increment, temp;
	int swp = 0, comp = 0; increment = n / 2;
	while (increment > 0)
	{
		for (i = 0; i < increment; i++)
		{
			for (j = 0; j < n; j += increment)
			{
				temp = x[j];
				for (k = j - increment; k >= 0 && temp < x[k]; k -= increment)
				{
					comp++;
					swp++;
					x[k + increment] = x[k];
				}
				x[k + increment] = temp;
				swp++;
			}
		}
		comp++;
		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
}

//------------------------------
int* sort1(int m[], int lm)
{
	int buf;
	for (int i = 0; i < lm; i++)
		for (int j = 0; j < lm - i - 1; j++)
			if (m[j] > m[j + 1])
			{
				buf = m[j];
				m[j] = m[j + 1];
				m[j + 1] = buf;
			}
	return m;
}
//------------------------------
int* sort2(int m[], int lm[], int size)
{
	int i, j, count;
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j)
			if (m[j] < m[i] || (m[j] == m[i] && i < j))
				count++;
		lm[count] = m[i];
	}
	return 0;
}

void selectSort(int A[], int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
}

//------------------------------
int getRandKey(int reg = 0)     // генерация случайных ключей
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 100000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}
//------------------------------

int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 30000;
	int fCount = 0;
	int k[N*2], f[N * 2], A[N], B[N];
	clock_t  t1, t2;
	getRandKey(1);
	for (int i = 0; i < N; i++) {
		A[i] = getRandKey(0);
		if (A[i] % 2 == 0) {
			f[fCount] = A[i];
			fCount++;
		}
		B[i] = getRandKey(0);
		if (B[i] % 2 == 1) {
			f[fCount] = B[i];
			fCount++;
		}
	}
		
	for (int n = 10000; n <= N; n += 10000)
	{
		cout << "n = " << n << endl;
		cout << "Сортировка пузырьком " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort1(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "Сортировка подсчетом " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort2(f, k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl << endl;
		/*cout << "Сортировка Выбором " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		selectSort(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "Сортировка Шелла " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		shellsort(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;*/
	}
	return 0;

}
