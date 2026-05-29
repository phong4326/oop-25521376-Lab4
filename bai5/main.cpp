#include"cDaThuc.h"

using namespace std;

int main() {
    cDaThuc f, _f;

    cout << "Nhap da thuc f: \n"; cin >> f;
    cout << "f(x) = " << f;
    cout << "\nNhap da thuc f': \n"; cin >> _f;
    cout << "f'(x) = " << _f;

    cDaThuc tong = f + _f;
    cDaThuc hieu = f - _f;
    cout << "\nf(x) + f'(x) = " << tong;
    cout << "\nf(x) - f'(x) = " << hieu;

    double x;
    cout << "\nNhap gia tri cua x de tinh f(x): "; cin >> x;
    cout << "f(" << x << ") = " << f(x);
    return 0;
}