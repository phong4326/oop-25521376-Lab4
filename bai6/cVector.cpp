#include "cVector.h"

cVector::cVector() : n(0) {}

cVector::cVector(int n) :n(n), data(n, 0.0) {}

cVector::cVector(int n, double val) : n(n), data(n, val) {}

cVector::cVector(std::initializer_list<double> list) : n(list.size()), data(list) {}

cVector::cVector(const cVector &other) : n(other.n), data(other.data) {}

int cVector::size() const{ return n; }

double &cVector::operator[](int i)
{
    return data[i];
    // TODO: insert return statement here
}

const double &cVector::operator[](int i) const
{
    return data[i];
    // TODO: insert return statement here
}

double cVector::at(int i) const
{
    if (i < 0 || i >= n) {
        throw std::out_of_range("Chi so vuot qua gioi han Vector!");
    }
    return data[i];
}

cVector cVector::operator+(const cVector &o) const
{
    if (this->n != o.n) throw std::invalid_argument("Hai vector khong cung so chieu");
    cVector res(*this);
    res += o;
    return res;
}

cVector cVector::operator-(const cVector &o) const
{
    if (this->n != o.n) throw std::invalid_argument("Hai vector khong cung so chieu");
    cVector res(*this);
    res -= o;
    return res;
}

cVector cVector::operator*(double scalar) const
{
    cVector res(*this);
    res *= scalar;
    return res;
}

cVector cVector::operator/(double scalar) const
{
    if (scalar == 0) throw std::runtime_error("Loi chia cho 0!");
    cVector res(*this);
    res *= (1.0 / scalar);
    return res;
}

cVector operator*(double scalar, const cVector &v) //ham friend
{
    return v * scalar;
}

cVector &cVector::operator+=(const cVector &o)
{
    if (this->n != o.n) throw std::invalid_argument("Hai vector khong cung so chieu");
    for (int i = 0; i < n; i++) {
        data[i] += o.data[i];
    }
    return *this;
    // TODO: insert return statement here
}

cVector &cVector::operator-=(const cVector &o)
{
    if (this->n != o.n) throw std::invalid_argument("Hai vector khong cung so chieu");
    for (int i = 0; i < n; i++) {
        data[i] -= o.data[i];
    }
    return *this;
    // TODO: insert return statement here
}

cVector &cVector::operator*=(double scalar)
{
    for (int i = 0; i < n; i++) data[i] *= scalar;
    return *this;
    // TODO: insert return statement here
}

//dung sai so EPSILON de so sanh so thuc double chuan xac hon
bool cVector::operator==(const cVector &o) const
{
    if (this->n != o.n) return false;
    const double EPSILON = 1e-9;
    for (int i = 0; i < n; i++) {
        if (std::abs(data[i] - o.data[i]) > EPSILON) return false;
    }
    return true;
}

bool cVector::operator!=(const cVector &o) const
{
    return !(*this == o);
}

double cVector::dot(const cVector &o) const //tich vo huong
{
    if (this->n != o.n) throw std::invalid_argument("Hai vector khong cung so chieu");
    double sum = 0;
    for (int i = 0; i < n; i++) sum += this->data[i] * o.data[i];
    return sum;
}

double cVector::norm() const //do dai |v|
{
    return std::sqrt(this->normSquared()); // can bac hai (v.v) DRY
}

double cVector::normSquared() const // v.v
{
    return this->dot(*this);
}

cVector cVector::normalize() const
{
    double len = this->norm();
    if (len == 0) throw std::runtime_error("Khong the chuan hoa vector co do dai bang 0!");
    return *this / len;
}

double cVector::angle(const cVector &o) const //cos(u, v) = (u.v)/(|u|.|v|)
{
    double lenProduct = this->norm() * o.norm();
    if (lenProduct == 0) throw std::runtime_error("Khong the tinh goc voi vector 0");
    double cosTheta = this->dot(o) / lenProduct;
    // Gioi han gia tri trong [-1, 1] de tranh sai so lam ham acos bi loi
    cosTheta = std::max(-1.0, std::min(1.0, cosTheta)); // tranh truong hop cos = 1.000000000002
    return std::acos(cosTheta); // Tra ve radian
}

bool cVector::isOrthogonal(const cVector &o) const //vuong goc
{
    return std::abs(this->dot(o)) < 1e-9;
}

bool cVector::isParallel(const cVector &o) const //song song
{
    if (this->n != o.n) return false;
    // hai vector song song thi goc = 0 hoac PI
    double theta = this->angle(o);
    return (theta < 1e-9 || std::abs(theta - M_PI) < 1e-9);
}

cVector cVector::cross(const cVector &o) const
{
    if (this->n != 3 || o.n != 3) throw std::invalid_argument("Tich co huong (Cross Product) chi ap dung cho vector 3 chieu");
    return cVector{
        this->data[1]*o.data[2] - this->data[2]*o.data[1],
        this->data[2]*o.data[0] - this->data[0]*o.data[2],
        this->data[0]*o.data[1] - this->data[1]*o.data[0]
    };
}

std::istream &operator>>(std::istream &in, cVector &v)
{
    std::cout << "Nhap so chieu: ";
    in >> v.n;
    v.data.resize(v.n);
    std::cout << "Nhap " << v.n << " toa do: ";
    for (int i = 0; i < v.n; i++) {
        in >> v.data[i];
    }
    return in;
    // TODO: insert return statement here
}

std::ostream &operator<<(std::ostream &out, const cVector &v)
{
    out << "[";
    for (int i = 0; i < v.n; i++) {
        out << v.data[i];
        if (i < v.n - 1) out << ", ";
    }
    out << "]";
    return out;
    // TODO: insert return statement here
}