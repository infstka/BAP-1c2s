#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;

void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}


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


void insOrd(int m[], int sm, int em, int e)
{ 
	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
int* sortMerge(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		sortMerge(m, lm / 2, sm);
		sortMerge(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}

void swapEl(int* arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}
void myShakerSort(int* arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;
	}
}



int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 30000;
	int fCount = 0;
	int k[N], f[N], A[N], B[N];
	clock_t  t1, t2;
	getRandKey(1);
	for (int i = 0; i < N; i++){
		f[i] = getRandKey(0);
	}

	for (int n = 10000; n <= N; n += 10000)
	{
		cout << "n = " << n << endl;
		cout << "Сортировка Шейкерная " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		myShakerSort(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		
		cout << "Сортировка слиянием " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sortMerge(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;

		cout << "Сортировка Хоара " << endl;
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		shellsort(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
	}
	return 0;

}
