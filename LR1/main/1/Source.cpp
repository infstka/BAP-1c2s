#include <iostream>
using namespace std;
double Dihotomia(double b, double (*fun)(double));
double fun1(double x);
double fun2(double x);

int main() {
    double b;
    cin >> b;
    cout << "func 1" << endl;
    Dihotomia(b, fun1);
    cout << "func 2" << endl;
    Dihotomia(b, fun2);
    return 0;
}

double fun1(double x) {

    return cos(x) + x - 7;
}

double fun2(double x) {

    return exp(x) - 1 / x;
}

double Dihotomia(double b, double (*fun)(double)) {
    double a, c, e = 0.001;
    a = 0;
    while (b - a > e) {
        c = (a + b) / 2;
        if (fun(b) * fun(c) < 0)
            a = c;
        else
            b = c;
    }
    cout << (a + b) / 2 << endl;
    return 0;
}
