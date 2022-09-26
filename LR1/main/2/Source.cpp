#include <iostream>
#include <stdarg.h>
using namespace std;

void prost(int n, ...);


int main() {
    cout << "first call" << endl;
    prost(2, 1, 7, 5, 11);
    cout << "second call" << endl;
    prost(3, 1, 7, 5, 11, 1, 11);
    cout << "third call" << endl;
    prost(1, 4, 100);
    return 0;
}

void prost(int n, ...) {
    va_list factor;
    va_start(factor, n);
    for (int i = 1; i <= n; i++) {
        int j = (va_arg(factor, int));
        int m = (va_arg(factor, int));
        for (; j < m; j++) {
            bool flag = false;
            for (int h = 2; h < j; h++) {
                if (j % h == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    va_end(factor);
    cout << endl;
}