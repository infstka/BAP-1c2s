#include <iostream>
#include <fstream>

using namespace std;

struct Stack
{
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};


void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void lol(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	int k = 100000000; // ����������� ����������
	int y = 0; // ����� ����������� ����������
	int q = 1; // ������� ����������
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
	cout << "����� ����������� ������: " << k << endl;
	cout << "����� ���� ������: " << q;
	cout << endl;
}

void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	x = x - 1;
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}

void proverka(Stack* myStk) {
	ifstream frm("Steck.txt", ios_base::in);
	if (!frm.is_open()) {
		cout << "������ ��������";
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
		cout << "������ ��������";
	}
	else {
		frm << "������ ��� ����?\r\n���������\r\n� � ����\r\n�������\r\n�����o ";
		frm.close();
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Stack* myStk = new Stack; //��������� ������ ��� �����
	myStk->head = NULL;
	for (;;) {
		cout << "\n�������� �������:" << endl;
		cout << "1 - ���� ����� � ����" << endl;
		cout << "2 - ���� ���� ����� �� ����� � ���� " << endl;
		cout << "3 - ����� �����" << endl;
		cout << "4 - ����� ����� �������� ������ � � ������" << endl;
		cout << "5 - �����" << endl;
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
		case 3: cout << "\n���� ����: " << endl;
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