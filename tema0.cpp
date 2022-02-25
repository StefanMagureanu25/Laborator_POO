#include <iostream>
#include <cmath>

using namespace std;

class Numar_Complex {
    double a, b;
public:
    Numar_Complex(double a_, double b_) {
        a = a_;
        b = b_;
    }

    Numar_Complex(Numar_Complex &c1) {
        c1.a = a;
        c1.b = b;
    }

    void setA(double a_) {
        a = a_;
    }

    void setB(double b) {
        Numar_Complex::b = b;
    }

    friend ostream &operator<<(ostream &os, const Numar_Complex &complex) {
        if (complex.b == 0)
            os << complex.a;
        else if (complex.a == 0)
            os << complex.b << "i";
        else if (complex.b == 1)
            os << complex.a << "+i";
        else if (complex.b == -1)
            os << complex.a << "-i";
        else if (complex.b > 0)
            os << complex.a << "+" << complex.b << "i";
        else if (complex.b < 0)
            os << complex.a << "-" << complex.b << "i";
        return os;
    }

    Numar_Complex operator+(const Numar_Complex &rhs) const {
        return Numar_Complex(a + rhs.a,
                             b + rhs.b);
    }

    Numar_Complex operator*(const Numar_Complex &rhs) const {
        return Numar_Complex(a * rhs.a,
                             b * rhs.b);
    }

    Numar_Complex operator/(const Numar_Complex &rhs) const {
        return Numar_Complex(a / rhs.a,
                             b / rhs.b);
    }

    double modul(Numar_Complex c) {
        return sqrt(pow(c.a, 2) + pow(c.b, 2));
    }
};

int main() {

}