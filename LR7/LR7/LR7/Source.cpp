#include<iostream>
#include<fstream>
using namespace std;
struct stack
{
	int value;
	stack* next;
};
stack* head = NULL;
stack* p;
int count1 = 0;//подсчет всех элементов
int counter = 1;//для функции вывода
//push
//pop
void push()//добавить элемент
{
	cout << "<------------------------------------------------>" << endl;
	int data;
	cout << "Введите новый элемент : ";
	cin >> data;
	p = new stack;
	p->value = data;
	p->next = head;
	head = p;
	count1++;
	cout << "Элемент был успешно добавлен в начало стека." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}

int pop()
{
	cout << "<------------------------------------------------>" << endl;
	if (!head)
	{
		cout << "Список пуст." << endl;
		cout << "<------------------------------------------------>" << endl;
		return 0;
	}
	cout << endl;
	stack* h = p;
	int data;
	data = h->value;
	p = p->next;
	head = head->next;
	cout << "Элемент был успешно извлечён." << endl;
	cout << "Элемент - " << data << endl;
	cout << "<------------------------------------------------>" << endl;
	return data;
}


void rec_write(stack* pilist)//рекурсивный вывод 
{
	if (pilist == NULL) { return; }
	rec_write(pilist->next);
	cout << "Элемент №" << counter << " = " << pilist->value << endl;
	counter++;
	return;
}
void write()//красивый вывод с использованием рекурсивного вывода 
{
	stack* pilist = head;
	if (!pilist) {
		cout << "<------------------------------------------------>" << endl;
		cout << "Список пуст." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << "<------------------------------------------------>" << endl;
	cout << "Все элементы списка : " << endl;
	rec_write(pilist);
	counter = 1;
	cout << "<------------------------------------------------>" << endl;
	return;
}

void zadanie()
{
	cout << "<------------------------------------------------>" << endl;
	int cont = 0;
	stack* host = p;
	for (int i = 0; i < count1 - 1; i++) {
		int val1, val2;
		val1 = host->value;
		host = host->next;
		val2 = host->value;
		if (val1 == val2) cont++;
	}
	if (cont == 0) { cout << "Таких значений нет." << endl; return; }
	else { cout << "Количество пар одинаковых соседних элементов - " << cont << endl; }
	cout << "<------------------------------------------------>" << endl;
}


void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "Что собираетесь делать?" << endl;
		cout << "1 - Добавление элемента в вершину стека." << endl;
		cout << "2 - Извлечение элемента с вершины стека." << endl;
		cout << "3 - Вывод всех элементов стека." << endl;
		cout << "4 - Исполнение функции варианта." << endl;
		cout << "5 - Выход." << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			write();
			break;
		case 4:
			zadanie();
			break;
		case 5:
			cout << "До новых встреч" << endl;
			break;
		default:
			cout << "Некорректный запрос, повторите пожалуйста." << endl;
			break;
		}

	} while (c != 5);
}
