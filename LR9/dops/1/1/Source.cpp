#include <iostream>
#include <fstream>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. ???? ?????" << endl;
	cout << "2. ???????? ?????" << endl;
	cout << "3. ????? ?? ?????" << endl;
	cout << "4. ?????" << endl;
	cout << "5. ?????" << endl;
	cout << endl;
	do
	{
		cout << "??? ?????: ";
		std::cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 5);
	return c;
}
//-----------------------------------------------------------
// ?????????? ? ????? ?????? 9 ???????
void insert(Address* e, Address** phead, Address** plast) //?????????? ? ????? ??????
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // ???????? ???????? ? ???? ??? ???????? ? ?????????? 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cout << "?????? ????????? ?????? ??????";
		return NULL;
	}
	cout << "??????? ???: ";
	std::cin.getline(temp->name, NAME_SIZE - 1, '\n');
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.clear();
	cout << "??????? ?????: ";
	std::cin.getline(temp->city, CITY_SIZE - 1, '\n');
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //????? ?????? ?? ?????
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // ????? ????? ? ??????
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cout << "??? ?? ???????" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast) // ???????? ????? 
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "??? ?? ???????" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "??????? ??????" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead)       //?????? ? ????
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "???? ?? ???????????" << endl;
		exit(1);
	}
	cout << "?????????? ? ????" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)          //?????????? ?? ?????
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "???? ?? ???????????" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "???????? ?? ?????" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "?????? ????????? ??????" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}


int main()
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "??????? ???: ";
			std::cin.getline(dname, NAME_SIZE - 1, '\n');
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {
			char fname[NAME_SIZE];
			cout << "??????? ???: ";
			std::cin.getline(fname, NAME_SIZE - 1, '\n');
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.sync();
			find(fname, &head);
			break;
		}
		case 5:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}