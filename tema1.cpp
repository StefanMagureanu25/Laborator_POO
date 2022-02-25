#include <iostream>
#include <cstring>

using namespace std;

class student {
    char *nume;
    int anul_nasterii, numar_credite;
    double medie_generala;
public:
    student(const char *numele, int an_nastere, int nr_credite, double medie) {
        size_t length = strlen(numele);
        nume = new char[length];
        anul_nasterii = an_nastere;
        numar_credite = nr_credite;
        medie_generala = medie;
        strcpy(nume, numele);
    }

    ~student() {
        delete[] nume;
    }

    void setNume(char *numele) {
        nume = numele;
    }

    void setAnulNasterii(int anulNasterii) {
        anul_nasterii = anulNasterii;
    }

    void setNumarCredite(int numarCredite) {
        numar_credite = numarCredite;
    }

    void setMedieGenerala(double medieGenerala) {
        medie_generala = medieGenerala;
    }

    friend istream &operator>>(istream &citire, const student &s) {
        return citire;
    }

    friend ostream &operator<<(ostream &afisare, const student &s) {
        afisare << s.nume << " " << s.anul_nasterii << " " << s.numar_credite << " " << s.medie_generala;
        return afisare;
    }

};

class grupa {

};

int main() {
    
}