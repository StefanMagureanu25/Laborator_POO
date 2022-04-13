#include "Abonat.h"

Abonat::Abonat() {}

Abonat::Abonat(std::string name_, std::string CNP_) : Persoana(
        name_, CNP_) {};

Abonat::Abonat(std::string name_, std::string CNP_, int nrMaxCarti_, int nrCartiImprumutate_, int pretAbonament_) :
        Persoana(name_, CNP_) {
    nrMaxCarti = nrMaxCarti_;
    nrCartiImprumutate = nrCartiImprumutate_;
    pretAbonament = pretAbonament_;
}

Abonat &Abonat::operator=(const Abonat &ab) {
    this->pretAbonament = ab.pretAbonament;
    this->nrCartiImprumutate = ab.nrCartiImprumutate;
    this->nrMaxCarti = ab.nrMaxCarti;
    this->setName(ab.getName());
    this->setCnp(ab.getCnp());
    return *this;
}

int Abonat::getNrCartiImprumutate() const {
    return nrCartiImprumutate;
}

int Abonat::getNrMaxCarti() const {
    return nrMaxCarti;
}

int Abonat::getPretAbonament() const {
    return pretAbonament;
}


void Abonat::setNrMaxCarti(int nrMaxCarti_) {
    nrMaxCarti = nrMaxCarti_;
}

void Abonat::setNrCartiImprumutate(int nrCartiImprumutate_) {
    nrCartiImprumutate = nrCartiImprumutate_;
}

void Abonat::setPretAbonament(int pretAbonament_) {
    pretAbonament = pretAbonament_;
}

std::istream &operator>>(std::istream &is, Abonat &ab) {
    std::string nume, cnp;
    std::cout << "Numele abonatului:";
    std::cin >> nume;
    std::cout << "CNP-ul abonatului:";
    std::cin >> cnp;
    if (cnp[0] == '9' || cnp.size() != 13)
        throw Invalid_argument();
    std::cout << "nrMaxCarti:";
    std::cin >> ab.nrMaxCarti;
    std::cout << "nrCartiImprumutate:";
    std::cin >> ab.nrCartiImprumutate;
    std::cout << "pretAbonament:";
    std::cin >> ab.pretAbonament;
    ab.setName(nume);
    ab.setCnp(cnp);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Abonat &ab) {
    std::cout << "Numele abonatului: " << ab.getName() << "\n";
    std::cout << "CNP-ul abonatului: " << ab.getCnp() << "\n";
    std::cout << "nrMaxCarti: " << ab.nrMaxCarti << "\n";
    std::cout << "nrCartiImprumutate: " << ab.nrCartiImprumutate << "\n";
    std::cout << "pretAbonament: " << ab.pretAbonament << "\n";
    return os;
}

