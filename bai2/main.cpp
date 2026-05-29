#include "cPhanSo.h"
#include <iostream>

using namespace std;

int main() {
    cPhanSo a, b;
    
    try {
        cout << "Nhap phan so a (tu mau): "; 
        cin >> a;
        cout << "Nhap phan so b (tu mau): "; 
        cin >> b;
    } 
    catch (const invalid_argument &e) {
        cout << "\n[LOI NHAP LIEU]: " << e.what() << endl;
        return 1;
    }

    cout << "\n--- KET QUA CAC PHEP TOAN ---" << endl;
    
    cout << "Phan so a + b = " << a + b << endl;
    cout << "Phan so a - b = " << a - b << endl;
    cout << "Phan so a * b = " << a * b << endl;

    try {
        cout << "Phan so a / b = " << a / b << endl;
    } 
    catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    cout << "\n--- KET QUA SO SANH ---" << endl;
    if (a == b) cout << "Phan so a = phan so b\n";
    if (a > b)  cout << "Phan so a > phan so b\n";
    if (a < b)  cout << "Phan so a < phan so b\n";

    cout << "\n=== CHUONG TRINH KET THUC AN TOAN! ===" << endl;
    return 0;
}