#include<iostream>
#include<algorithm>
using namespace std;
void func(int A,int start,int end1)
{
	if (start == end1) { return; }
	int k = start,h = 0;
	while (k != 0) 
	{
		int f = k % 10;
		k /= 10;
		if (f > A) { h++; }
	}
	if (h == 0) { cout << start<<endl; }
	func(A,start+1,end1);
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "¬ведите A : ";
	int A;
	cin >> A;
	int start,end1;
	start = pow(10, A - 1);
	end1 = (A+1)*pow(10, A-1);
	func(A,start,end1);
}