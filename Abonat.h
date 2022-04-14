#ifndef _ABONAT_H_
#define _ABONAT_H_
#pragma once

#include "Persoana.h"


class nr_Max : public std::exception {
public:
    nr_Max();

    const char *what() const noexcept override;
};

class Carti_imprumutate : public std::exception {
public:
    Carti_imprumutate();

    const char *what() const noexcept override;
};

class Abonat : public Persoana {
    int nrMaxCarti, nrCartiImprumutate, pretAbonament;
public:
    Abonat();

    Abonat(std::string name_, std::string CNP_);

    Abonat(std::string name_, std::string CNP_, int nrMaxCarti_, int nrCartiImprumutate_,
           int pretAbonament_);

    Abonat(const Abonat &ab);

    Abonat &operator=(const Abonat &ab);

    virtual int getVarsta(int zi_curenta, int luna_curenta, int an_curent) override;

    int getNrMaxCarti() const;

    int getNrCartiImprumutate() const;

    int getPretAbonament() const;

    void setNrMaxCarti(int nrMaxCarti_);

    void setNrCartiImprumutate(int nrCartiImprumutate_);

    void setPretAbonament(int pretAbonament_);

    friend std::istream &operator>>(std::istream &is, Abonat &ab);

    friend std::ostream &operator<<(std::ostream &os, std::shared_ptr<Abonat> ab);

};

#endif
