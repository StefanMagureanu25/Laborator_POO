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

    Numar_Complex();

    /*Am adaugat inca un constructor implicit, pentru a
     * nu fi nevoit de fiecare data sa initializeze obiectul
     * cu anumite valori (a se vedea exemplele de la suma si produs, unde
     * am prezentat aceasta varianta) */

    Numar_Complex(Numar_Complex &c1) {
        a = c1.a;
        b = c1.b;
    }

    void parte_reala(double a_) {
        a = a_;
    }

    void parte_imaginara(double b_) {
        b = b_;
    }

    friend ostream &operator<<(ostream &afis, const Numar_Complex &complex) {
        if (complex.b == 0)
            afis << complex.a;
        else if (complex.a == 0)
            afis << complex.b << "i";
        else if (complex.b == 1)
            afis << complex.a << "+i";
        else if (complex.b == -1)
            afis << complex.a << "-i";
        else if (complex.b > 0)
            afis << complex.a << "+" << complex.b << "i";
        else if (complex.b < 0)
            afis << complex.a << complex.b << "i";
        return afis;
    }

    friend Numar_Complex operator+(const Numar_Complex &c1, const Numar_Complex &c2) {
        Numar_Complex S;
        S.a = c1.a + c2.a;
        S.b = c1.b + c2.b;
        return S;
    }


    friend Numar_Complex operator*(const Numar_Complex &c1, const Numar_Complex &c2) {
        Numar_Complex P;
        P.a = c1.a * c2.a - c1.b * c2.b;
        P.b = c1.a * c2.b + c2.a * c1.b;
        return P;
    }

    friend Numar_Complex operator/(const Numar_Complex &c1, const Numar_Complex &c2) {
        Numar_Complex I((c1.a * c2.a + c1.b * c2.b) / (pow(c2.a, 2) + pow(c2.b, 2)),
                        (c2.a * c1.b - c1.a * c2.b) / (pow(c2.a, 2) + pow(c2.b, 2)));
        return I;
    }

    double modul() {
        return sqrt(pow(a, 2) + pow(b, 2));
    }
};

Numar_Complex::Numar_Complex() {}

int main() {
    double re, im;
    Numar_Complex c;
    c.parte_reala(3), c.parte_imaginara(4);
    cout << c << "\n";
    cout << "Primul numar complex\n";
    cout << "Introduceti partea reala:";
    cin >> re;
    cout << "Introduceti partea imaginara:";
    cin >> im;
    Numar_Complex a(re, im);
    cout << "Al doilea numar complex\n";
    cout << "Introduceti partea reala:";
    cin >> re;
    cout << "Introduceti partea imaginara:";
    cin >> im;
    Numar_Complex b(re, im);
    Numar_Complex copie(a);
    cout << "Copia primului numar complex este: " << copie << "\n";
    cout << "Modulul primului numar complex este: " << a.modul() << "\n";
    cout << "Modulul celui de-al doilea numar complex este: " << b.modul() << "\n";
    cout << "Suma celor doua numere complexe este: " << a + b << "\n";
    cout << "Produsul celor doua numere complexe este: " << a * b << "\n";
    cout << "Raportul celor doua numere complexe este: " << a / b << "\n";
    return 0;
}