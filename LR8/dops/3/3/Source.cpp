#include<iostream>
using namespace std;
struct item
{
	int value;
	item* next;
};
item* plist = NULL;
item* p;
int count1 = 0;//подсчет всех элементов
int counter = 1;//для функции вывода
void push()//добавить элемент
{
	cout << "<------------------------------------------------>" << endl;
	int data;
	cout << "Ввод эл-а : ";
	cin >> data;
	p = new item;
	p->value = data;
	p->next = plist;
	plist = p;
	count1++;
	cout << "Эл-т  добавлен в начало очереди." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void pop()
{
	cout << "<------------------------------------------------>" << endl;
	item* hash = p;
	if (!hash) { cout << "Очередь пуста." << endl; return; }
	int k;
	if (count1 == 1)
	{
		k = hash->value;
		hash = NULL;
		plist = NULL;
	}
	else
	{
		for (; hash->next->next != NULL;)
		{
			hash = hash->next;
		}
		k = hash->next->value;
		hash->next = NULL;
	}
	count1--;
	cout << "Извл эл-т равен - " << k << '.' << endl;
	cout << "<------------------------------------------------>" << endl;
}
void rec_write(item* pilist)//рекурсивный вывод 
{
	if (pilist == NULL) { return; }
	rec_write(pilist->next);
	cout << "Элемент №" << counter << " = " << pilist->value << endl;
	counter++;
	return;
}
void write()//красивый вывод с использованием рекурсивного вывода 
{
	item* pilist = plist;
	if (!pilist)
	{
		cout << "<------------------------------------------------>" << endl;
		cout << "Очередь пуста." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << "<------------------------------------------------>" << endl;
	cout << "Все эл-ы очереди : " << endl;
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
		cout << "Очередь пуста." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << endl;
	rec_write(plist);
	counter = 1;
	cout << endl;
	cout << "Какой эл-т хотите удалить?" << endl;
	int num;
	cout << "Элемент № ";
	cin >> num;
	if (num<0 && num>count1) {
		cout << "Такого элемента не существует" << endl;
		return;
		cout << "<------------------------------------------------>" << endl;
	}
	item* host = plist;//промежуточный указатель по которому будем идти
	for (int i = 0; i < count1 - num - 1; i++)
	{
		host = host->next;
	}
	if (count1 == 1) { plist = NULL; p = NULL; }
	else {
		host->next = host->next->next;//переопределение указателей списка через один
	}
	count1--;
	cout << "Эл-т удалён успешно." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void size()
{
	cout << "<------------------------------------------------>" << endl;
	cout << "Размер очереди = " << count1 << endl;
	cout << "<------------------------------------------------>" << endl;
}
void max_el()
{
	cout << "<------------------------------------------------>" << endl;
	item* hash = p;
	if (!hash)
	{
		cout << "<------------------------------------------------>" << endl;
		cout << "Очередь пуста." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	int ma = hash->value;
	for (; hash->next != NULL; hash = hash->next)
	{
		if (ma < hash->value) { ma = hash->value; }
	}
	cout << "Макс эл-т очереди равен - " << ma << endl;
	cout << "<------------------------------------------------>" << endl;
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "Что хотите сделать?" << endl;
		cout << "1 - Добавить эл-т очереди." << endl;
		cout << "2 - Извлечь эл-т очереди." << endl;
		cout << "3 - Вывести все эл-ы очереди." << endl;
		cout << "4 - Удалить эл-т очереди." << endl;
		cout << "5 - Размер очереди" << endl;
		cout << "6 - Макс эл-т очереди." << endl;
		cout << "8 - Выход" << endl;
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
			del();
			break;
		case 5:
			size();
			break;
		case 6:
			max_el();
			break;
		case 8:
			cout << "До скорого" << endl;
			break;
		default:
			cout << "Некорректный запрос" << endl;
			break;
		}

	} while (c != 8);
}
