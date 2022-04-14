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

    ~Dosar() override;

    Dosar &operator=(const std::vector<std::shared_ptr<Abonat>> &dosar);

    void addAbonati(std::shared_ptr<Abonat> ab);

    friend std::ostream &operator<<(std::ostream &os, const Dosar &d);

    const std::vector<std::shared_ptr<Abonat>> &getAbonati() const;

};

#endif