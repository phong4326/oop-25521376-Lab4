#ifndef CTIME_H
#define CTIME_H

#include<iostream>

class cTime
{
private:
    int s, m, h;
public:
    cTime(int h = 0, int m = 0, int s = 0);
    friend std::istream& operator>>(std::istream& in, cTime& a);
    friend std::ostream& operator<<(std::ostream& out, const cTime& a);

    cTime operator+(int time) const;
    cTime operator-(int time) const;

    cTime& operator++(); //++t: tang xong r moi tra ve doi tuong goc
    cTime operator++(int); //t++: luu lai gia tri cu, tang doi tuong goc, tra ve gia tri cu

    cTime& operator--();
    cTime operator--(int);
};

#endif