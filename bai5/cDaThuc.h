#ifndef CDATHUC_H
#define CDATHUC_H

#include<iostream>
#include<vector>
#include<cmath>
//bai nay dung operator la qua hop ly roi
class cDaThuc
{
private:
    int n;              //bac cua da thuc
    std::vector<int> a; //cac he so cua da thuc
public:
    cDaThuc(int bac = 0);
    double operator()(double x) const;

    cDaThuc operator+(const cDaThuc& other) const;
    cDaThuc operator-(const cDaThuc& other) const;

    friend std::istream& operator>>(std::istream& in, cDaThuc& dt);
    friend std::ostream& operator<<(std::ostream& out, const cDaThuc& dt);
    ~cDaThuc() {}
};

#endif