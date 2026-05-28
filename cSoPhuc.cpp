#include"cSoPhuc.h"
#include<cmath>

cSoPhuc::cSoPhuc(double x, double y) : x(x), y(y) {}

std::istream& operator>>(std::istream &in, cSoPhuc &a)
{   
    in >> a.x >> a.y;
    return in;
    // TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& out,const cSoPhuc &a)
{   
    if (a.y == 0) out << a.x; // neu ao = 0 thi phan thuc quyet dinh, du thuc = 0 thi van in ra 0
    else if (a.x == 0) out << a.y << "i";
    else {
        out << a.x;
        if (a.y > 0) out << " + " << a.y << "i";
        else out << " - " << std::abs(a.y) << "i"; // chuan hoa dau am
    }
    return out;
    // TODO: insert return statement here
}

cSoPhuc cSoPhuc::operator+(const cSoPhuc &other) const
{
    return cSoPhuc(this->x + other.x, this->y + other.y);
}

cSoPhuc cSoPhuc::operator-(const cSoPhuc &other) const
{
    return cSoPhuc(this->x - other.x, this->y - other.y);
}

cSoPhuc cSoPhuc::operator*(const cSoPhuc &other) const
{// (ac - bd) + (ad + bc)i
    return cSoPhuc(this->x * other.x - this->y * other.y,
                    this->x * other.y + this->y * other.x);
}

cSoPhuc cSoPhuc::operator/(const cSoPhuc &other) const
{ //cong thuc toan hoc co ban
    double mau = other.x * other.x + other.y * other.y,
        tuThuc = this->x * other.x + this->y * other.y,
        tuAo = this->y * other.x - this->x * other.y;
    return cSoPhuc(tuThuc/mau , tuAo/mau);
}

bool cSoPhuc::operator==(const cSoPhuc &other) const
{   
    return (this->x == other.x && this->y == other.y);
}

bool cSoPhuc::operator!=(const cSoPhuc &other) const
{
    return (!(*this == other));
}
