#include <iostream>
#include <fstream>

using namespace std;

struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};


void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void lol(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	int k = 100000000; // минимальная переменная
	int y = 0; // номер минимальной переменной
	int q = 1; // подсчёт переменных
	while (e != NULL)
	{
		if (e->data <= k) {
			k = e->data;
			y = q;
		}
		q++;
		e = e->next;
	}
	q = q - y;
	cout << "Длина минимальной строки: " << k << endl;
	cout << "Номер этой строки: " << q;
	cout << endl;
}

void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	x = x - 1;
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

void proverka(Stack* myStk) {
	ifstream frm("Steck.txt", ios_base::in);
	if (!frm.is_open()) {
		cout << "Ошибка открытия";
	}
	else {
		int l;
		while (!frm.eof()) {
			char low[50];
			frm.getline(low, 50);
			l = strlen(low);
			push(l, myStk);
		}
	}
}

void vvod() {
	setlocale(LC_ALL, "Russian");
	ofstream frm("Steck.txt");
	if (!frm.is_open()) {
		cout << "Ошибка открытия";
	}
	else {
		frm << "Привет как дела?\r\nнормально\r\nА у тебя\r\nспасибо\r\nхорошo ";
		frm.close();
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;
	for (;;) {
		cout << "\nВыберите команду:" << endl;
		cout << "1 - Ввод строк в файл" << endl;
		cout << "2 - Ввод длин строк из файла в стек " << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Поиск самой короткой строки и её номера" << endl;
		cout << "5 - Выход" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			vvod();
			break;
		case 2:
			proverka(myStk);
			break;
		case 3: cout << "\nВесь стек: " << endl;
			show(myStk);
			break;
		case 4:
			lol(myStk);
			break;
		case 5: return 0;
			break;
		}
	}
}