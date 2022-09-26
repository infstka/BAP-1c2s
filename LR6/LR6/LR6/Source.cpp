#include<iostream>
#include<fstream>
using namespace std;
struct item
{
	double value;
	item* next;
};
item* plist = NULL;
item* p;
int count1 = 0;//������� ���� ���������
int counter = 1;//��� ������� ������
void add()//�������� �������
{
	cout << "<------------------------------------------------>" << endl;
	double data;
	cout << "������� ����� ������� : ";
	cin >> data;
	p = new item;
	p->value = data;
	p->next = plist;
	plist = p;
	count1++;
	cout << "������� ��� ������� �������� � ������ ������." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void rec_write(item* pilist)//����������� ����� 
{
	if (pilist == NULL) { return; }
	rec_write(pilist->next);
	cout << "������� �" << counter << " = " << pilist->value << endl;
	counter++;
	return;
}
void write()//�������� ����� � �������������� ������������ ������ 
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
	if (num<0 && num>count1) { cout << "������ �������� �� ����������." << endl; return; }
	item* host = plist;//������������� ��������� �� �������� ����� ����
	for (int i = 0; i < count1 - num - 1; i++)
	{
		host = host->next;
	}
	host->next = host->next->next;//��������������� ���������� ������ ����� ����

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
		if (host->value == num) { cout << "������ ������� ��������� ��� ������� �" << i - 1 << endl; j = 1; }
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
	double num;
	plist = NULL;
	count1 = 0;
	while (fin >> num)
	{
		p = new item;
		p->value = num;
		p->next = plist;
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
void zadanie()
{
	cout << "<------------------------------------------------>" << endl;

	double sum = 0;
	int n = 0;
	item* host = plist;
	for (; host != NULL;)
	{
		if (host->value < 0)
		{
			sum += host->value;
			n++;
		}
		host = host->next;
	}
	if (n == 0) { cout << "����� ��������� ���." << endl; }
	else { cout << "������� �������������� ������ ��������� ����� = " << (sum / n) << endl; }
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
		cout << "7 - ���������� ������� ��������." << endl;
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
			zadanie();
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
