#include <iostream>
using namespace std;

class Matrix {
public:
       long matr[2][2];

       Matrix(const Matrix&rhs);

       Matrix(long a, long b, long c, long d);

       Matrix& operator=(const Matrix&);

       friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
              Matrix ret(0,0,0,0);
              ret.matr[0][0] = lhs.matr[0][0]*rhs.matr[0][0] + lhs.matr[0][1]*rhs.matr[1][0];
              ret.matr[0][1] = lhs.matr[0][0]*rhs.matr[0][1] + lhs.matr[0][1]*rhs.matr[1][1];
              ret.matr[1][0] = lhs.matr[1][0]*rhs.matr[0][0] + lhs.matr[1][1]*rhs.matr[1][0];
              ret.matr[1][1] = lhs.matr[1][0]*rhs.matr[0][1] + lhs.matr[1][1]*rhs.matr[1][1];
              return ret;
       }

};

Matrix::Matrix(long a, long b, long c, long d) {
       this->matr[0][0] = a;
       this->matr[0][1] = b;
       this->matr[1][0] = c;
       this->matr[1][1] = d;
}

Matrix::Matrix(const Matrix &rhs) {
       this->matr[0][0] = rhs.matr[0][0];
       this->matr[0][1] = rhs.matr[0][1];
       this->matr[1][0] = rhs.matr[1][0];
       this->matr[1][1] = rhs.matr[1][1];
}

Matrix& Matrix::operator =(const Matrix &rhs) {
       this->matr[0][0] = rhs.matr[0][0];
       this->matr[0][1] = rhs.matr[0][1];
       this->matr[1][0] = rhs.matr[1][0];
       this->matr[1][1] = rhs.matr[1][1];
       return *this;
}

Matrix power(const Matrix& m, int n) {
       if (n <= 1)
              return m;
       if (n%2 == 0)
              return power(m*m, n/2);
       else
              return power(m*m, n/2) * m;

}

long fib4(int n) {
       Matrix matrix0(1, 1, 1, 0);
       matrix0 = power(matrix0, n-1);
       return matrix0.matr[0][0];
}

int main() {
    cout << fib4(1) << endl;
    cout << fib4(2) << endl;
    cout << fib4(3) << endl;
    cout << fib4(4) << endl;
    return 0;
}
