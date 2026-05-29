#include"cMatrix.h"
#include<iomanip>

cMatrix::cMatrix() : row(0), col(0) {}

 
cMatrix::cMatrix(int m, int n, double val)
    : row(m), col(n), data(m, std::vector<double>(n, val)) {
    if (m <= 0 || n <= 0)
        throw std::invalid_argument("cMatrix: kich thuoc phai > 0");
}
 
cMatrix::cMatrix(const std::vector<std::vector<double>>& v) {
    row = static_cast<int>(v.size());
    col = (row > 0) ? static_cast<int>(v[0].size()) : 0;
    for (const auto& row_ : v)
        if (static_cast<int>(row_.size()) != col)
            throw std::invalid_argument("cMatrix: Cac hang khong cung do dai");
    data = v;
}

cMatrix cMatrix::identity(int n) {
    cMatrix I(n, n, 0.0);
    for (int i = 0; i < n; i++) I(i,i) = 1.0; // co' operator()
    return I;
}

cMatrix cMatrix::zeros(int m, int n) { return cMatrix(m, n, 0.0); }

int cMatrix::getRow() const { return row; }
int cMatrix::getCol() const { return col; }

void cMatrix::checkBound(int i, int j) const {
    if (i < 0 || i >= row || j < 0 || j >= col) 
        throw std::out_of_range("checkBound: chi so (" + std::to_string(i) + ", " + std::to_string(j) + ") nam ngoai pham vi");
}

double& cMatrix::operator()(int i, int j) {
    checkBound(i, j);
    return data[i][j];
}

const double& cMatrix::operator()(int i, int j) const {
    checkBound(i, j);
    return data[i][j];
}

cMatrix cMatrix::operator+(const cMatrix& B) const {        // A + B
    if (this->row != B.row || this->col != B.col) 
        throw std::invalid_argument("operator+: chi so khong khop");
    cMatrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.data[i][j] = this->data[i][j] + B.data[i][j];
        }
    }
    return res;
}          
cMatrix cMatrix::operator-(const cMatrix& B) const{         // A - B
    if (this->row != B.row || this->col != B.col) 
        throw std::invalid_argument("operator-: chi so khong khop");
    cMatrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.data[i][j] = this->data[i][j] - B.data[i][j];
        }
    }
    return res;
}
cMatrix cMatrix::operator*(double scalar)    const{         // A * k
    cMatrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return res;
}

cMatrix operator*(double scalar, const cMatrix& A) {        // k * A
    return A*scalar;
}

cVector cMatrix::operator*(const cVector& v) const {
    if (this->col != v.size()) 
        throw std::invalid_argument("operator*(vector): kich thuoc khong khop");
    cVector res(row, 0.0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i] += this->data[i][j] * v[j];
        }
    }
    return res;
}
cMatrix cMatrix::operator*(const cMatrix& v) const {
    //A(m×k) * B(k×n) = C(m×n)
    if (col != v.row) 
        throw std::invalid_argument("operator*(matrix): sai kich thuoc, khong the nhan");
    cMatrix res(row, v.col, 0.0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < v.col; j++) {
            for (int k = 0; k < col; k++) {
                res.data[i][j] += data[i][k] * v.data[k][j];
            }
        }
    }
    return res;
}

bool cMatrix::operator==(const cMatrix& B) const {
    if (this->row != B.row || this->col != B.col) return false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (this->data[i][j] != B.data[i][j]) return false;
        }
    }
    return true;
}
bool cMatrix::operator!=(const cMatrix& B) const {
    return !(*this == B);
}

cMatrix cMatrix::transpose() const {
    cMatrix res(col, row);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            res.data[i][j] = data[j][i];
        }
    }
    return res;
}

void cMatrix::print(const std::string& name) const {
    if (!name.empty())
        std::cout << name << " (" << row << "x" << col << "):\n";
    for (int i = 0; i < row; ++i) {
        std::cout << "|";
        for (int j = 0; j < col; ++j)
            std::cout << std::setw(8) << std::fixed << std::setprecision(2)
                      << data[i][j];
        std::cout << "|\n";
    }
}

std::istream& operator>>(std::istream& in, cMatrix& A) {
    std::cout << "Nhap row va col: "; in >> A.row >> A.col;
    if (A.row <= 0 || A.col <= 0) {
        throw std::invalid_argument("Kich thuoc ma tran nhap vao phai lon hon 0!");
    }
    A.data.resize(A.row);
    for (int i = 0; i < A.row; i++) {
        A.data[i].resize(A.col);
        for (int j = 0; j < A.col; j++) {
            in >> A.data[i][j];
            if (in.fail()) 
                throw std::invalid_argument("Loi dinh dang: Vui long chi nhap so thuc");
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const cMatrix& A) {
    for (int i = 0; i < A.row; i++) {
        out << "|";
        for (int j = 0; j < A.col; j++) {
            out << std::setw(8) << std::fixed << std::setprecision(2) << A.data[i][j];
        }
        out << "|\n";
    }
    return out;
}