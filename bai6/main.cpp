#include"cVector.h"
#include<iostream>

using namespace std;

int main() {
    cout << "-----TESTING CONSTRUCTOR-----\n";
    cVector v_default;
    cVector v_3d(3, 1.5);
    cVector v_init = {1.0, 2.0, 3.0};
    cVector v_copy(v_init);
    cout << "Vector mac dinh: " << v_default;
    cout << "\nVector 3D (val = 1.5): " << v_3d;
    cout << "\nVector khoi tao list: " << v_init;
    cout << "\nVector sao chep: " << v_copy;

    // test I/O va toan tu truy cap chi so []
    cout << "\n-----TESTING INPUT/OUTPUT & INDEX OPERATOR-----\n";
    cVector v1, v2;
    cout << "Nhap thong tin cho Vector 1: ";
    cin >> v1; // Ví dụ nhập: 3 chiều [1, 0, 0]
    cout << "Nhap thong tin cho Vector 2: ";
    cin >> v2; // Ví dụ nhập: 3 chiều [0, 1, 0]
    cout << "Vector 1 vua nhap: " << v1 
         << " (So chieu: " << v1.size() << ")";
    cout << "\nVector 2 vua nhap: " << v2 
         << " (So chieu: " << v2.size() << ")";
    // if (v1.size() > 0) {
    //     v1[0] = 5.0;
    //     cout << "\nVector sau khi thay doi toa do: " << v1;
    // }

    //test cac phep toan so hoc
    //boc vao try đe chu đong theo doi cac phep toan co nguy co loi
    try {
        cout << "\nv1 + v2 = " << (v1 + v2);
    } 
    catch (const invalid_argument& e) {
        //neu phat hien loi lech sa chieu, chay lenh o đay thay vi đe may bi crash
        cout << "[DA CHAN LOI]: " << e.what();
    }

    //boc tuong tu cho phep tru de phong dinh loi
    try {
        cout << "\nv1 - v2 = " << (v1 - v2);
    }
    catch (const invalid_argument& e) {
        cout << "[DA CHAN LOI]: " << e.what();
    }

    cout << "\nv1 * (-2) = " << v1 * -2; //vector * so thuc
    cout << "\nv1 / 2 = " << v1 / 2; //so thuc * vector

    try {
        cVector v_temp = v1;
        v_temp += v2;
        cout << "\nv1 += v2 -> " << v_temp;
    }
    catch (const invalid_argument& e) {
        cout << " [DA CHAN LOI]: " << e.what();
    }

    // test cac dac trung hinh hoc
    cout << "\nDo dai vector v1 (norm): " << v1.norm();
    cout << "\n----TESTING GEOMETRIC----\n";
    try {
        cout << "\nTich vo huong (v1 dot v2): " << v1.dot(v2);
    }
    catch (const invalid_argument& e) {
        cout << " [DA CHAN LOI]: " << e.what();
    }
    
    if (v1.norm() > 0) {
        cout << "\nVector don vi cua v1 (normalize): " << v1.normalize();
    }

    //tinh goc va kiem tra trang thai hinh hoc
    try {
        double rad = v1.angle(v2);
        cout << "\nGoc giua v1 va v2 (Radian): " << rad;
        cout << "\nGoc giua v1 va v2 (Degree): " << rad * 180 / M_PI << " °C";
    } catch (const std::exception& e) {
        cout << "\nLoi khi tinh goc giua hai vector: " << e.what();
    }

    cout << "\nv1 co vuong goc voi v2 khong? " << (v1.isOrthogonal(v2) ? "CO" : "KHONG");
    cout << "\nv1 co song song voi v2 khong? " << (v1.isParallel(v2) ? "CO" : "KHONG");

    cout << "\n-----TESTING CROSS PRODUCT-----\n";
    try {
        cVector crossRes = v1.cross(v2);
        cout << "Tich co huong [v1 x v2] = " << crossRes;
    } catch (const exception& e) {
        cout << "Loi tich co huong: " << e.what();
    }
    
    cout << "\n-----TESTING SAFETY-----\n";
    
    // Bay loi 1: Goi ham at() vuot bien
    try {
        cout << "Co tinh truy cap v1.at(99): ";
        cout << v1.at(99);
    } catch (const out_of_range& e) {
        cout << "[DA CHAN] " << e.what();
    }

    // Bay loi 2: Chia cho so 0
    try {
        cout << "\nCo tinh chia v1 / 0: ";
        cVector failDiv = v1 / 0.0;
    } catch (const runtime_error& e) {
        cout << "\n[DA CHAN] " << e.what();
    }

    // Bay loi 3: Cong 2 vector lech so chieu
    try {
        cout << "\nCo tinh cong Vector 2 chieu voi Vector 3 chieu: ";
        cVector v_2d(2, 1.0);
        cVector failAdd = v_2d + v1;
    } catch (const invalid_argument& e) {
        cout << "\n[DA CHAN] " << e.what();
    }

    cout << "\n-----THE PROGRAM CONCLUDED SAFELY!----";
    return 0;
}

// test1
// 2
// 3.0 4.0
// 2
// 1.0 2.0

//test2
// 3
// 1.0 0.0 0.0
// 3
// 0.0 1.0 0.0

//test3
// 2
// 1.5 2.5
// 2
// 3.0 5.0

//test4
// 4
// 1.0 1.0 1.0 1.0
// 4
// -2.0 -2.0 -2.0 -2.0

//test5
// 3
// 0.5 -0.25 0.0
// 3
// 2.0 4.0 -1.5

//test6
// 1
// -5.5
// 1
// 2.0

//test7
// doi cho nhan thanh -2 chia 2

//test8
// 2
// 1.0 2.0
// 3
// 1.0 2.0 3.0

//test9
// 3
// 0.0 0.0 0.0
// test voi so 0 -> loi

//test10
//doi phep chia thanh chia cho 0.0