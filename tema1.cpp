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

    ~student() {
        nume.clear();
    }

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

    ~grupa() {
        studenti.clear();
    }

    double medie(vector<student> Studenti);

    void delete_student(int index) {
        //numaratoarea incepe de la 0
        if (index <= studenti.size() - 1)
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

double grupa::medie(vector<student> Studenti) {
    double S = 0;
    for (int i = 0; i < Studenti.size(); i++)
        S += Studenti[i].getMedieGenerala();
    medie_generala_grupa = (double) S / Studenti.size();
    return medie_generala_grupa;
}


int main() {
    string s, operatie;
    int nr_studenti, index;
    cout << "Introduceti numarul de studenti:";
    cin >> nr_studenti;
    student entitate;
    vector<student> entitati;
    for (int i = 0; i < nr_studenti; i++) {
        cin >> entitate;
        entitati.push_back(entitate);
    }
    grupa studenti(entitati, nr_studenti);
    while (operatie != "EXIT") {
        cout << "Operatii(meniul principal):\n";
        cout << "Pentru a adauga un student, tastati ADD\n";
        cout << "Pentru a sterge un student, tastati DELETE\n";
        cout << "Pentru a cauta un student dupa nume, tastati SEARCH\n";
        cout << "Pentru a vedea toti studentii introdusi, tastati SEE\n";
        cout << "Pentru a calcula media generala a tuturor studentilor, tastati AVERAGE\n";
        cout << "Pentru a iesi, tastati EXIT\n";
        cin >> operatie;
        if (operatie == "ADD") {
            cout << "Introduceti datele pentru student:";
            cin >> entitate;
            studenti.add_student(entitate);
        } else if (operatie == "DELETE") {
            cout << "Introduceti pozitia de pe care doriti sa stergeti studentul:";
            cin >> index;
            studenti.delete_student(index);
        } else if (operatie == "SEE") {
            cout << studenti;
        } else if (operatie == "AVERAGE") {
            cout << "Media generala a grupei este: " << studenti.medie(studenti.getStudenti()) << "\n";
        } else if (operatie == "SEARCH") {

            cout << "Introduceti numele studentului pe care doriti sa-l cautati:";
            cin >> s;
            if (studenti.check_student(s))
                cout << s << " se afla in grupa\n";
            else
                cout << s << " nu se afla in grupa\n";
        }
    }
}