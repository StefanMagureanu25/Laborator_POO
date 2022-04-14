#include "Persoana.h"

Cnp_incorect::Cnp_incorect() = default;

const char *Cnp_incorect::what() const noexcept {
    return "CNP-ul trebuie sa contina numai cifre";
}

Zi_invalida::Zi_invalida() = default;

const char *Zi_invalida::what() const noexcept {
    return "Ziua de pe CNP nu corespunde";
}

Luna_invalida::Luna_invalida() = default;

const char *Luna_invalida::what() const noexcept {
    return "Luna de pe CNP nu corespunde.";
}

Invalid_argument::Invalid_argument() = default;

const char *Invalid_argument::what() const noexcept {
    return "Cnp-ul introdus nu este bun.";
}

Persoana::Persoana() {}


Persoana::Persoana(std::string name, std::string CNP) : name(std::move(name)), cnp(std::move(CNP)) {
}

void Persoana::setName(const std::string &nume) {
    this->name = nume;
}

void Persoana::setCnp(const std::string &cnp_) {
    cnp = cnp_;
}

int Persoana::getVarsta(int zi_curenta, int luna_curenta, int an_curent) {
    std::string an_modificat;
    int varsta;
    int zi, luna, an;
    if (cnp[3] == '0')
        luna = cnp[4] - '0';
    else
        luna = std::stoi(cnp.substr(3, 2));
    if (cnp[5] == '0')
        zi = cnp[6] - '0';
    else
        zi = std::stoi(cnp.substr(5, 2));
    if (std::stoi(cnp.substr(1, 2)) <= 22) {
        an_modificat = "20";
        an_modificat += cnp.substr(1, 2);
        an = std::stoi(an_modificat);
    } else {
        an_modificat = "19";
        an_modificat += cnp.substr(1, 2);
        an = std::stoi(an_modificat);
    }
    varsta = an_curent - an;
    if (luna_curenta < luna || (luna_curenta >= luna && zi_curenta < zi))
        varsta--;
    return varsta;
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

Persoana::~Persoana() = default;


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
    if (pers.cnp[0] == '9' || pers.cnp.size() != 13)
        throw Invalid_argument();
    for (auto cifra: pers.cnp) {
        if (!isdigit(cifra))
            throw Cnp_incorect();
    }
    if ((pers.cnp[3] == '1' && pers.cnp[4] > '2') || pers.cnp[3] > '1' || (pers.cnp[3] == '0' && pers.cnp[4] == '0'))
        throw Luna_invalida();
    if ((pers.cnp[3] == '0' && pers.cnp[4] == '1') || (pers.cnp[3] == '0' && pers.cnp[4] == '3') ||
        (pers.cnp[3] == '0' && pers.cnp[4] == '5') || (pers.cnp[3] == '0' && pers.cnp[4] == '7') ||
        (pers.cnp[3] == '0' && pers.cnp[4] == '8') || (pers.cnp[3] == '1' && pers.cnp[4] == '0') ||
        (pers.cnp[3] == '1' && pers.cnp[4] == '2')) {
        if (pers.cnp[5] > '3' || (pers.cnp[5] == '3' && pers.cnp[6] > '1') ||
            (pers.cnp[5] == '0' && pers.cnp[6] == '0'))
            throw Zi_invalida();
    } else if (pers.cnp[3] == '0' && pers.cnp[4] == '2') { //Februarie
        if (pers.cnp[5] > '2' || (pers.cnp[5] == '2' && pers.cnp[6] > '8') ||
            (pers.cnp[5] == '0' && pers.cnp[6] == '0'))
            throw Zi_invalida();
    } else {
        if (pers.cnp[5] > '3' || (pers.cnp[5] == '3' && pers.cnp[6] > '0') ||
            (pers.cnp[5] == '0' && pers.cnp[6] == '0'))
            throw Zi_invalida();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Persoana &pers) {
    os << "name: " << pers.name << " \nCNP: " << pers.cnp;
    return os;
}

