#ifndef _PERSOANA_H_
#define _PERSOANA_H_
#pragma once

#include <iostream>
#include <string>

class Persoana {
private:
    std::string name, cnp;
public:
    Persoana();

    Persoana(std::string name, std::string CNP);

    void setName(const std::string &nume);

    void setCnp(const std::string &cnp);

    const std::string &getName() const;

    const std::string &getCnp() const;

    Persoana(Persoana &pers);

    virtual ~Persoana();

    Persoana &operator=(const Persoana &p);

    friend std::istream &operator>>(std::istream &is, Persoana &pers);

    friend std::ostream &operator<<(std::ostream &os, const Persoana &pers);
};


#endif
