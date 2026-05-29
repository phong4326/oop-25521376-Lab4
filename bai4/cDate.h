#ifndef CDATE_H
#define CDATE_H

#include<iostream>

class cDate
{
private:
    int d, m, y;
public:
    cDate(int d = 0, int m = 0, int y = 0);
    friend std::istream& operator>>(std::istream& in, cDate& a);
    friend std::ostream& operator<<(std::ostream& out, const cDate& a);
    cDate operator+(int day);
    cDate operator-(int day);

    cDate& operator++(); //++t: tang xong r moi tra ve doi tuong goc
    cDate operator++(int); //t++: luu lai gia tri cu, tang doi tuong goc, tra ve gia tri cu

    cDate& operator--();
    cDate operator--(int);
};

#endif