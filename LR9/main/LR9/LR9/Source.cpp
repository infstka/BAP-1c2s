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
int count1 = 0;//������� ���� ���������
int counter = 1;//��� ������� ������
/*
		cout << "1 - ���������� ��������." << endl;///////////////+
		cout << "2 - �������� ��������." << endl;
		cout << "3 - ����� ���� ���������." << endl;
		cout << "4 - ����� ��������." << endl;
		cout << "5 - ����� � ���� ���� ���������." << endl;
		cout << "6 - ������ � ����� ���� ���������." << endl;*/
void add()
{
	cout << "<------------------------------------------------>" << endl;
	int data;
	cout << "������� ����� ������� : ";
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
	cout << "������� ��� ������� �������� � ������ ������." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void rec_write(item* pilist)
{
	if (pilist == NULL) { return; }
	rec_write(pilist->next);
	cout << "������� �" << counter << " = " << pilist->value << endl;
	counter++;
	return;
}
void write() 
{
	item* pilist = plist;
	if (!pilist) { cout << "������ ����." << endl; return; }
	cout << "<------------------------------------------------>" << endl;
	cout << "��� �������� ������ : " << endl;
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
		cout << "������ ����." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << endl;
	rec_write(plist);
	counter = 1;
	cout << endl;
	cout << "����� ������� ������ �������?" << endl;
	int num;
	cout << "������� ����� - ";
	cin >> num;
	if (num<0 && num>count1) {
		cout << "������ �������� �� ����������." << endl;
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

				host->next = host->next->next;//��������������� ���������� ������ ����� ����
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
	cout << "������� ����� �������" << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void search()
{
	cout << "<------------------------------------------------>" << endl;
	cout << "������� ������� : ";
	int num;
	cin >> num;
	item* host = plist;
	bool j = 0;//�������
	for (int i = count1; host != NULL; i--)
	{
		if (host->value == num) { cout << "������ ������� ��������� ��� ������� �" << i << endl; j = 1; }
		host = host->next;
	}
	if (j == 0) { cout << "������ ������� �� ��� ������ � ������." << endl; }
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
	cout << "���������� � ����� ������ �������." << endl;
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
	cout << "��� ������ ���� �������� � ����." << endl;
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
	cout << "����������� ������� ������ - " << mi << endl;
	cout << "<------------------------------------------------>" << endl;
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "��� ����������� ������?" << endl;
		cout << "1 - ���������� ��������." << endl;
		cout << "2 - �������� ��������." << endl;
		cout << "3 - ����� ���� ���������." << endl;
		cout << "4 - ����� ��������." << endl;
		cout << "5 - ����� � ���� ���� ���������." << endl;
		cout << "6 - ������ � ����� ���� ���������." << endl;
		cout << "7 - ����� ������������ �������� � ������." << endl;
		cout << "8 - �����." << endl;
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
			cout << "�� ����� ������" << endl;
			break;
		default:
			cout << "������������ ������, ��������� ����������." << endl;
			break;
		}

	} while (c != 8);
}
