#include"cVector.h"
#include<iomanip>

cVector::cVector(int size, double val) : n(size), data(size, val) {} 
cVector::cVector(std::initializer_list<double> list) : 
n(list.size()), data(list) {}
 
// --- Truy cap ---
int    cVector::size() const { return n; }
double& cVector::operator[](int i) {
    if (i < 0 || i >= n)
        throw std::out_of_range("size(): Chi so ngoai pham vi");
    return data[i];
}

const double& cVector::operator[](int i) const {
    if (i < 0 || i >= n)
        throw std::out_of_range("operator[]: Chi so ngoai pham vi");
    return data[i];
}
 
// --- Tien ich ---
void cVector::print(const std::string& name) const {
    if (!name.empty()) std::cout << name << " = [";
    for (int i = 0; i < n; ++i) {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << data[i];
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}