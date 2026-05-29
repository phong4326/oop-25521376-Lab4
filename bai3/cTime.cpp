#include "cTime.h"
#include<iomanip>
#include<iostream>

// cong cu giup chuan hoa' gio
// giup viet +, - de hon
static void normalize(int& h, int& m, int& s) {
    const int day = 24*3600; // so giay 1 day
    int total = h*3600 + m*60 + s;
    total = ((total % day) + day) % day;// tranh so am do dau tru
    h = total / 3600;
    total %= 3600;
    m = total / 60;
    s = total % 60;
} 

cTime::cTime(int h, int m, int s) : h(h), m(m), s(s) {}

std::istream &operator>>(std::istream &in, cTime &a)
{
    in >> a.h >> a.m >> a.s;
    if (in.fail()) {
        throw std::invalid_argument("Loi dinh dang: Vui long chi nhap so nguyen cho thoi gian!");
    }

    // Kiem tra tinh hop le cua thoi gian
    if (a.h < 0 || a.h >= 24 || a.m < 0 || a.m >= 60 || a.s < 0 || a.s >= 60) {
        throw std::invalid_argument("\nLoi: Thoi gian nhap vao khong hop le (0<=h<24, 0<=m,s<60)!");
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const cTime &a)
{
    out << std::setw(2) << std::setfill('0') << a.h
        << ":" << std::setw(2) << std::setfill('0') << a.m
        << ":" <<std::setw(2) << std::setfill('0') << a.s;
    return out;
    // TODO: insert return statement here
}

cTime cTime::operator+(int time) const // cong them bao nhieu giay
{
    int H = h, M = m, S = s;
    S += time;
    normalize(H, M, S);
    return cTime(H, M, S);
}

cTime cTime::operator-(int time) const //tru bao nhieu giay
{
    return *this + (-time);
}

cTime &cTime::operator++() //++t
{
    int H = h, M = m, S = s;
    S += 1;
    normalize(H, M, S);
    h = H, m = M, s = S;
    return *this;
    // TODO: insert return statement here
}

cTime cTime::operator++(int) //t++
{
    cTime tmp = *this;
    ++(*this);
    return tmp;
}

cTime &cTime::operator--()
{
    int H = h, M = m, S = s;
    S -= 1;
    normalize(H, M, S);
    h = H, m = M, s = S;
    return *this;
    // TODO: insert return statement here
}

cTime cTime::operator--(int)
{
    cTime tmp = *this;
    --(*this);
    return tmp;
}