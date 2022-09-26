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
		cout << "1 - ���� ������" << endl;
		cout << "2 - ����� ������" << endl;
		cout << "3 - ����� �� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "������� ����� ��������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {	cout << "���-�� ���������" << endl;
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
			cout << "�������: "; cin >> buf.fio;
			cout << "������: "; cin >> buf.group;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "������ �������� �����";
		return;
	}
}

void output()
{
	STUD buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		cout << "\n�������   ������\n";
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
		cout << "������ �������� �����";
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
				cout << "\n�������    ������\n";
				cout << buf.fio << "\t    " << buf.group << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "������ �� �������\n";
	}
	else {
		cout << "������ �������� �����";
		return;
	}
}