#ifndef CVECTOR_H
#define CVECTOR_H

#include<vector>
#include<iostream>
#include<cmath>
#include<initializer_list>

class cVector
{
private:
    std::vector<double> data;
    int n;
public:
    //constructor
    cVector();
    cVector(int n);
    cVector(int n, double val);
    cVector(std::initializer_list<double> list);
    cVector(const cVector& other);

    //getter
    int size() const;
    double& operator[](int i);
    const double& operator[](int i) const;
    double at(int i) const;

    //arithemtic operator
    cVector operator+(const cVector& o) const;
    cVector operator-(const cVector& o) const;
    cVector operator*(double scalar) const;
    cVector operator/(double scalar) const;
    friend cVector operator*(double scalar, const cVector& v);

    //compound assignment
    cVector& operator+=(const cVector& o);
    cVector& operator-=(const cVector& o);
    cVector& operator*=(double scalar);

    //comparison
    bool operator==(const cVector& o) const;
    bool operator!=(const cVector& o) const;

    //vector operations
    double dot(const cVector& o) const;
    double norm() const;
    double normSquared() const;
    cVector normalize() const;
    double angle(const cVector& o) const;
    bool isOrthogonal(const cVector& o) const;
    bool isParallel(const cVector& o) const;

    //vector 3 chieu
    cVector cross(const cVector& o) const;

    //I/O
    friend std::istream& operator>>(std::istream& in, cVector& v);
    friend std::ostream& operator<<(std::ostream& out, const cVector& v);
};

#endif