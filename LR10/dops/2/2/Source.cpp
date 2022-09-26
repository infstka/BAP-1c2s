#include <iostream>
using namespace std;

int steck_kol1, steck_kol2;

struct Stk1
{
	int x;
	Stk1* Next, * Head1;
};

struct Stk
{
	int x;
	Stk* Next, * Head;
};

struct Stk2
{
	int x;
	Stk2* Next, * Head2;
};

void Push1(int x, Stk1** MyStk1)  //Добавление эле-мента
{
	Stk1* temp = new Stk1;
	temp->x = x;
	temp->Next = (*MyStk1)->Head1;
	(*MyStk1)->Head1 = temp;
}

void Push(int x, Stk** MyStk)  //Добавление эле-мента
{
	Stk* temp = new Stk;
	temp->x = x;
	temp->Next = (*MyStk)->Head;
	(*MyStk)->Head = temp;
}

void Push2(int x, Stk2** MyStk2)  //Добавление эле-мента
{
	Stk2* temp = new Stk2;
	temp->x = x;
	temp->Next = (*MyStk2)->Head2;
	(*MyStk2)->Head2 = temp;
}



void Show(Stk* MyStk)           //Вывод стека
{
	Stk* temp = MyStk->Head;
	while (temp != NULL)
	{
		cout << temp->x << " ";
		temp = temp->Next;
	}
	cout << endl;
}
void NEW_steck(Stk1** MyStk1, Stk2** MyStk2)
{
	int y, y1, y2;
	Stk* temp = new Stk;
	Stk1* temp1 = new Stk1;
	Stk2* temp2 = new Stk2;
	/*temp->x = (*MyStk)->x;
	temp1->x = x;
	temp2->x = x;*/
	//temp = (*MyStk)->Head;
	Stk* MyStk = new Stk;
	MyStk->Head = NULL;
	temp1 = (*MyStk1)->Head1;
	bool a = true;
	while (temp1 != NULL)
	{
		a = true;
		temp2 = (*MyStk2)->Head2;
		while (temp2 != NULL)
		{
			if (temp1->x == temp2->x) a = false;
			temp2 = temp2->Next;
		}
		if (a == true)
		{
			y = temp1->x;
			Push(temp1->x, &MyStk);
		}
		temp1 = temp1->Next;
	};
	Show(MyStk);
}

int main()
{
	setlocale(0, "rus");
	int elem;
	Stk1* MyStk1 = new Stk1;
	Stk2* MyStk2 = new Stk2;
	MyStk1->Head1 = NULL;
	MyStk2->Head2 = NULL;
	Stk* MyStk = new Stk;
	MyStk->Head = NULL;
	cout << "Введите Стек 1 и Стек 2: " << endl;
	cin >> steck_kol1; cin >> steck_kol2;

	for (int i = 1; i <= steck_kol1; i++)
	{
		cout << "введите число" << i << " стека 1  ";
		cin >> elem;
		Push1(elem, &MyStk1);
		cout << endl;
	}
	for (int i = 1; i <= steck_kol2; i++)

	{
		cout << "введите число" << i << " стека 2  ";
		cin >> elem;
		Push2(elem, &MyStk2);
		cout << endl;
	}
	NEW_steck(&MyStk1, &MyStk2);

	system("pause");
	return(0);
}
