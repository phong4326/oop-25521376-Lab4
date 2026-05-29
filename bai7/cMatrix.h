#ifndef CMATRIX_H
#define CMATRIX_H

#include<iostream>
#include<vector>
#include"cVector.h"

class cMatrix
{
private:
    std::vector<std::vector<double>> data;
    int row, col;
    void checkBound(int i, int j) const;
public:
    cMatrix();
    cMatrix(int m, int n, double val = 0.0);            // m×n khoi tao = val
    cMatrix(const std::vector<std::vector<double>>& v); // tu mang 2D
    cMatrix(const cMatrix& other)            = default;
    cMatrix& operator=(const cMatrix& other) = default;
    ~cMatrix()                               = default;
    
    //-----Static factories-----
    static cMatrix identity(int n);                     // ma tran don vi n×n
    static cMatrix zeros(int m, int n);                 // ma tran 0

    //-----Getter-----
    int getRow() const;
    int getCol() const;
    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    cMatrix operator+(const cMatrix& B) const;          // A + B
    cMatrix operator-(const cMatrix& B) const;          // A - B
    cMatrix operator*(double scalar)    const;          // A * k
    friend cMatrix operator*(double scalar, const cMatrix& A); // k * A

    //viet mot cVector de nhan thay vi cho vector la ma tran (nx1)
    //thuan tien hon vi ko can ep kieu, friendly cache, truy xuat nhanh hon vector<vector<double>>
    cVector operator*(const cVector& v) const;

    cMatrix operator*(const cMatrix& v) const;

    // toan tu so sanh
    bool operator==(const cMatrix& B) const;
    bool operator!=(const cMatrix& B) const;
 
    // ── Bien đoi ma tran 
    cMatrix transpose() const;                          // Aᵀ
 
    // Xuat
    void print(const std::string& name = "") const;
    friend std::ostream& operator<<(std::ostream& out, const cMatrix& A);
    friend std::istream& operator>>(std::istream& in, cMatrix& A);
};

#endif