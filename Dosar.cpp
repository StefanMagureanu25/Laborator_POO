#include "Dosar.h"

int Dosar::getNrAbonati() {
    return nr_abonati;
}

Dosar::Dosar() {};

void Dosar::addAbonati(std::shared_ptr<Abonat> ab) {
    abonati.push_back(ab);
    nr_abonati++;
}
