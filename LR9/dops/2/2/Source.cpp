#include<iostream>
#include<algorithm>
using namespace std;
struct item
{
	int value;
	char fname[30] = {};
	char sname[30] = {};
	char thname[30] = {};
	int year;
	int course;
	int group;
	int marks[5];
	float middle_mark = 0;

	item* next;
	item* prev;

};
item* plist = NULL;
item* p;
item* plist1 = NULL;
item* p1;
int count1 = 0;//������� ���� ���������
int counter = 1;//��� ������� ������
void add()//�������� �������(��������)
{
	cout << "<------------------------------------------------>" << endl;
	char fname[50];
	char sname[50];
	char thname[50];
	cout << "������� ��� �������� :";
	cin >> fname >> sname >> thname;
	int year;

	cout << "������� ��� �������� :";
	cin >> year;
	int group, course, marks[5];
	cout << "������� ���� � ����� ������ :";
	cin >> course >> group;
	for (int i = 0; i < 5; i++)
	{
		cout << "������� ������ ����� �" << i + 1 << " :";
		cin >> marks[i];
	}
	p = new item;
	for (int i = 0; i < strlen(fname); i++)
	{
		p->fname[i] = fname[i];
	}
	for (int i = 0; i < strlen(sname); i++)
	{
		p->sname[i] = sname[i];
	}
	for (int i = 0; i < strlen(thname); i++)
	{
		p->thname[i] = thname[i];
	}
	p->year = year;
	p->course = course;
	p->group = group;
	for (int i = 0; i < 5; i++)
	{
		p->marks[i] = marks[i];
		p->middle_mark += marks[i];
	}
	p->middle_mark /= 5;
	p->next = plist;
	p->prev = NULL;
	if (p->next != NULL)
	{
		item* previ;
		previ = p;
		p = p->next;
		p->prev = previ;
		p = previ;
	}
	plist = p;
	count1++;
	cout << "������� ��� ������� �������� � ������ ������." << endl;
	cout << "<------------------------------------------------>" << endl;
	return;
}
void Sort()
{
	cout << "<------------------------------------------------>" << endl;
	int val = count1 - 1;
	for (int i = 0; i < count1; i++)
	{
		item* host1 = p;
		item* host2 = p->next;
		for (int j = 0; j < val; j++)
		{
			if (host1->course < host2->course)
			{
				swap(host1->fname, host2->fname);
				swap(host1->sname, host2->sname);
				swap(host1->thname, host2->thname);
				swap(host1->course, host2->course);
				swap(host1->group, host2->group);
				swap(host1->year, host2->year);
				swap(host1->marks, host2->marks);
				swap(host1->middle_mark, host2->middle_mark);
			}
			host1 = host1->next;
			host2 = host2->next;
		}
		val--;
	}
	cout << "���������� ��������� �������!" << endl;
	cout << "<------------------------------------------------>" << endl;
}
void write()
{
	cout << "<------------------------------------------------>" << endl;
	item* host = p;
	for (int i = 0; i < count1; i++)
	{
		cout << "��� : " << host->fname << " " << host->sname << " " << host->thname << endl;
		cout << "��� �������� : " << host->year << " ���� : " << host->course << " ������ : " << host->group << endl;
		cout << "������ : " << host->marks[0] << " " << host->marks[1] << " " << host->marks[2] << " " << host->marks[3] << " " << host->marks[4] << endl;
		host = host->next;
	}
	cout << "<------------------------------------------------>" << endl;
}

void better_student()
{
	cout << "<------------------------------------------------>" << endl;
	item* host = p;
	int max_mark = host->middle_mark;
	item* better = host;
	for (int i = 0; i < count1; i++)
	{
		if (max_mark < host->middle_mark)
		{
			max_mark = host->middle_mark;
			better = host;
		}
		host = host->next;
	}
	cout << "��� ������� �������� :" << better->fname << " " << better->sname << " " << better->thname << endl;
	cout << "<------------------------------------------------>" << endl;
}
void max_min_year()
{
	cout << "<------------------------------------------------>" << endl;
	item* host = p;
	int ma = host->year;
	int mi = host->year;
	item* mi_st = host;
	item* ma_st = host;
	for (int i = 0; i < count1; i++)
	{
		if (ma < host->year)
		{
			ma = host->year;
			ma_st = host;
		}
		if (mi > host->year)
		{
			mi = host->year;
			mi_st = host;
		}
		host = host->next;
	}

	cout << "����� ������� ������� : " << mi_st->fname << " " << mi_st->sname << " " << mi_st->thname << endl;
	cout << "����� ������� ������� : " << ma_st->fname << " " << ma_st->sname << " " << ma_st->thname << endl;
	cout << "<------------------------------------------------>" << endl;
}
void middle_groups()
{
	cout << "<------------------------------------------------>" << endl;
	item* ho = p;
	for (int i = 0; i < count1; i++)
	{
		p1 = new item;
		for (int i = 0; i < strlen(ho->fname); i++)
		{
			p1->fname[i] = ho->fname[i];
		}
		for (int i = 0; i < strlen(ho->sname); i++)
		{
			p1->sname[i] = ho->sname[i];
		}
		for (int i = 0; i < strlen(ho->thname); i++)
		{
			p1->thname[i] = ho->thname[i];
		}
		p1->year = ho->year;
		p1->course = ho->course;
		p1->group = ho->group;
		for (int i = 0; i < 5; i++)
		{
			p1->marks[i] = ho->marks[i];
		}
		p1->middle_mark = ho->middle_mark;
		p1->next = plist1;
		p1->prev = NULL;
		if (p1->next != NULL)
		{
			item* previ;
			previ = p1;
			p1 = p1->next;
			p1->prev = previ;
			p1 = previ;
		}
		plist1 = p1;
		ho = ho->next;
	}

	int val = count1 - 1;
	for (int i = 0; i < count1; i++)
	{
		item* host11 = p1;
		item* host22 = p1->next;
		for (int j = 0; j < val; j++)
		{
			if (host11->group < host22->group)
			{
				swap(host11->fname, host22->fname);
				swap(host11->sname, host22->sname);
				swap(host11->thname, host22->thname);
				swap(host11->course, host22->course);
				swap(host11->group, host22->group);
				swap(host11->year, host22->year);
				swap(host11->marks, host22->marks);
				swap(host11->middle_mark, host22->middle_mark);
			}
			host11 = host11->next;
			host22 = host22->next;

		}
		val--;
	}

	item* host = p1;
	/*item* host5 = p1;
	for (int i = 0; i < count1; i++)
	{

		cout << "��� : " << host5->fname << " " << host5->sname << " " << host5->thname << endl;
		cout << "��� �������� : " << host5->year << " ���� : " << host5->course << " ������ : " << host5->group << endl;
		cout << "������ : " << host5->marks[0] << " " << host5->marks[1] << " " << host5->marks[2] << " " << host5->marks[3] << " " << host5->marks[4] << endl;
		host5 = host5->next;
	}
	cout << "---------------------" << endl;*/
	item* best = host;
	int ma = host->middle_mark, gr = host->group;
	for (int i = 0; i < count1; i++)
	{
		if (host->group != gr)
		{
			cout << "������� ������ �" << gr << " ������ : " << best->fname << " " << best->sname << " " << best->thname << endl;
			gr = host->group;
			ma = host->middle_mark;
			best = host;
		}
		if (ma < host->middle_mark)
		{
			ma = host->middle_mark;
			gr = host->group;
			best = host;
		}
		if (i != count1 - 1)host = host->next;
	}
	if (ma < host->middle_mark)
	{
		ma = host->middle_mark;
		gr = host->group;
		best = host;
	}
	cout << "������� ������ �" << gr << " ������ : " << best->fname << " " << best->sname << " " << best->thname << endl;



	cout << "<------------------------------------------------>" << endl;
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	int c;
	do {
		cout << "��� ����������� ������?" << endl;
		cout << "1 - ���������� ��������." << endl;
		cout << "2 - ����� ���� ���������." << endl;
		cout << "3 - ���������� � ������� ������." << endl;
		cout << "4 - ������ ������� �� ������������." << endl;
		cout << "5 - ����� ������� � ������� �������." << endl;
		cout << "6 - ������� ���� �� �������." << endl;
		cout << "7 - �����." << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			add();
			break;
		case 2:
			write();
			break;
		case 3:
			Sort();
			break;
		case 4:
			better_student();
			break;
		case 5:
			max_min_year();
			break;
		case 6:
			middle_groups();
			break;
		case 7:
			cout << "�� ����� ������" << endl;
			break;
		default:
			cout << "������������ ������, ��������� ����������." << endl;
			break;
		}

	} while (c != 7);
}
