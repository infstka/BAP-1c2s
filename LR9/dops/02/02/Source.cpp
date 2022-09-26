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

void Poisk(void) // ����� ����� � ������
{
	char name[40];  struct Adr* t;  t = head;
	cout << "������� ����� ����������: "; gets(name);
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t) cout << "����� ���������� �� �������" << endl;
	else
		cout << t->name << ' ' << t->time << ' ' << t->date << ' ' << t->stoim << endl;
}
void Udalit(Adr** head, Adr** last)
{
	Adr* t;
	char name[40];
	t = *head;
	system("cls");
	cout << "������� ����� ����������: ";
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


void Zapisat(void)       //������ � ����
{
	struct Adr* t;  FILE* fp;
	fp = fopen("mlist", "wb");
	if (!fp) { cout << "���� �� �����������" << endl;  exit(1); }
	cout << "���������� � ����" << endl;
	t = head;
	while (t) {
		fwrite(t, sizeof(struct Adr), 1, fp);
		t = t->next;
	}      fclose(fp);
}
void Schitat()          //������. �� �����
{
	struct Adr* t;  FILE* fp;
	fp = fopen("mlist", "rb");
	if (!fp) { cout << "���� �� �����������" << endl;  exit(1); }
	while (head)
	{
		last = head->next; delete head;
		head = last;
	}   head = last = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new (struct Adr);
		if (!t) { cout << "��� ��������� ����-��" << endl; return; }
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
		if (strlen(p) >> count) cout << ("������� ������� ������");  //����� ������
	} while (strlen(p) >> count);
	p[strlen(p) - 1] = 0;  strcpy(s, p);
}
void VvodSp(void)      // ���� ������
{
	struct Adr* t;
	t = new (struct Adr);
	if (!t) { cout << ("��� ��������� ������"); return; }
	Vvod("������� ����� ����������: ", t->name, 30);
	Vvod("������� ����� ������: ", t->time, 40);
	Vvod("������� ���� ������: ", t->date, 20);
	cout << "������� ��������� ������: ";
	cin >> t->stoim;
	Sozdat(t, &head, &last);
}
void VyvodSp(void)      //������ �� �����
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
	cout << "1. ���� " << endl;
	cout << "2. �������� �����" << endl;
	cout << "3. ����� ������ �� �����" << endl;
	cout << "4. �����" << endl;
	cout << "5. ��������� � ����" << endl;
	cout << "6. ��������� �� �����" << endl;
	cout << "7. �������� ������" << endl;
	cout << "8. ���������� ��������� � ������" << endl;
	cout << "9. �������� �-��� �������� ������" << endl;
	cout << "10. ����� ������������� ��������" << endl;
	cout << "11. �����" << endl; cout << endl;
	/*do
	{*/
	cout << "��� �����: "; gets(s);  cout << endl;
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
	if (tmp == NULL) cout << "��������� ���" << endl;
	else
	{
		int col = 0;
		while (tmp)
		{
			tmp = tmp->next; col++;
		}
		cout << "���������� ��������� � ������: " << col << endl;
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
	cout << "������������ ������� ������. " << endl << "������ � " << num + 1 << ":" << endl << m->name << " " << m->time << " " << m->date << " " << m->stoim << endl;
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

