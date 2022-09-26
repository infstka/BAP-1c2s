#include<iostream>
using namespace std;
struct item
{
	int value;
	item* next;
};
item* plist = NULL;
item* p;
int count1 = 0;//������� ���� ���������
int counter = 1;//��� ������� ������
void push()//�������� �������
{
	cout << "<------------------------------------------------>" << endl;
	int data;
	cout << "���� ��-� : ";
	cin >> data;
	p = new item;
	p->value = data;
	p->next = plist;
	plist = p;
	count1++;
	cout << "��-�  �������� � ������ �������." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void pop()
{
	cout << "<------------------------------------------------>" << endl;
	item* hash = p;
	if (!hash) { cout << "������� �����." << endl; return; }
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
	cout << "���� ��-� ����� - " << k << '.' << endl;
	cout << "<------------------------------------------------>" << endl;
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
	if (!pilist)
	{
		cout << "<------------------------------------------------>" << endl;
		cout << "������� �����." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << "<------------------------------------------------>" << endl;
	cout << "��� ��-� ������� : " << endl;
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
		cout << "������� �����." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << endl;
	rec_write(plist);
	counter = 1;
	cout << endl;
	cout << "����� ��-� ������ �������?" << endl;
	int num;
	cout << "������� � ";
	cin >> num;
	if (num<0 && num>count1) {
		cout << "������ �������� �� ����������" << endl;
		return;
		cout << "<------------------------------------------------>" << endl;
	}
	item* host = plist;//������������� ��������� �� �������� ����� ����
	for (int i = 0; i < count1 - num - 1; i++)
	{
		host = host->next;
	}
	if (count1 == 1) { plist = NULL; p = NULL; }
	else {
		host->next = host->next->next;//��������������� ���������� ������ ����� ����
	}
	count1--;
	cout << "��-� ����� �������." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void size()
{
	cout << "<------------------------------------------------>" << endl;
	cout << "������ ������� = " << count1 << endl;
	cout << "<------------------------------------------------>" << endl;
}
void max_el()
{
	cout << "<------------------------------------------------>" << endl;
	item* hash = p;
	if (!hash)
	{
		cout << "<------------------------------------------------>" << endl;
		cout << "������� �����." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	int ma = hash->value;
	for (; hash->next != NULL; hash = hash->next)
	{
		if (ma < hash->value) { ma = hash->value; }
	}
	cout << "���� ��-� ������� ����� - " << ma << endl;
	cout << "<------------------------------------------------>" << endl;
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "��� ������ �������?" << endl;
		cout << "1 - �������� ��-� �������." << endl;
		cout << "2 - ������� ��-� �������." << endl;
		cout << "3 - ������� ��� ��-� �������." << endl;
		cout << "4 - ������� ��-� �������." << endl;
		cout << "5 - ������ �������" << endl;
		cout << "6 - ���� ��-� �������." << endl;
		cout << "8 - �����" << endl;
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
			cout << "�� �������" << endl;
			break;
		default:
			cout << "������������ ������" << endl;
			break;
		}

	} while (c != 8);
}
