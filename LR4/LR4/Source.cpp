#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char lastName[]);

typedef struct Students {
	char fio[16];
	char group[3];
} STUD;
int number; FILE* f; errno_t err;


int main() {
	setlocale(LC_CTYPE, "Russian");
	int choice; char fio[16];
	do
	{
		cout << "1 - Ввод данных" << endl;
		cout << "2 - Вывод данных" << endl;
		cout << "3 - Поиск по фамилии" << endl;
		cout << "0 - Выход" << endl;
		cout << "Введите номер операции" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {	cout << "Кол-во студентов" << endl;
			cin >> number;
			input(number);
			break;
		} break;
		case 2: output(); break;
		case 3: {	cout << "vvod fio";
			cin >> fio;
			find(fio); break;
		} break;
		case 0: exit(0); break;
		}
	} while (choice != 0);
	return 0;
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "base.bin", "ab")) {
		for (int p = 0; p < size; p++)
		{
			cout << "Фамилия: "; cin >> buf.fio;
			cout << "Группа: "; cin >> buf.group;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	STUD buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		cout << "\nФамилия   Группа\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.fio << "\t    " << buf.group << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void find(char lastName[]) {
	bool flag = false; STUD buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.fio) == 0)
			{
				cout << "\nФамилия    Группа\n";
				cout << buf.fio << "\t    " << buf.group << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}