#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Stack {
	char data;
	Stack* next;
	Stack* head;
};
void push(Stack* myStk) {
	const short Length = 10;
	char Buffer[Length];
	cout << "Введите слово" << endl;
	cin >> Buffer;
	for (int i = 0; i < Length; i++) {
		Stack* st = new Stack;
		if (i < (Length / 2)) {
			st->data = Buffer[Length / 2 + i];
			st->next = myStk->head;
			myStk->head = st;
		}
		if (i >= Length / 2) {
			st->data = Buffer[i - (Length / 2)];
			st->next = myStk->head;
			myStk->head = st;
		}
	}
}
void snow(Stack* myStk) {
	Stack* st = myStk->head;
	if (st == NULL) {
		cout << "Стек пуст!" << endl;
	}
	while (st != NULL) {
		cout << st->data;
		st = st->next;
	}
	cout << endl;
}
void main() {
	setlocale(LC_CTYPE, "Rus");
	Stack* myStk = new Stack;
	myStk->head = NULL;
	int Choise;
	for (;;) {
		cout << " 1. Добавить элемент стека" << endl;
		cout << " 2. Вывести содержимое стека" << endl;
		cin >> Choise;
		switch (Choise) {
		case 1: push(myStk);
			break;
		case 2: snow(myStk);
			break;
		}
	}
}