#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
struct  node
{
	int Key;
	int Count;
	node* Left;
	node* Right;
};
node* Tree;  
node* Res; 
int B;     
node** GetTree()
{
	return &Tree;
}

void Search(int x, node** p) 
{
	if (*p == NULL) 
	{
		*p = new(node);
		(**p).Key = x;
		(**p).Count = 1;
		(**p).Left = (**p).Right = NULL;
	}
	else
		if (x < (**p).Key) Search(x, &((**p).Left));
		else
			if (x > (**p).Key) Search(x, &((**p).Right));
			else  (**p).Count += 1;
}

void BuildTree() 
{
	int el;
	cout << "Введите ключи вершин дерева: \n";
	cin >> el;
	while (el != 0)
	{
		Search(el, &Tree);
		cin >> el;
	}
}

void Vyvod(node** w, int l) 
{
	int i;
	if (*w != NULL)            
	{
		Vyvod(&((**w).Right), l + 1);
		for (i = 1; i <= l; i++)
			cout << "   ";
		cout << (**w).Key << endl;
		Vyvod(&((**w).Left), l + 1);
	}
}

void VyvodV(node** w, int l, node** V)  //Вывод на экран
{
	int i;
	if (*w != *V)            //*w - указатель на корень 
	{
		VyvodV(&((**w).Right), l + 1, V);
		for (i = 1; i <= l; i++)
			cout << "   ";
		cout << (**w).Key << endl;
		VyvodV(&((**w).Left), l + 1, V);
	}
}

int Poisk(int k)   //Поиск вершины с ключом k 
{
	node* p, * q = 0; B = FALSE; p = Tree;
	int i = 0, v;
	if (Tree != NULL)
		do
		{
			i++;
			q = p; if ((*p).Key == k) B = TRUE;
			else
			{
				q = p;
				if (k < (*p).Key)  p = (*p).Left;
				else  p = (*p).Right;
			}
		} while (!B && p != NULL);
		Res = q;
		VyvodV(GetTree(), 0, &Res);
		return B;
}


void main()
{
	setlocale(LC_CTYPE, "Russian");
	int el;
	BuildTree();
	Vyvod(GetTree(), 0);
}
