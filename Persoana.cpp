#include "Persoana.h"

Persoana::Persoana() {}


Persoana::Persoana(std::string name, std::string CNP) : name(std::move(name)), cnp(std::move(CNP)) {}

void Persoana::setName(const std::string &nume) {
    this->name = nume;
}

void Persoana::setCnp(const std::string &cnp_) {
    cnp = cnp_;
}

const std::string &Persoana::getName() const {
    return name;
}

const std::string &Persoana::getCnp() const {
    return cnp;
}

Persoana::Persoana(Persoana &pers) {
    this->cnp = pers.cnp;
    this->name = pers.name;
}

Persoana::~Persoana() {
    name.clear(), cnp.clear();
}

Persoana &Persoana::operator=(const Persoana &p) {
    this->cnp = p.cnp;
    this->name = p.name;
    return *this;
}

/*Constructorul de copiere, destructorul si operatorul =
 * sunt optionali, intrucat acestia oricum sunt implementati
 * in std::string */

std::istream &operator>>(std::istream &is, Persoana &pers) {
    is >> pers.name >> pers.cnp;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Persoana &pers) {
    os << "name: " << pers.name << " \nCNP: " << pers.cnp;
    return os;
}

