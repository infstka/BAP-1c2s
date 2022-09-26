#include<iostream>
#include<fstream>
using namespace std;
struct item
{
	int value;
	item* next;
	item* prev;
};
item* plist = NULL;
item* p;
int count1 = 0;//подсчет всех элементов
int counter = 1;//для функции вывода
/*
		cout << "1 - Добавление элемента." << endl;///////////////+
		cout << "2 - Удаление элемента." << endl;
		cout << "3 - Вывод всех элементов." << endl;
		cout << "4 - Поиск элемента." << endl;
		cout << "5 - Вывод в файл всех элементов." << endl;
		cout << "6 - Запись с файла всех элементов." << endl;*/
void add()
{
	cout << "<------------------------------------------------>" << endl;
	int data;
	cout << "Введите новый элемент : ";
	cin >> data;
	p = new item;
	p->value = data;
	p->next = plist;
	p->prev = NULL;
	if (p->next != NULL)
	{
		item* previ;
		previ = p;
		p = p->next;
		p->prev = previ;
		p = previ;
	}
	plist = p;
	count1++;
	cout << "Элемент был успешно добавлен в начало списка." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void rec_write(item* pilist)
{
	if (pilist == NULL) { return; }
	rec_write(pilist->next);
	cout << "Элемент №" << counter << " = " << pilist->value << endl;
	counter++;
	return;
}
void write() 
{
	item* pilist = plist;
	if (!pilist) { cout << "Список пуст." << endl; return; }
	cout << "<------------------------------------------------>" << endl;
	cout << "Все элементы списка : " << endl;
	rec_write(pilist);
	counter = 1;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void del()
{
	cout << "<------------------------------------------------>" << endl;
	if (!plist)
	{
		cout << "Список пуст." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << endl;
	rec_write(plist);
	counter = 1;
	cout << endl;
	cout << "Какой элемент хотите удалить?" << endl;
	int num;
	cout << "Элемент номер - ";
	cin >> num;
	if (num<0 && num>count1) {
		cout << "Такого элемента не существует." << endl;
		return;
		cout << "<------------------------------------------------>" << endl;
	}
	item* host = plist;
	for (int i = 0; i < count1 - num - 1; i++)
	{
		host = host->next;
	}
	if (count1 == 1)
	{
		free(p);
		plist = NULL;
	}
	else
		if (num == count1)
		{
			host = host->next;
			host->prev = NULL;
			p = host;
			plist = host;
		}
		else
		{
			if (num == 1)
			{
				host->next = NULL;
			}
			else
			{

				host->next = host->next->next;//переопределение указателей списка через один
				if (!host->next)
				{
					item* previ;
					previ = host;
					host = host->next;
					host->prev = previ;
					host = previ;
				}
			}
		}
	count1--;
	cout << "Элемент удалён успешно" << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void search()
{
	cout << "<------------------------------------------------>" << endl;
	cout << "Введите элемент : ";
	int num;
	cin >> num;
	item* host = plist;
	bool j = 0;//триггер
	for (int i = count1; host != NULL; i--)
	{
		if (host->value == num) { cout << "Данный элемент находится под номером №" << i << endl; j = 1; }
		host = host->next;
	}
	if (j == 0) { cout << "Данный элемент не был найден в списке." << endl; }
	cout << "<------------------------------------------------>" << endl;
	return;
}

void finput()
{
	cout << "<------------------------------------------------>" << endl;

	item* host = plist;
	ifstream fin("IN.txt");
	int num;
	plist = NULL;
	count1 = 0;
	while (fin >> num)
	{
		p = new item;
		p->value = num;
		p->next = plist;
		p->prev = NULL;
		if (!p->next)
		{
			item* previ;
			previ = p;
			p = p->next;
			p->prev = previ;
			p = previ;
		}
		plist = p;
		count1++;
	}
	cout << "Перезапись с файла прошло успешно." << endl;
	cout << "<------------------------------------------------>" << endl;

}

void foutput()
{
	cout << "<------------------------------------------------>" << endl;

	item* host = plist;
	ofstream fout("OUT.txt");
	for (; host != NULL;)
	{
		fout << host->value << endl;
		host = host->next;
	}
	cout << "Все данные были выведены в файл." << endl;
	cout << "<------------------------------------------------>" << endl;

}
void findMin()
{
	cout << "<------------------------------------------------>" << endl;
	int mi = p->value;
	item* host = plist;
	while (host != NULL)
	{
		if (mi > host->value)
		{
			mi = host->value;
		}
		host = host->next;
	}
	cout << "Минимальный элемент списка - " << mi << endl;
	cout << "<------------------------------------------------>" << endl;
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "Что собираетесь делать?" << endl;
		cout << "1 - Добавление элемента." << endl;
		cout << "2 - Удаление элемента." << endl;
		cout << "3 - Вывод всех элементов." << endl;
		cout << "4 - Поиск элемента." << endl;
		cout << "5 - Вывод в файл всех элементов." << endl;
		cout << "6 - Запись с файла всех элементов." << endl;
		cout << "7 - Поиск минимального элемента в списке." << endl;
		cout << "8 - Выход." << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			add();
			break;
		case 2:
			del();
			break;
		case 3:
			write();
			break;
		case 4:
			search();
			break;
		case 5:
			foutput();
			break;
		case 6:
			finput();
			break;
		case 7:
			findMin();
			break;
		case 8:
			cout << "До новых встреч" << endl;
			break;
		default:
			cout << "Некорректный запрос, повторите пожалуйста." << endl;
			break;
		}

	} while (c != 8);
}
