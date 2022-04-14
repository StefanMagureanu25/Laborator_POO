#include "Dosar.h"

int Dosar::getNrAbonati() {
    return nr_abonati;
}

const std::vector<std::shared_ptr<Abonat>> &Dosar::getAbonati() const {
    return abonati;
}

Dosar::~Dosar() = default;

Dosar::Dosar() {};

void Dosar::addAbonati(std::shared_ptr<Abonat> ab) {
    abonati.push_back(ab);
    nr_abonati++;
}

std::ostream &operator<<(std::ostream &os, const Dosar &d) {
    int count = 1;
    for (auto it: d.getAbonati()) {
        os << count << "\n";
        os << "Numele abonatului: " << it->getName() << "\n";
        os << "CNP-ul abonatului: " << it->getCnp() << "\n";
        os << "nrMaxCarti: " << it->getNrMaxCarti() << "\n";
        os << "nrCartiImprumutate: " << it->getNrCartiImprumutate() << "\n";
        os << "pretAbonament: " << it->getPretAbonament() << "\n";
        count++;
    }
    return os;
}

Dosar &Dosar::operator=(const std::vector<std::shared_ptr<Abonat>> &dosar) {
    int count = 0;
    for (auto it: dosar) {
        Dosar::abonati[count]->setName(it->getName());
        Dosar::abonati[count]->setCnp(it->getCnp());
        Dosar::abonati[count]->setNrMaxCarti(it->getNrMaxCarti());
        Dosar::abonati[count]->setNrCartiImprumutate(it->getNrCartiImprumutate());
        Dosar::abonati[count]->setPretAbonament(it->getPretAbonament());
        count++;
    }
    return *this;
}