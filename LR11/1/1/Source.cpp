#include <iostream>
#include<conio.h>  

using namespace std;
struct Node
{
	int data;             //�������������� ����
	Node* left, * right;   //��������� �� ����� � ������ ����� ������
};
Node* tree = nullptr;

void insert(int a, Node** t)  //���������� �������� a 
{
	if ((*t) == NULL)              //���� ������ ���, �� ��������� �������
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a >= (*t)->data)  //������ ����, ���� � ������ ��������
		insert(a, &(*t)->right);  //�� ������� ���������� ������
	else
		insert(a, &(*t)->left);   //����� - �����
}

void print(Node* t, int level)    //����� �� ����� | u - ������� 
{
	if (t == NULL)  return; // ���� ������ ���������, �� ���������� ������, ������� ������� ��
	else
	{
		print(t->left, ++level);     //����� ��������� | ������� ������� ������
		for (int i = 0; i < level; ++i)
			cout << "|";

		cout << t->data << endl;
		level--;
	}
	print(t->right, ++level);          // ������ ���������
}

int counter(Node* t, int level, int CUNT, int ans) {
	if (t == NULL)  return ans++;
	else
	{
		counter(t->left, ++level, CUNT, ans);     //����� ���������
		if (t->data == CUNT) {
			ans++;
			for (int i = 0; i < level; ++i)
				cout << "|";

			cout << t->data << endl;
		}
		level--;
	}
	counter(t->right, ++level, CUNT, ans);
}

void menu() {
	int count = 0, temp = 0, choice = 0;
	do {
		cout << "-----------------------" << endl;
		cout << "1 - ���� ����" << endl;
		cout << "2 - ������� ������ �� �����" << endl;
		cout << "3 - ���������� ���-�� ������� ������ ������� ��������" << endl;
		cout << "4 - �����" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "������� ���������� ���������  "; cin >> count;
			for (int i = 0; i < count; ++i)
			{
				cout << "������� �����  ";	cin >> temp;
				insert(temp, &tree);
			}
			break;
		}
		case 2: {
			print(tree, 0); break;
		}
		case 3: {
			int numb = 0, ans = 0;
			cout << "������� �����" << endl;
			cin >> numb;
			cout << counter(tree, 0, numb, ans) << endl;
			break;
		}
		case 4: {
			exit(-1);
		}
		}
	} while (choice != 4);
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	menu();
}
