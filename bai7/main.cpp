#include "cMatrix.h"
#include "cVector.h"
#include <iostream>

using namespace std;

int main() {
    // Khởi tạo an toàn bằng khối try-catch đề phòng dữ liệu tĩnh lỗi
    cMatrix a, c;
    // nhap ma tran muon test
    try {
        a = cMatrix({{100.123, 2, 3},
                     {4, 50, 6}});
        c = cMatrix({{50.12, 6, 1},
                     {0, 45, 6}});
    } catch (const exception& e) {
        cout << "Loi khoi tao ma tran ban dau: " << e.what() << endl;
        return 1;
    }

    cout << "Ma tran A co " << a.getRow() << " hang va " << a.getCol() << " cot\n";
    a.print("A");
    try {
        cout << a(2,3);
    } catch (const exception& e) {
        cout << "Loi truy cap " << e.what();
        return 1;
    }
    cMatrix b;
    try {
        cout << "--- Nhap Ma Tran B ---\n";
        cin >> b;
        cout << "\nMa tran B vua nhap:\n" << b;
    } catch (const exception& e) {
        cout << e.what();
        return 1;
    }

    // 1. Test tich ma tran x vector
    cout << "\n--- TEST: Ma tran A x vector v ---\n";
    try {
        cVector v({1, 0, -1});
        v.print("V");
        (a * v).print("A x V");
    } catch (const exception& e) {
        cout << "[DA CHAN LOI AxV]: " << e.what() << endl;
    }

    // 2. Test tich ma tran x ma tran
    cout << "--- 2. TEST: Ma tran A x Ma tran B ---\n";
    try {
        cMatrix res = a * b;
        res.print("A x B");
    } catch (const exception& e) {
        cout << "[DA CHAN LOI AxB]: " << e.what() << endl;
    }

    // 3. Chuyen vi
    cout << "--- TEST: Chuyen vi Ma tran Aᵀ ---\n";
    try {
        a.transpose().print("Aᵀ");
    } catch (const exception& e) {
        cout << "[LOI CHUYEN VI]: " << e.what() << endl;
    }

    // 4. Cac phep toan cong, tru, nhan vo huong
    cout << "--- TEST: Cac phep toan dai so ---\n";
    try {
        (a + c).print("A + C");
    } catch (const exception& e) {
        cout << "[LOI PHEP CONG]: " << e.what() << endl;
    }

    try {
        (a - c).print("A - C");
    } catch (const exception& e) {
        cout << "[LOI PHEP TRU]: " << e.what() << endl;
    }

    try {
        (a * 2.5).print("A x 2.5");
    } catch (const exception& e) {
        cout << "[LOI NHAN VO HUONG]: " << e.what() << endl;
    }

    // 5. Ma tran dac biet
    cout << "\n--- TEST: Khoi tao Ma tran dac biet ---\n";
    try {
        cMatrix I = cMatrix::identity(3);
        I.print("Ma tran don vi I3");

        cMatrix P = cMatrix::zeros(3, 3);
        P.print("Ma tran khong P (3x3)");
    } catch (const exception& e) {
        cout << "[LOI MA TRAN DAC BIET]: " << e.what() << endl;
    }
    return 0;
}