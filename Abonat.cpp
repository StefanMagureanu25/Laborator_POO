#include "Abonat.h"

nr_Max::nr_Max() = default;

const char *nr_Max::what() const noexcept {
    return "Numarul maxim de carti este mai mare decat pretul abonamentului";
}

Carti_imprumutate::Carti_imprumutate() = default;

const char *Carti_imprumutate::what() const noexcept {
    return "Numarul de carti imprumutate este mai mare decat numarul maxim de carti";
}

int Abonat::getVarsta(int zi_curenta, int luna_curenta, int an_curent) {
    std::string an_modificat;
    int varsta;
    int zi, luna, an;
    if (Abonat::getCnp()[3] == '0')
        luna = Abonat::getCnp()[4] - '0';
    else
        luna = std::stoi(Abonat::getCnp().substr(3, 2));
    if (Abonat::getCnp()[5] == '0')
        zi = Abonat::getCnp()[6] - '0';
    else
        zi = std::stoi(Abonat::getCnp().substr(5, 2));
    if (std::stoi(Abonat::getCnp().substr(1, 2)) <= 22) {
        an_modificat = "20";
        an_modificat += Abonat::getCnp().substr(1, 2);
        an = std::stoi(an_modificat);
    } else {
        an_modificat = "19";
        an_modificat += Abonat::getCnp().substr(1, 2);
        an = std::stoi(an_modificat);
    }
    varsta = an_curent - an;
    if (luna_curenta < luna || (luna_curenta >= luna && zi_curenta < zi))
        varsta--;
    return varsta;
}

Abonat::Abonat() {}

Abonat::Abonat(std::string name_, std::string CNP_) : Persoana(
        name_, CNP_) {};

Abonat::Abonat(std::string name_, std::string CNP_, int nrMaxCarti_, int nrCartiImprumutate_, int pretAbonament_) :
        Persoana(name_, CNP_) {
    nrMaxCarti = nrMaxCarti_;
    nrCartiImprumutate = nrCartiImprumutate_;
    pretAbonament = pretAbonament_;
}

Abonat::Abonat(const Abonat &ab) : Persoana() {
    Abonat::nrMaxCarti = ab.nrMaxCarti;
    Abonat::nrCartiImprumutate = ab.nrCartiImprumutate;
    Abonat::pretAbonament = ab.pretAbonament;
    Abonat::setName(ab.getName());
    Abonat::setCnp(ab.getCnp());
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
    is >> nume;
    std::cout << "CNP-ul abonatului:";
    is >> cnp;
    if (cnp[0] == '9' || cnp.size() != 13)
        throw Invalid_argument();
    for (auto cifra: cnp) {
        if (!isdigit(cifra))
            throw Cnp_incorect();
    }
    if ((cnp[3] == '1' && cnp[4] > '2') || cnp[3] > '1' || (cnp[3] == '0' && cnp[4] == '0'))
        throw Luna_invalida();
    if ((cnp[3] == '0' && cnp[4] == '1') || (cnp[3] == '0' && cnp[4] == '3') ||
        (cnp[3] == '0' && cnp[4] == '5') || (cnp[3] == '0' && cnp[4] == '7') ||
        (cnp[3] == '0' && cnp[4] == '8') || (cnp[3] == '1' && cnp[4] == '0') ||
        (cnp[3] == '1' && cnp[4] == '2')) {
        if (cnp[5] > '3' || (cnp[5] == '3' && cnp[6] > '1') ||
            (cnp[5] == '0' && cnp[6] == '0'))
            throw Zi_invalida();
    } else if (cnp[3] == '0' && cnp[4] == '2') { //Februarie
        if (cnp[5] > '2' || (cnp[5] == '2' && cnp[6] > '8') ||
            (cnp[5] == '0' && cnp[6] == '0'))
            throw Zi_invalida();
    } else {
        if (cnp[5] > '3' || (cnp[5] == '3' && cnp[6] > '0') ||
            (cnp[5] == '0' && cnp[6] == '0'))
            throw Zi_invalida();
    }
    std::cout << "nrMaxCarti:";
    is >> ab.nrMaxCarti;
    std::cout << "nrCartiImprumutate:";
    is >> ab.nrCartiImprumutate;
    if (ab.nrCartiImprumutate > ab.nrMaxCarti)
        throw Carti_imprumutate();
    std::cout << "pretAbonament:";
    is >> ab.pretAbonament;
    if (ab.nrMaxCarti > ab.pretAbonament)
        throw nr_Max();

    ab.setName(nume);
    ab.setCnp(cnp);
    return is;
}

std::ostream &operator<<(std::ostream &os, std::shared_ptr<Abonat> ab) {
    os << "Numele abonatului: " << ab->getName() << "\n";
    os << "CNP-ul abonatului: " << ab->getCnp() << "\n";
    os << "nrMaxCarti: " << ab->getNrMaxCarti() << "\n";
    os << "nrCartiImprumutate: " << ab->getNrCartiImprumutate() << "\n";
    os << "pretAbonament: " << ab->getPretAbonament() << "\n";
    return os;
}

