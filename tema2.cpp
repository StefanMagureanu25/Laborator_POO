#include <iostream>
#include <vector>
#include <string>

class Persoana {
    std::string nume, cnp;
public:
    Persoana() {}

    Persoana(std::string Nume, std::string CNP) : nume(Nume), cnp(CNP) {}

    Persoana(Persoana &pers) {
        this->cnp = pers.cnp;
        this->nume = pers.nume;
    }

    void setNume(const std::string &nume) {
        this->nume = nume;
    }

    void setCnp(const std::string &cnp) {
        this->cnp = cnp;
    }

    const std::string &getNume() const {
        return nume;
    }

    const std::string &getCnp() const {
        return cnp;
    }

    virtual ~Persoana() {
        nume.clear(), cnp.clear();
    }

    friend std::istream &operator>>(std::istream &is, Persoana &persoana) {
        is >> persoana.nume >> persoana.cnp;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Persoana &persoana) {
        os << "Nume: " << persoana.nume << " \nCNP: " << persoana.cnp;
        return os;
    }
};

class Abonat : public Persoana {
    int nrMaxCarti, nrCartiImprumutate, pretAbonament;
public:
};

class dosar {

};

int main() {
    Persoana Stefan;
}