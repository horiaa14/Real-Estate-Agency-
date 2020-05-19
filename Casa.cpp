#include "Casa.h"
using namespace std;

Casa::Casa(const std::string& nume, const std::string& prenume, double Suprafata, double Discount, double PretInchiriere, double SuprafataCurte
           , double PretInchiriereCurte): Locuinta(nume, prenume, Suprafata, Discount, PretInchiriere) {

    suprafataCurte = SuprafataCurte;
    pretInchiriereCurte = PretInchiriereCurte;
}

double Casa::getSuprafataCurte() const {
    return suprafataCurte;
}

void Casa::setSuprafataCurte(double val) {
    suprafataCurte = val;
}

double Casa::getPretInchiriereCurte() const {
    return pretInchiriereCurte;
}

void Casa::setPretInchiriereCurte(double val) {
    pretInchiriereCurte = val;
}

double Casa::getPretChirieCasa() const {
    double x = getPretInchiriere() * getSuprafataUtila();
    return (x - (getDiscount() / 100 * x)) + getPretInchiriereCurte() * getSuprafataCurte();
}

void Casa::afisareInformatiiLocuinta() {
    cout << "Numele clientului este " << numeClient << "\n";
    cout << "Prenumele clientului este " << prenumeClient << "\n";
    cout << "Suprafata utila este de " << suprafataUtila << " m^2\n";
    cout << "Discount-ul acordat este de " << discount << "%\n";
    cout << "Pretul de inchiriere / m^2 este de " << pretInchiriere << "$\n";
    cout << "Suprafata curtii este de " << suprafataCurte << " m^2\n";
    cout << "Pretul de inchiriere / m^2 al curtii este de " << pretInchiriereCurte << "$\n";
    cout << "Suprafata utila pentru fiecare etaj este:\n";
    for(unsigned i = 0; i < suprafataEtaj.size(); ++i)
        cout << "Etajul " << i + 1 << " are " << suprafataEtaj[i] << " m^2\n";
}

istream& operator >> (istream& in, Casa& casa) {
    int et;
    in >> static_cast<Locuinta&>(casa);
    try {
        cout << "Introduceti suprafata curtii: ";
        in >> casa.suprafataCurte;
        if(casa.suprafataCurte < 0)
            throw logic_error("Suprafata curtii nu poate fi negativa!");
        if(casa.suprafataCurte < 20)
            throw logic_error("Curtea trebuie sa aiba cel putin 20 m^2!");
        cout << "Introduceti pretul de inchiriere al curtii: ";
        in >> casa.pretInchiriereCurte;
        if(casa.pretInchiriereCurte <= 10)
            throw logic_error("Pretul de inchiriere / m^2 al curtii trebuie sa fie mai mare de 10$");

        cout << "Introduceti numarul de etaje ale casei: ";
        in >> et;
        if(et < 2)
            throw logic_error("Casa trebuie sa aiba cel putin 2 etaje!");

        cout << "Introduceti suprafata utila pentru ficare dintre cele " << et << " etaje: ";
        double val;
        for(int i = 0; i < et; ++i) {
            in >> val;
            if(val <= 10)
                throw logic_error("Suprafata utila trebuie sa fie mai mare de 10 m^2 pentru fiecare etaj!");
            casa.suprafataEtaj.emplace_back(val);
        }
    }
    catch(logic_error& error) {
        cout << "A aparut o eroare la citirea informatiilor despre casa!\n";
        cout << error.what() << "\n";
        exit(1);
    }
    return in;
}

ostream& operator << (ostream& out, const Casa& casa) {
    out << static_cast<const Locuinta&>(casa);
    out << "Suprafata curtii este de " << casa.suprafataCurte << " m^2\n";
    out << "Pretul de inchiriere / m^2 al curtii este de " << casa.pretInchiriereCurte << "$\n";
    out << "Casa are " << casa.suprafataEtaj.size() << " etaje\n";
    out << "Etajele au urmatoarele suprafete:\n";
    vector<double>::const_iterator it;
    int cnt = 0;
    for(it = casa.suprafataEtaj.begin(); it != casa.suprafataEtaj.end(); ++it) {
        out << "Etajul " << cnt + 1 << " are " << (*it) << " m^2\n";
        ++cnt;
    }
    return out;
}
