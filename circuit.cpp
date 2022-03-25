#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
    int speed;
    string name;
public:
    Car(string Name, int Speed) {
        speed = Speed;
        name = Name;
    }

    Car();

    virtual ~Car() {
        name.clear();
    }

    int getSpeed() const {
        return speed;
    }

    static bool sortare(Car a, Car b);

    const string &getname() const {
        return name;
    }

    void setname(const string &Name) {
        Car::name = Name;
    }

    void setSpeed(int speed) {
        Car::speed = speed;
    }

    friend istream &operator>>(istream &is, Car &car) {
        is >> car.name >> car.speed;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Car &car) {
        os << "Numele masinii: " << car.name << "\n";
        os << "Viteza masinii: " << car.speed << "\n";
        return os;
    }
};

bool Car::sortare(Car a, Car b) {
    return a.speed > b.speed;
}


class Circuit {
    vector<Car> masini;
public:
    void addCar(string name, int speed) {
        Car m(name, speed);
        masini.push_back(m);
    }

    void addCar_2(Car masina) {
        masini.push_back(masina);
    }

    virtual ~Circuit() {
        masini.clear();
    }

    void showRating() {
        sort(masini.begin(), masini.end(), Car::sortare);
        for (int i = 0; i < masini.size(); i++) {
            cout << "Locul " << i + 1 << "\n";
            cout << masini[i];
        }
    }
};

int main() {
    Circuit C;
    C.addCar("Toyota", 90);
    C.addCar("Fiat", 75);
    C.addCar("Mercedes", 120);
    C.addCar("BMW", 100);
    C.showRating();
    return 0;
}

