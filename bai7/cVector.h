#ifndef CVECTOR_H
#define CVECTOR_H

#include<iostream>
#include<vector>

class cVector
{
private:
    int n;
    std::vector<double> data;
public:
    // --- Constructors ---
    explicit cVector(int size = 0, double val = 0.0);
    cVector(std::initializer_list<double> list);
 
    // --- Truy cap ---
    int    size()            const;
    double& operator[](int i);
    const double& operator[](int i) const;
 
    // --- Tien ich ---
    void print(const std::string& name = "") const;
 
};

#endif