#include<iostream>
using namespace std;
struct Item
{
	int data;
	Item* next;
};
Item* head, * tail;

bool isNull(void)    //�������� �� �������
{
	return (head == nullptr);
}
void deletFirst()   //���������� �������� �� ������
{
	if (isNull())
		cout << "������� �����" << endl;
	else
	{
		Item* p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //��������� �������� �� ������
{
	if (isNull())
		cout << "������� �����" << endl;
	else
		cout << "������ = " << head->data << endl;
}
void getFromTail()  //��������� �������� �� �����
{
	if (isNull())
		cout << "������� �����" << endl;
	else
		cout << "����� = " << tail->data << endl;
}
void insertToQueue(int x)  //���������� �������� � ������� 
{
	Item* p = new Item;      //����� ��������� 
	p->data = x;
	p->next = nullptr;
	Item* v = new Item;      //��������� ��� ������ �����
	Item* p1 = new Item;
	Item* p2 = new Item;
	int i = 0;               //������ 
	if (isNull())
		head = tail = p;
	else
	{
		p2 = head; p1 = head; // !!!����� ����������� ���� LiFo ���������� ����� ��������� p2 ��� ������, FiFo ��������
		while (p1 != nullptr)  //���� ������� �� ����������
		{
			/*if (i == 1) //����� ���������� ��� ���������� LiFo
			{*/
			if (i == 1)
			{
				if (x > p1->data)  //����� ������, ��� � �������
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				if (x == p1->data)
				{
					v->data = x;
					v->next = p1->next;
					p1->next = v;
					return;
				}
				p2 = p2->next;
			}
			if (x > p1->data)
			{
				v->data = x;
				v->next = p1;
				head = v;
				return;
			}
			if (p1->next == nullptr)
			{
				v->data = x;
				v->next = nullptr;
				tail->next = v;
				tail = v;
				return;
			}
			i = 1;

			p1 = p1->next;      // ��������� �����
		/*}*/
		/*else // else ����������� ��� ���������� ������� LiFo
		{
			if (x >= p1->data)
			{
				v->data = x;
				v->next = p2;
				head = v;
				return;
			}
		}*/
		/*p1 = p1->next; //����� ���������� ��� ���������� LiFo
		i = 1;*/
		/*}
		if (p1 == NULL) // ��������� ��� ��������� LiFo
		{
			v->data = x;
			v->next = tail;
			p2.next = v;
		}*/
		}
	}
}
void printQueue()             //����� �������
{
	Item* p = new Item;
	if (isNull())
		cout << "������� �����" << endl;
	else
	{
		cout << "������� = ";
		p = head;
		while (!isNull())
		{
			if (p != nullptr)
			{
				cout << p->data << " "; cout << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clrQueue()           //������� �������
{
	while (!isNull()) deletFirst();
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1, z; head = nullptr;  tail = nullptr;
	while (choice != 0)
	{
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������� � ������" << endl;
		cout << "3 - ������� ������� � ������" << endl;
		cout << "4 - ������� ��������" << endl;
		cout << "5 - �������� �������" << endl;
		cout << "6 - �������� ������� � �����" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� ��������  ";  cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������:  "; cin >> z;
			insertToQueue(z); printQueue();  break;
		case 2: getFromHead(); break;
		case 3: deletFirst();  break;
		case 4: printQueue();  break;
		case 5: clrQueue();    break;
		case 6: getFromTail(); break;
		}
	}
	return 0;
}
