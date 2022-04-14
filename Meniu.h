#ifndef _MENIU_H
#define _MENIU_H
#pragma once

#include "Dosar.h"

class Meniu : public Dosar {
    Dosar d;
    std::string comanda;
public:
    Meniu();
};

#endif
