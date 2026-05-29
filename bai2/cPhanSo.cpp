#include "cPhanSo.h"
#include<cmath>

cPhanSo::cPhanSo(int x, int y) : x(x), y(y) {
    if (y == 0) {
        throw std::invalid_argument("\nLoi: Mau so khong duoc bang 0!\n");
    }
}

int gcd(const int& a, const int& b) {
    return (b) ? gcd(b, a%b) : a;
}
void cPhanSo::rutGon()
{
    if (y == 0) return; // Đề phòng chia cho 0
    int ucln = gcd(std::abs(x), std::abs(y));
    x /= ucln;
    y /= ucln;
}

cPhanSo cPhanSo::operator+(const cPhanSo &other) const
{
    cPhanSo res(this->x * other.y + this->y * other.x, this->y * other.y);
    res.rutGon(); //nen rut gon luon ket qua truoc khi tra ve
    return res;
}

cPhanSo cPhanSo::operator-(const cPhanSo &other) const
{
    cPhanSo res(this->x * other.y - this->y * other.x, this->y * other.y);
    res.rutGon();
    return res;
}

cPhanSo cPhanSo::operator*(const cPhanSo &other) const
{
    cPhanSo res(this->x * other.x, this->y * other.y);
    res.rutGon();
    return res;
}

cPhanSo cPhanSo::operator/(const cPhanSo &other) const
{
    if (other.x == 0) {
        throw std::runtime_error("\nLoi toan hoc: Khong the chia cho phan so co gia tri bang 0!\n");
    }
    cPhanSo res(this->x * other.y, this->y * other.x);
    res.rutGon();
    return res;
}

bool cPhanSo::operator>(const cPhanSo &other) const
{
    return (this->x * other.y > other.x * this->y);
}

bool cPhanSo::operator<(const cPhanSo &other) const
{
    return (this->x * other.y < other.x * this->y);
}

bool cPhanSo::operator==(const cPhanSo &other) const
{
    return (this->x * other.y == other.x * this->y);
}

std::istream &operator>>(std::istream &in, cPhanSo &a)
{
    in >> a.x >> a.y;
    if (a.y == 0) {
        throw std::invalid_argument("Loi: Nhap mau so bang 0 la bat hop le!\n");
    }
    a.rutGon();
    return in;
    // TODO: insert return statement here
}

std::ostream &operator<<(std::ostream &out, const cPhanSo &a)
{
    if (a.x % a.y == 0) out << a.x / a.y;
    else {
        if (a.y < 0) out << -1*a.x << "/" << -1*a.y;
        else out << a.x << "/" << a.y;
    }
    return out;
    // TODO: insert return statement here
}