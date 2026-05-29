#include"cDate.h"
#include<iostream>

using namespace std;

int main() {
    cDate a;
    try {
        cout << "Nhap ngay hien tai (dd mm yyyy): "; 
        cin >> a;
    } 
    catch (const invalid_argument &e) {
        cout << e.what();
        return 1;
    }
    cout << "Ngay hien tai la: " << a;
    cout << "\nNgay thang khi cong them 100 ngay la: " << a + 100;
    cout << "\nNgay thang khi tru di 100 ngay la: " << a - 100;
    cout << "\n-----------------------------------------\n";

    cout << "Cong tien to (++a): " << ++a;
    cout << "\nCong hau to (a++): ";
    cDate b = a++;
    cout << b << " Ngay sau do: " << a;

    cout << "\nTru tien to (--a): " << --a;
    
    cout << "\nTru hau to (a--): ";
    cDate c = a--;
    cout << c << " Ngay sau do: " << a;

    cout << "\n-----CHUONG TRINH KET THUC AN TOAN-----";
    return 0;
}