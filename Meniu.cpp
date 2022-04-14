#include "Meniu.h"

Meniu::Meniu() {
    std::cout << "Bine ati venit la Biblioteca Nationala a Romaniei\n";
    std::cout << "-------------------------------------------------\n";
    while (comanda != "EXIT") {
        std::cout << "Pentru a introduce un abonat, scrieti ADD\n";
        std::cout << "Pentru a afisa numarul total de abonati, scrieti TOTAL\n";
        std::cout << "Pentru a verifica daca un abonat se afla in baza de date, scrieti SEARCH\n";
        std::cout << "Pentru a afla varsta unui abonat, scrieti AGE\n";
        std::cout << "Pentru a parasi meniul, scrieti EXIT\n";
        std::cin >> comanda;
        std::string nume;
        if (comanda == "ADD") {
            Abonat ab;
            std::cin >> ab;
            std::shared_ptr<Abonat> a = std::make_shared<Abonat>(ab);
            d.addAbonati(a);
        } else if (comanda == "TOTAL") {
            if (d.getAbonati().size() == 0)
                std::cout << 0 << "\n";
            else
                std::cout << d << "\n";
        } else if (comanda == "TOTAL")
            std::cout << d.getAbonati().size() << "\n";
        else if (comanda == "SEARCH") {
            bool gasit = false;
            std::cout << "Introduceti numele pe care doriti sa-l cautati:";
            std::cin >> nume;
            for (auto it: d.getAbonati()) {
                if (it->getName() == nume) {
                    gasit = true;
                    std::cout << "Abonatul " << nume << " a fost gasit in baza de date!\n";
                    break;
                }
            }
            if (!gasit)
                std::cout << "Abonatul " << nume << " nu a fost gasit in baza de date!\n";
        } else if (comanda == "AGE") {
            bool gasit = false;
            std::cout << "Introduceti numele pe care doriti sa-l cautati:";
            std::cin >> nume;
            for (auto it: d.getAbonati()) {
                if (it->getName() == nume) {
                    gasit = true;
                    std::cout << "Abonatul " << nume << " are varsta de " << it->getVarsta(14, 4, 2022) << " de ani\n";
                    break;
                }
            }
            if (!gasit)
                std::cout << "Abonatul " << nume << " nu a fost gasit in baza de date!\n";
        }
    }
};