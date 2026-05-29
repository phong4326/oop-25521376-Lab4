#include"cDaThuc.h"

using namespace std;

cDaThuc::cDaThuc(int bac) {
    this->n = bac;
    this->a.resize(n + 1, 0);
}

//su dung so do Horner de tinh dan gia tri cua da thuc
double cDaThuc::operator()(double x) const {
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = ans * x + a[i]; //khong lo du ra he so tu do
    }
    return ans;
}

cDaThuc cDaThuc::operator+(const cDaThuc& other) const {
    int maxBac = max(this->n, other.n);
    //tim max bac de tranh hai da thuc khac bac nhau
    cDaThuc ans(maxBac);
    //cong tung so theo tung bac
    //neu da thuc nao ko co bac do thi coi nhu he so bang 0
    //vd: (2x^2 + 3x + 4) + (x^3 + x^2 + 2x)
    for (int i = 0; i <= maxBac; i++) {
        int hs1 = (i <= this->n) ? this->a[i] : 0;
        int hs2 = (i <= other.n) ? other.a[i] : 0;
        ans.a[i] = hs1 + hs2;
    }
    return ans;
}

cDaThuc cDaThuc::operator-(const cDaThuc& other) const {
    int maxBac = max(this->n, other.n);
    //tim max bac de tranh hai da thuc khac bac nhau
    cDaThuc ans(maxBac);
    //cong tung so theo tung bac
    //neu da thuc nao ko co bac do thi coi nhu he so bang 0
    //vd: (2x^2 + 3x + 4) + 
    for (int i = 0; i <= maxBac; i++) {
        int hs1 = (i <= this->n) ? this->a[i] : 0;
        int hs2 = (i <= other.n) ? other.a[i] : 0;
        ans.a[i] = hs1 - hs2;
    }
    return ans;
}

istream& operator>>(std::istream& in, cDaThuc& dt) {
    cout << "Nhap bac cua da thuc: "; in >> dt.n;
    dt.a.resize(dt.n + 1);
    for (int i = 0; i <= dt.n; i++) {
        if (dt.n - i == 1) cout << "Nhap he so cua x: ";
        else if (i == dt.n) cout << "Nhap he so tu do: ";
        else cout << "Nhap he so cua x^" << dt.n - i << ": ";
        in >> dt.a[i];
    }
    return in;
}

ostream& operator<<(std::ostream& out, const cDaThuc& dt) {
    bool isFirst = true;
    for (int i = 0; i <= dt.n; i++) {
        if (dt.a[i] == 0) continue;

        //In dau
        if (isFirst) { //neu la so dau tien ta chi can kiem tra he so am
            if (dt.a[i] < 0) out << "-"; // neu am vd -2x^3 phai viet lien dau -
        } else {
            if (dt.a[i] > 0) out << " + "; // cac truong hop con lai viet theo dau cach
            else out << " - "; //vd -2x^3 + 3x^2 + x - 5
        }

        //In he so
        int val = abs(dt.a[i]);
        if (val != 1 || i == dt.n) out << val;
        //neu he so khac 1 thi ghi vao va la he so tu do thi ghi vao
        //vd : 2x out << 2; he so tu do = 1 out << 1

        //In x va so mu
        if (dt.n - i > 0) out << "x";
        if (dt.n - i > 1) out << "^" << (dt.n - i);

        isFirst = false;
    }
    if (isFirst) out << "0"; //neu truong hop da thuc ko co j thi in ra 0
    return out;
}