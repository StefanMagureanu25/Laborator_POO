#ifndef _DOSAR_H
#define _DOSAR_H
#pragma once

#include "Abonat.h"

class Dosar : public Abonat {
    std::vector<std::shared_ptr<Abonat>> abonati;
    static int nr_abonati;
public:
    static int getNrAbonati();

    Dosar();

    void addAbonati(std::shared_ptr<Abonat> ab);

};

int Dosar::nr_abonati = 0;

#endif