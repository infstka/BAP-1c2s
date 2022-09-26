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
int count1 = 0;//������� ���� ���������
int counter = 1;//��� ������� ������
//push
//pop
void push()//�������� �������
{
	cout << "<------------------------------------------------>" << endl;
	int data;
	cout << "������� ����� ������� : ";
	cin >> data;
	p = new stack;
	p->value = data;
	p->next = head;
	head = p;
	count1++;
	cout << "������� ��� ������� �������� � ������ �����." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}

int pop()
{
	cout << "<------------------------------------------------>" << endl;
	if (!head)
	{
		cout << "������ ����." << endl;
		cout << "<------------------------------------------------>" << endl;
		return 0;
	}
	cout << endl;
	stack* h = p;
	int data;
	data = h->value;
	p = p->next;
	head = head->next;
	cout << "������� ��� ������� ��������." << endl;
	cout << "������� - " << data << endl;
	cout << "<------------------------------------------------>" << endl;
	return data;
}


void rec_write(stack* pilist)//����������� ����� 
{
	if (pilist == NULL) { return; }
	rec_write(pilist->next);
	cout << "������� �" << counter << " = " << pilist->value << endl;
	counter++;
	return;
}
void write()//�������� ����� � �������������� ������������ ������ 
{
	stack* pilist = head;
	if (!pilist) {
		cout << "<------------------------------------------------>" << endl;
		cout << "������ ����." << endl;
		cout << "<------------------------------------------------>" << endl;
		return;
	}
	cout << "<------------------------------------------------>" << endl;
	cout << "��� �������� ������ : " << endl;
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
	if (cont == 0) { cout << "����� �������� ���." << endl; return; }
	else { cout << "���������� ��� ���������� �������� ��������� - " << cont << endl; }
	cout << "<------------------------------------------------>" << endl;
}


void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "��� ����������� ������?" << endl;
		cout << "1 - ���������� �������� � ������� �����." << endl;
		cout << "2 - ���������� �������� � ������� �����." << endl;
		cout << "3 - ����� ���� ��������� �����." << endl;
		cout << "4 - ���������� ������� ��������." << endl;
		cout << "5 - �����." << endl;
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
			cout << "�� ����� ������" << endl;
			break;
		default:
			cout << "������������ ������, ��������� ����������." << endl;
			break;
		}

	} while (c != 5);
}
