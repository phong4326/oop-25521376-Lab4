#include"cTime.h"
#include<iostream>

using namespace std;

int main() {
    cTime a;
    try {
        cout << "Nhap thoi gian (hh mm ss): "; 
        cin >> a;
    } catch (const invalid_argument &e) {
        cout << "\n[LOI HE THONG]: " << e.what();
        return 1;
    }
    cout << "Thoi gian hien tai la: " << a;

    cout << "\nThoi gian cong them 54000s: " << a + 54000;
    cout << "\nThoi gian tru di 54000s: " << a - 54000;

    cout << "\nCong tien to: " << ++a;
    cout << "\nCong hau to (a++): ";
    cTime b = a++; 
    cout << b << " | Thoi gian sau do: " << a;

    cout << "\nTru tien to: " << --a;
    cout << "\nTru hau to (a--): ";
    cTime c = a--;
    cout << c << " | Thoi gian sau do: " << a;
    return 0;
}