#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>   
using namespace std;
unsigned int f(unsigned int m, unsigned int n)
{
    if (m == 0 || n == 0)
    {
        return n + 1;
    }
    else
    {
        return f(m - 1, f(m, n - 1));
    }
}
using namespace std;
double sumCos(double x, int n)
{
    if (n == 1)
        return cos(x);
    else
        return sumCos(x, n - 1) + cos(n * x);
}
string Abracadabra(string u, int n)
{
    char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    
    u.insert(u.begin(),alphabet[n]);   
    if (n == 26)
        return u;
    else
        return Abracadabra(u.append(u),n + 1);
}
void osn1() {
    double x;
    cout << "Enter x: ";
    cin >> x;


    int n;
    cout << "Enter n: ";
    cin >> n;

    double y = sumCos(x, n);
    cout << "y = " << y << endl;
}
void osn2() {
    int x;
    cout << "Enter x: ";
    cin >> x;


    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << f(x, n) << endl;
}
void dop4() {
    string z = "";
    string u = Abracadabra(z, 0);
    cout << u[20] << endl;
}