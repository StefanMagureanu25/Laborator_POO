#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    // programare procedurala
    vector<tuple<int, int>> compozitie;
    /* retin cantitate de gem, respectiv frisca in vector
     * primul element din tuple este cantitatea de frisca
     * iar al doilea reprezinta cantitatea de gem */
    string forma, comanda;
    int n, c1, c2, l, L, r, h, x;
    /* Legenda:
     * n: numarul total de forme de copt
     * c1: cateta 1
     * c2: cateta 2
     * l: latura mica (dreptunghi), respectiv latura (patrat)
     * L: latura mare
     * r: raza
     * h: inaltime
     * x: pozitia unde se afla forma(-1, ca numar de la 0) */
    cin >> n;
    /* am cautat pe net o aproximatie
     * pentru valoarea lui pi */
    double pi = 2 * acos(0.0); //arccos(0) = pi/2
    int count = 0; // retin numarul de forme de copt
    /* presupunem ca nu ar folosi chiar toate cele n forme de copt,
     * problema mentionand ca are la dispozitie n forme de copt, deci
     * nu e neaparat necesar sa le foloseasca pe toate */
    while (count < n) {
        double arie = 0, volum = 0; //voi reseta la fiecare pas aria si volumul
        cin >> comanda;
        if (comanda == "ADD") {
            cin >> forma;
            if (forma == "cerc") {
                cin >> r >> h;
                arie = pi * pow(r, 2);
                volum = arie * h;
            } else if (forma == "dreptunghi") {
                cin >> l >> L >> h;
                arie = l * L;
                volum = arie * h;
            } else if (forma == "patrat") {
                cin >> l >> h;
                arie = pow(l, 2);
                volum = arie * h;
            } else if (forma == "triunghi_dreptunghic") {
                cin >> c1 >> c2 >> h;
                arie = (c1 * c2) / 2;
                volum = arie * h;
            }
            compozitie.push_back({arie, volum * 2});
            cout << "Aveti nevoie de " << ceil(arie) << " g de frisca, respectiv " << ceil(volum * 2) << " g de gem\n";
            /* Am folosit ceil, pentru ca in cazul cercului nu va da un numar intreg si practic nu putem avea
             * o cantitate de frisca/gem care sa nu fie fixa */
            count++;
        } else if (comanda == "REMOVE") {
            cin >> x;
            compozitie.erase(compozitie.begin() + x - 1);
            /* Am presupus ca acea forma nu va putea fi refolosita, nefiind nevoie sa scad din
             * numarul total de forme folosite pana in acel moment */
        } else if (comanda == "TOTAL") {
            int sum_frisca = 0, sum_gem = 0;
            for (auto it: compozitie) {
                sum_frisca += get<0>(it);
                sum_gem += get<1>(it);
            }
            cout << "Cantitatea totala necesara pentru frisca este: " << sum_frisca << '\n';
            cout << "Cantitatea totala necesara pentru gem este: " << sum_gem << '\n';
            // Se va afisa la fiecare comanda de TOTAL cantitatea de gem si de frisca din acel moment
        } else if (comanda == "STOP")
            break;
    }
    // Programul se incheie fie prin comanda STOP, fie prin epuizarea numarului total de forme de copt
    if (count == n) {
        /*As vrea sa afisez si cantitatea totala de frisca si gem, in cazul in care s-au folosit deja
         * toate formele de copt si nu s-a afisat vreun TOTAL */
        int sum_frisca = 0, sum_gem = 0;
        for (auto it: compozitie) {
            sum_frisca += get<0>(it);
            sum_gem += get<1>(it);
        }
        cout << "Cantitatea totala necesara pentru frisca este: " << sum_frisca << '\n';
        cout << "Cantitatea totala necesara pentru gem este: " << sum_gem << '\n';
    }
    return 0;
}