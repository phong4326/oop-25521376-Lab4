#ifndef CSOPHUC_H
#define CSOPHUC_H

#include<iostream>

class cSoPhuc
{
private:
    double x, y;
public:
    cSoPhuc(double x = 0, double y = 0);
    friend std::istream& operator>>(std::istream& in, cSoPhuc& a);
    friend std::ostream& operator<<(std::ostream& out, const cSoPhuc& a);
    cSoPhuc operator+(const cSoPhuc& other) const;
    cSoPhuc operator-(const cSoPhuc& other) const;
    cSoPhuc operator*(const cSoPhuc& other) const;
    cSoPhuc operator/(const cSoPhuc& other) const;
    bool operator==(const cSoPhuc& other) const;
    bool operator!=(const cSoPhuc& other) const;
};

#endif