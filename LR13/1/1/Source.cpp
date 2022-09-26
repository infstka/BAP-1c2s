#include<iostream>
#include<algorithm>
using namespace std;
	int Heap[2048];
	int HeapSize = 0;
	int Heap1[2048];
	int HeapSize1 = 0;
	void insert_elem(int n) {
		int i, parent;
		i = HeapSize;
		Heap[i] = n;
		parent = (i - 1) / 2;
		while (parent >= 0 && i > 0) {
		
			if (Heap[i] > Heap[parent]) 
			{
				swap(Heap[i], Heap[parent]);
			}
			i = parent;
			parent = (i - 1) / 2;
		}
		HeapSize++;
	}
	void insert_elem1(int n) {
		int i, parent;
		i = HeapSize1;
		Heap1[i] = n;
		parent = (i - 1) / 2;
		while (parent >= 0 && i > 0) {

			if (Heap1[i] > Heap1[parent])
			{
				swap(Heap1[i], Heap1[parent]);
			}
			i = parent;
			parent = (i - 1) / 2;
		}
		HeapSize1++;
	}
	void PrintHeap1() {
		int i = 0;
		int k = 1;
		while (i < HeapSize1) {

			while ((i < k) && (i < HeapSize1)) {
				cout << Heap1[i] << ' ';
				i++;
			}
			cout << endl;
			k = k * 2 + 1;
		}

	}
	void PrintHeap() {
		int i = 0;
		int k = 1;
		while (i < HeapSize) {
		
			while ((i < k) && (i < HeapSize)) {
				cout << Heap[i] << ' ';
				i++;
			}
			cout << endl;
			k = k * 2 + 1;
		}
	
	}
	void HeapOut() {
		for (int i = 0; i < HeapSize; i++) 
		{
			cout << Heap[i] << ' ';
		}
		cout << endl;
	}
	void Heapify(int i) {
		int left, right;
		left = i * 2 + 1;
		right = i * 2 + 2;
		if (left < HeapSize) {
		
			if (Heap[i] < Heap[left]) 
			{
				swap(Heap[i], Heap[left]);
				Heapify(right);
			}
		
		}
	
	}
	void HeapifyUp(int i) {
		int parent;
		parent = (i - 1) / 2;
		if (Heap[i] > Heap[parent]) 
		{
			swap(Heap[i], Heap[parent]);
			Heapify(parent);
		}
	
	
	}
	int DeleteMax() {
		int x;
		x = Heap[0];
		Heap[0] = Heap[HeapSize - 1];
		HeapSize--;
		Heapify(0);
		return x;
	}
	int level() {
		int i = HeapSize;
		int level = 0;
		int parent = (i - 1) / 2;
		while (parent >= 0 && i > 0) {

			
			i = parent;
			parent = (i - 1) / 2;
			level++;
		}
		return level;
	}
	int DeleteMin() {
		int h = level();
		int k = 0;
		for (int i = 0; i < h - 1; i++) 
		{
			k = k * 2 + 1;
		}
		int k_next = k * 2 + 1;
		int skip_el = (HeapSize - k_next + 1) / 2;
		int number = k, value = Heap[k];
		for (int i = k + skip_el; i < HeapSize; i++) 
		{
			if (Heap[i] < value) {
				value = Heap[i];
				number = i;
			}
		}
		if (number == HeapSize - 1) 
		{
			HeapSize--;
			return value;
		}
		for (int i = number; i < HeapSize-1; i++) 
		{
			swap(Heap[i],Heap[i+1]);
		}
		HeapSize--;
		for (int i = k; i < HeapSize; i++) 
		{
			HeapifyUp(i);
		}
		return value;
	}
	int DeleteI(int i) {
		int x;
		x = Heap[i-1];
		if (i == HeapSize) 
		{
			HeapSize--;
			return x;
		}
		Heap[i-1] = Heap[HeapSize - 1];
		HeapSize--;
		Heapify(i-1);
		return x;

	}
	void MergeHeaps() {
		for (int i = 0; i < HeapSize1; i++) {
			insert_elem(Heap1[i]);
		}
		cout << "Слияние куч произошло успешно." << endl;
	}
void main() {
	setlocale(LC_CTYPE, "Russian");
	int choice=0;
	for (;;)
	{
		int n;
		cout << "1 - добавить элемент" << endl;
		cout << "2 - вывод кучи на экран" << endl;
		cout << "3 - вывод значений кучи на экран в строку" << endl;
		cout << "4 - удалить максимальный элемент" << endl;
		cout << "5 - Вывод количества уровней кучи" << endl;
		cout << "6 - Удаление элемента под номером i" << endl;
		cout << "7 - Удаление минимального элемента кучи" << endl;
		cout << "8 - Добавление элемента к второй кучи" << endl;
		cout << "9 - Вывод на экран второй кучи" << endl;
		cout << "10 - Задание слияния второй кучи с первой" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  cout << "Введите добавляемое значение :";  cin >> n; insert_elem(n); break;
		case 2:PrintHeap(); break;
		case 3:  HeapOut(); break;
		case 4: cout << "Максимальный элемент кучи который был удалён :" << DeleteMax() << endl; break;
		case 5: cout << "Количество заполненных уровней кучи равно :" << level()<<endl; break;
		case 6: cout << "Введите номер элемента который хотите удалить :"; cin >> n; cout<<"Удалённый элемент под номером "<<n<<" был "<<DeleteI(n)<<endl; break;
		case 7: cout << "Значение удалённого минимального элемента :" << DeleteMin() << endl; break;
		case 8:  cout << "Введите добавляемое значение :";  cin >> n; insert_elem1(n); break;
		case 9:PrintHeap1(); break;
		case 10: MergeHeaps(); PrintHeap(); break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	}
	
	
	return;
}