#ifndef _PERSOANA_H_
#define _PERSOANA_H_
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Cnp_incorect : public std::exception {
public:
    Cnp_incorect();

    const char *what() const noexcept override;
};

class Zi_invalida : public std::exception {
public:
    Zi_invalida();

    const char *what() const noexcept override;
};

class Luna_invalida : public std::exception {
public:
    Luna_invalida();

    const char *what() const noexcept override;
};

class Invalid_argument : public std::exception {
public:
    Invalid_argument();

    const char *what() const noexcept override;
};

class Persoana {
private:
    std::string name, cnp;
public:
    Persoana();

    Persoana(std::string name, std::string CNP);

    void setName(const std::string &nume);

    void setCnp(const std::string &cnp);

    virtual int getVarsta(int zi_curenta, int luna_curenta, int an_curent);

    const std::string &getName() const;

    const std::string &getCnp() const;

    Persoana(Persoana &pers);

    virtual ~Persoana();

    Persoana &operator=(const Persoana &p);

    friend std::istream &operator>>(std::istream &is, Persoana &pers);

    friend std::ostream &operator<<(std::ostream &os, const Persoana &pers);
};


#endif
