#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

struct Adr
{
	char name[30]; char time[40];
	char date[20]; int stoim;
	struct Adr* next;
	struct Adr* prev;
};
struct Adr* head; struct Adr* last;

void Poisk(void) // Поиск имени в списке
{
	char name[40];  struct Adr* t;  t = head;
	cout << "Введите пункт назначения: "; gets(name);
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t) cout << "Пункт назначения не найдено" << endl;
	else
		cout << t->name << ' ' << t->time << ' ' << t->date << ' ' << t->stoim << endl;
}
void Udalit(Adr** head, Adr** last)
{
	Adr* t;
	char name[40];
	t = *head;
	system("cls");
	cout << "Введите пункт назначения: ";
	gets_s(name);
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (t) {
		if (*head == t)
		{
			*head = t->next;
			if (*head) (*head)->prev = NULL;
			else *last = NULL;
		}
		else {
			t->prev->next = t->next;
			if (t != *last) t->next->prev = t->prev;
			else  *last = t->prev;

		}
		delete t;
	}
	system("pause");
	return;
}

void Sozdat(Adr* i, Adr** head, Adr** last)
{
	struct Adr* old, * p;
	if (*last == NULL)
	{
		i->next = NULL; i->prev = NULL;
		*last = i;  *head = i;
		return;
	}
	p = *head; old = NULL;
	while (p)
	{
		if (strcmp(p->name, i->name) < 0)
		{
			old = p; p = p->next;
		}
		else
		{
			if (p->prev)
			{
				p->prev->next = i; i->next = p;
				i->prev = p->prev;  p->prev = i;
				return;
			}
			i->next = p; i->prev = NULL;
			p->prev = i; *head = i;
			return;
		}
	}
	old->next = i;
	i->next = NULL;  i->prev = old;
	*last = i;
}


void Zapisat(void)       //Запись в файл
{
	struct Adr* t;  FILE* fp;
	fp = fopen("mlist", "wb");
	if (!fp) { cout << "Файл не открывается" << endl;  exit(1); }
	cout << "Сохранение в файл" << endl;
	t = head;
	while (t) {
		fwrite(t, sizeof(struct Adr), 1, fp);
		t = t->next;
	}      fclose(fp);
}
void Schitat()          //Считыв. из файла
{
	struct Adr* t;  FILE* fp;
	fp = fopen("mlist", "rb");
	if (!fp) { cout << "Файл не открывается" << endl;  exit(1); }
	while (head)
	{
		last = head->next; delete head;
		head = last;
	}   head = last = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new (struct Adr);
		if (!t) { cout << "Нет свободной памя-ти" << endl; return; }
		if (1 != fread(t, sizeof(struct Adr), 1, fp)) break;	Sozdat(t, &head, &last);
	}
	fclose(fp);
}


void Vvod(char* prompt, char* s, int count)
{
	char p[255];
	do

	{
		cout << (prompt); fgets(p, 254, stdin);
		if (strlen(p) >> count) cout << ("Слишком длинная строка");  //длина строки
	} while (strlen(p) >> count);
	p[strlen(p) - 1] = 0;  strcpy(s, p);
}
void VvodSp(void)      // Ввод строки
{
	struct Adr* t;
	t = new (struct Adr);
	if (!t) { cout << ("Нет свободной памяти"); return; }
	Vvod("Введите пункт назначения: ", t->name, 30);
	Vvod("Введите время вылета: ", t->time, 40);
	Vvod("Введите дата вылета: ", t->date, 20);
	cout << "Введите стоимость билета: ";
	cin >> t->stoim;
	Sozdat(t, &head, &last);
}
void VyvodSp(void)      //Список на экран
{
	struct Adr* t;  t = head;
	while (t)
	{
		cout << t->name << ' ' << t->time << ' ' << t->date << ' ' << t->stoim << endl; t = t->next;
	}  cout << "" << endl;
}


int Menu(void)
{
	setlocale(LC_CTYPE, "Russian");
	char s[80];   int c;
	cout << endl;
	cout << "1. Ввод " << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод списка на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Сохранить в файл" << endl;
	cout << "6. Загрузить из файла" << endl;
	cout << "7. Удаление списка" << endl;
	cout << "8. Количество элементов в списке" << endl;
	cout << "9. Удаление М-ого элемента списка" << endl;
	cout << "10. Поиск максимального элемента" << endl;
	cout << "11. Выход" << endl; cout << endl;
	/*do
	{*/
	cout << "Ваш выбор: "; gets(s);  cout << endl;
	c = atoi(s);
	/*} while (c<0 || c>11);*/
	return c;
}



void dellist()
{

	while (head)
	{
		Adr* tmp = head->next;
		delete head;
		head = tmp;
	}
}

void ColList()
{
	Adr* tmp = head;
	if (tmp == NULL) cout << "Элементов нет" << endl;
	else
	{
		int col = 0;
		while (tmp)
		{
			tmp = tmp->next; col++;
		}
		cout << "Количество элементов в списке: " << col << endl;
	}

}


void delM()
{
	struct Adr* old, * t;  t = head; int sch = 0, num, m;
	cout << "M = ";
	cin >> m;
	for (t; t != NULL; t = t->next)
	{

		sch++;

		if (sch == m) { old = t->prev;  old->next = t->next; delete t; t = old; sch = 0; }

	}
}

void maxEl()
{
	Adr* tmp = head, * m = head; int max = -1, sch = 0, num;
	while (tmp)
	{
		if (tmp->stoim > max) { m = tmp; num = sch; }
		tmp = tmp->next; sch++;
	}
	cout << "Максимальный элемент списка. " << endl << "Запись № " << num + 1 << ":" << endl << m->name << " " << m->time << " " << m->date << " " << m->stoim << endl;
}


void main(void)
{
	setlocale(LC_CTYPE, "Rus");
	head = last = NULL;
	int q = 0;
	while (q != 11)
	{
		q = Menu();
		switch (q)
		{
		case 1: VvodSp();  break;
		case 2: Udalit(&head, &last); break;
		case 3: VyvodSp(); break;
		case 4: Poisk();   break;
		case 5: Zapisat(); break;
		case 6: Schitat(); break;
		case 7: dellist(); break;
		case 8: ColList(); break;
		case 9:delM(); break;
		case 10: maxEl(); break;
		case 11: exit(0);
		}
	}
}

