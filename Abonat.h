#ifndef _ABONAT_H_
#define _ABONAT_H_
#pragma once

#include "Persoana.h"

class Abonat : public Persoana {
    int nrMaxCarti, nrCartiImprumutate, pretAbonament;
public:
    Abonat();

    Abonat(std::string name_, std::string CNP_);

    Abonat(std::string name_, std::string CNP_, int nrMaxCarti_, int nrCartiImprumutate_,
           int pretAbonament_);

    Abonat &operator=(const Abonat &ab);

    int getNrMaxCarti() const;

    int getNrCartiImprumutate() const;

    int getPretAbonament() const;

    void setNrMaxCarti(int nrMaxCarti_);

    void setNrCartiImprumutate(int nrCartiImprumutate_);

    void setPretAbonament(int pretAbonament_);

    friend std::istream &operator>>(std::istream &is, Abonat &ab);

    friend std::ostream &operator<<(std::ostream &os, const Abonat &ab);

};

#endif
