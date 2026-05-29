#include"cSoPhuc.h"

using namespace std;

int main() {
    cSoPhuc a, b;
    cout << "Nhap so phuc a: "; cin >> a;
    cout << "Nhap so phuc b: "; cin >> b;
    cout << "hai so phuc vua nhap la: \n";
    cout << "a = " << a << " va b = " << b << endl;
    cout << "ket qua phep toan cong a + b: " << a + b << endl;
    cout << "ket qua phep toan tru a - b: " << (a - b) << endl;
    cout << "ket qua phep toan nhan a * b: " << (a * b) << endl;
    try {
        cout << "ket qua phep toan chia a / b: " << (a / b) << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what();
    }
    cout << "so phuc a bang so phuc b? " << boolalpha << (a == b) << endl;
    cout << "so phuc a khac so phuc b? " << boolalpha << (a != b);
    return 0;
} 