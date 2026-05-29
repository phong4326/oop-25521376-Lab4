#ifndef CPHANSO_H
#define CPHANSO_H

#include<iostream>

class cPhanSo
{
private:
    int x, y;
public:
    cPhanSo(int x = 0, int y = 1);
    void rutGon();
    friend std::istream& operator>>(std::istream& in, cPhanSo& a);
    friend std::ostream& operator<<(std::ostream& out, const cPhanSo& a);
    cPhanSo operator+(const cPhanSo& other) const;
    cPhanSo operator-(const cPhanSo& other) const;
    cPhanSo operator*(const cPhanSo& other) const;
    cPhanSo operator/(const cPhanSo& other) const;
    bool operator>(const cPhanSo& other) const;
    bool operator<(const cPhanSo& other) const;
    bool operator==(const cPhanSo& other) const;
};

#endif