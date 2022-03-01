#include <iostream>
#include <string>
#include <vector>

using namespace std;


class student {
    string nume;
    int anul_nasterii, numar_credite;
    double medie_generala;
public:

    student(string numele, int an_nastere, int nr_credite, double medie) {
        nume = numele;
        anul_nasterii = an_nastere;
        numar_credite = nr_credite;
        medie_generala = medie;
    }

    student() {}    //constructor implicit

    ~student() {}

    void setNume(char *numele) {
        nume = numele;
    }

    void setAnulNasterii(int anulNasterii) {
        anul_nasterii = anulNasterii;
    }

    void setNumarCredite(int numarCredite) {
        numar_credite = numarCredite;
    }

    void setMedieGenerala(double medieGenerala) {
        medie_generala = medieGenerala;
    }

    const string &getNume() const {
        return nume;
    }

    int getAnulNasterii() const {
        return anul_nasterii;
    }

    int getNumarCredite() const {
        return numar_credite;
    }

    double getMedieGenerala() const {
        return medie_generala;
    }

    bool operator==(const student &s) const {
        if (nume == s.nume)
            return true;
        return false;
    }


    friend istream &operator>>(istream &citire, student &s) {
        citire >> s.nume >> s.anul_nasterii >> s.numar_credite >> s.medie_generala;
        return citire;
    }

    friend ostream &operator<<(ostream &afisare, const student &s) {
        afisare << s.nume << " " << s.anul_nasterii << " " << s.numar_credite << " " << s.medie_generala;
        return afisare;
    }
};

class grupa {

    vector<student> studenti;
    int nr_studenti;
    double medie_generala_grupa;
public:

    grupa(vector<student> Studenti, int nr) {
        for (int i = 0; i < nr; i++)
            studenti.push_back(Studenti[i]);
        nr_studenti = nr;
    }

    const vector<student> &getStudenti() const {
        return studenti;
    }

/* Nu am pus si media_generala_grupe in constructor,
 * pentru ca aceasta trebuie calculata la urma, dupa ce
 * obiectul care apartine clasei 'grupa' a retinut vectorul
 * de studenti, respectiv nr_studenti */

    ~grupa() {}

    double medie(vector<student> Studenti, int nr);

    void delete_student(int index) {
        studenti.erase(studenti.begin() + index);
    }

    void add_student(student s) {
        studenti.push_back(s);
    }

    bool check_student(string s) {
        for (auto it: studenti)
            if (s == it.getNume())
                return true;
        return false;
    }

    friend ostream &operator<<(ostream &afisare, const grupa &g) {
        for (int i = 0; i < g.studenti.size(); i++)
            afisare << g.studenti[i] << "\n";
        return afisare;
    }
};

double grupa::medie(vector<student> Studenti, int nr) {
    double S = 0;
    for (int i = 0; i < nr; i++)
        S += Studenti[i].getMedieGenerala();
    medie_generala_grupa = (double) S / nr;
    return medie_generala_grupa;
}


int main() {
//    Stefan 2002 16 8.5
//    Daria 2004 15 9
//    Marian 2001 17 6
//    Mihai 2007 12 7
    string s;
    int nr_studenti, index;
    cout << "Introduceti numarul de studenti:";
    cin >> nr_studenti;
    student entitate;
    vector<student> entitati;
    for (int i = 0; i < nr_studenti; i++) {
        cin >> entitate;
        entitati.push_back(entitate);
    }
    cout << "Studentii introdusi sunt:\n";
    for (int i = 0; i < entitati.size(); i++)
        cout << entitati[i] << "\n";
    grupa studenti(entitati, nr_studenti);
    cout << "Introduceti studentul pe care doriti sa-l mai adaugati:";
    cin >> entitate;
    studenti.add_student(entitate);
    cout << "Studentii dupa introducere:\n" << studenti;
    cout << "Introduceti pozitia de pe care doriti sa stergeti un student: ";
    cin >> index;
    studenti.delete_student(index);
    cout << "Studentii dupa stergere:\n" << studenti;
    cout << "Introduceti studentul pe care doriti sa-l cautati:";
    cin >> s;
    if (studenti.check_student(s))
        cout << s << " se afla in grupa\n";
    else
        cout << s << " nu se afla in grupa\n";
    cout << "Media generala a grupei este: " << studenti.medie(studenti.getStudenti(), nr_studenti);
    return 0;
}