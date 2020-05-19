#include "Apartament.h"
using namespace std;

Apartament::Apartament(const string& nume, const string& prenume, double SuprafataUtila, double Discount, double PretInchiriere, int Etaj): Locuinta(nume, prenume, SuprafataUtila, Discount, PretInchiriere) {
    nrEtaj = Etaj;
}

int Apartament::getNrEtaj() const {
    return nrEtaj;
}

void Apartament::setEtaj(int val) {
    nrEtaj = val;
}

void Apartament::afisareInformatiiLocuinta() {
    cout << "Numele clientului este " << numeClient << "\n";
    cout << "Prenumele clientului este " << prenumeClient << "\n";
    cout << "Suprafata utila este de " << suprafataUtila << " m^2\n";
    cout << "Discount-ul acordat este de " << discount << "%\n";
    cout << "Pretul de inchiriere / m^2 este de " << pretInchiriere << "$\n";
    cout << "Apartamentul se afla la etajul " << nrEtaj << "\n";
}

double Apartament::getPretChirieApartament() const {
    double x = getPretInchiriere() * getSuprafataUtila();
    return x - (getDiscount() / 100 * x);
}

istream& operator >> (istream& in, Apartament& ap) {
    in >> static_cast<Locuinta&>(ap);
    cout << "Introduceti etajul la care se afla apartamentul ";
    try {
        in >> ap.nrEtaj;
        if(ap.nrEtaj < 0)
            throw logic_error("Etajul nu poate fi negativ!");
    }
    catch(logic_error& error) {
        cout << "A aparut o eroare la citirea informatiilor despre apartament!\n";
        cout << error.what() << "\n";
        exit(1);
    }
    return in;
}

ostream& operator << (ostream& out, const Apartament& ap) {
    out << static_cast<const Locuinta&>(ap);
    out << "Apartamentul se afla la etajul " << ap.nrEtaj << "\n";
    return out;
}

