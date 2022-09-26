#include<iostream>
using namespace std;
struct Item
{
	float data;
	Item* next;
};
Item* head, * tail;

bool isNull(void)    //�������� �� �������
{
	return (head == NULL);
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
void insertToQueue(float x)  //���������� �������� � ������� 
{
	Item* p = new Item;
	p->data = x;
	p->next = NULL;
	if (isNull())
		head = tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
}
void sortmax()
{
	Item* p = new Item;
	p = head;
	int count = 1, i = 1;
	float max = head->data;
	while (p != NULL)
	{
		if (max < p->data)
		{
			max = p->data;
			count = i;
		}
		i++;
		p = p->next;
	}
	tail->next = head;
	while ((count - 1))
	{
		head = head->next;
		tail = tail->next;
		count--;
	}
	tail->next = NULL;

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
			if (p != NULL)
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
	int i = 1, choice = 1, z; head = NULL;  tail = NULL;
	while (choice != 0)
	{
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������� � ������" << endl;
		cout << "3 - ������� ������� � ������" << endl;
		cout << "4 - ������� ��������" << endl;
		cout << "5 - ����� �� �������������" << endl;
		cout << "6 - �������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� ��������  ";  cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������:  "; cin >> z;
			insertToQueue(z); printQueue();  break;
		case 2: getFromHead(); break;
		case 3: deletFirst();  break;
		case 4: printQueue();  break;
		case 5: sortmax();  break;
		case 6: clrQueue();    break;
		}
	}
	return 0;
}