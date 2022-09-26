#include <iostream>
#include<conio.h>  

using namespace std;
struct Node
{
	int data;             //Информационное поле
	Node* left, * right;   //Указатели на левую и правую ветви дерева
};
Node* tree = nullptr;

void insert(int a, Node** t)  //Добавление элемента a 
{
	if ((*t) == NULL)              //если дерева нет, то создается элемент
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a >= (*t)->data)  //дерево есть, если а больше текущего
		insert(a, &(*t)->right);  //то элемент помещается вправо
	else
		insert(a, &(*t)->left);   //иначе - влево
}

void print(Node* t, int level)    //Вывод на экран | u - глубина 
{
	if (t == NULL)  return; // если пустой указатель, то перебирать нечего, логично впрочем да
	else
	{
		print(t->left, ++level);     //левое поддерево | находим уровень дерева
		for (int i = 0; i < level; ++i)
			cout << "|";

		cout << t->data << endl;
		level--;
	}
	print(t->right, ++level);          // правое поддерево
}

int counter(Node* t, int level, int CUNT, int ans) {
	if (t == NULL)  return ans++;
	else
	{
		counter(t->left, ++level, CUNT, ans);     //левое поддерево
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
		cout << "1 - Ввод чиел" << endl;
		cout << "2 - Вывести дерево на экран" << endl;
		cout << "3 - Подсчитать кол-во ввершин равных данному значению" << endl;
		cout << "4 - Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Введите количество элементов  "; cin >> count;
			for (int i = 0; i < count; ++i)
			{
				cout << "Введите число  ";	cin >> temp;
				insert(temp, &tree);
			}
			break;
		}
		case 2: {
			print(tree, 0); break;
		}
		case 3: {
			int numb = 0, ans = 0;
			cout << "Введите число" << endl;
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
