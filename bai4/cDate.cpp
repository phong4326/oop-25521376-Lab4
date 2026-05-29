#include "cDate.h"
#include<iomanip>

static bool isLeap(int y) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

static int getDayofMounth(int m, int y) {
    int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) return 29;
    return day[m];
}

static void normalize(int& d, int& m, int& y) {
    // neu d lo qua ngay trong thang thi xu ly nhu vay
    while (d > getDayofMounth(m, y))
    {
        d -= getDayofMounth(m, y);
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    //neu tru bot nay bi am 
    while (d <= 0)
    {
        m--;
        if (m < 1) {
            m = 12;
            y--;
        }
        d += getDayofMounth(m, y);
    }
    
}

cDate::cDate(int d, int m, int y) : d(d), m(m), y(y) 
{
    normalize(this->d, this->m, this->y);
}

std::istream &operator>>(std::istream &in, cDate &a)
{
    in >> a.d >> a.m >> a.y;
    if (in.fail()) {
        throw std::invalid_argument("Loi dinh dang: Vui long chi nhap so nguyen cho ngay thang nam!");
    }
    if (a.y <= 0 || a.m < 1 || a.m > 12 || a.d < 1 || a.d > getDayofMounth(a.m, a.y)) {
        throw std::invalid_argument("Loi logic: Ngay thang nam nhap vao khong ton tai tren thuc te!");
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const cDate &a)
{
    out << a.d << "/" << a.m << "/" << a.y;
    return out;
}

cDate cDate::operator+(int day)
{
    // Truyền thẳng vào Constructor, hàm normalize tự động lo phần tăng tháng/năm
    return cDate(d + day, m, y);
}

cDate cDate::operator-(int day)
{
    return cDate(d - day, m, y);
}

cDate &cDate::operator++()
{
    ++d;
    normalize(d, m, y);
    return *this;
}

cDate cDate::operator++(int)
{
    cDate tmp = *this;
    ++(*this);
    return tmp;
}

cDate &cDate::operator--()
{
    --d;
    normalize(d, m, y);
    return *this;
}

cDate cDate::operator--(int)
{
    cDate tmp = *this;
    --(*this);
    return tmp;
}
