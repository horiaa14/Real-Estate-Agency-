#include "Locuinta.h"
using namespace std;

Locuinta::Locuinta(const string& nume, const string& prenume, double Suprafata, double Discount, double PretInchiriere) {
    numeClient = nume;
    prenumeClient = prenume;
    suprafataUtila = Suprafata;
    discount = Discount;
    pretInchiriere = PretInchiriere;
}

Locuinta::~Locuinta() {

}

string Locuinta::getNumeClient() const {
    return numeClient;
}

void Locuinta::setNumeClient(string& nume) {
    numeClient = nume;
}

string Locuinta::getPrenumeClient() const {
    return prenumeClient;
}

void Locuinta::setPrenumeClient(string& prenume) {
    prenumeClient = prenume;
}

double Locuinta::getSuprafataUtila() const {
    return suprafataUtila;
}

void Locuinta::setSuprafataUtila(double x) {
    suprafataUtila = x;
}

double Locuinta::getDiscount() const {
    return discount;
}

void Locuinta::setDiscount(double x) {
    discount = x;
}

double Locuinta::getPretInchiriere() const {
    return pretInchiriere;
}

void Locuinta::setPretInchiriere(double x) {
    pretInchiriere = x;
}

void Locuinta::afisareInformatiiLocuinta() {
    cout << "Numele clientului este " << numeClient << "\n";
    cout << "Prenumele clientului este " << prenumeClient << "\n";
    cout << "Suprafata utila este de " << suprafataUtila << " m^2\n";
    cout << "Discount-ul acordat este de " << discount << "%\n";
    cout << "Pretul de inchiriere / m^2 este de " << pretInchiriere << "$\n";
}

istream& operator >> (istream& in, Locuinta& loc) {
    try {
        cout << "Introduceti numele persoanei: ";
        in >> loc.numeClient;
        if(loc.numeClient.length() < 3)
            throw logic_error("Numele persoanei trebuie sa aiba cel putin 3 litere!");
        for(unsigned i = 0; i < loc.numeClient.length(); ++i)
            if(!isalpha(loc.numeClient[i]))
                throw logic_error("Numele persoanei trebuie sa contina doar litere");
        cout << "Introduceti prenumele persoanei: ";
        in >> loc.prenumeClient;
        if(loc.prenumeClient.length() < 3)
            throw logic_error("Prenumele persoanei trebuie sa aiba cel putin 3 litere!");
        for(unsigned i = 0; i < loc.prenumeClient.length(); ++i)
            if(!isalpha(loc.prenumeClient[i]))
                throw logic_error("Prenumele persoanei trebuie sa contina doar litere");
        cout << "Introduceti suprafata locuintei: ";
        in >> loc.suprafataUtila;
        if(loc.suprafataUtila < 30)
            throw logic_error("Suprafata locuintei trebuie sa fie de cel putin 30 m^2!");
        cout << "Introduceti discount-ul: ";
        in >> loc.discount;
        if(loc.discount < 0 || loc.discount > 10)
            throw logic_error("Discount-ul trebuie sa fie intre 0 si 10!");
        cout << "Introduceti pretul de inchiriere / m^2: ";
        in >> loc.pretInchiriere;
        if(loc.pretInchiriere < 100)
            throw logic_error("Pretul de inchiriere trebuie sa fie de cel putin 100$");
    }
    catch(logic_error& error) {
        cout << "A aparut o eroare la citirea datelor!\n";
        cout << error.what();
        exit(1);
    }
    return in;
}

ostream& operator << (ostream& out, const Locuinta& loc) {
    out << "Numele clientului este " << loc.getNumeClient() << "\n";
    out << "Prenumele clientului este " << loc.getPrenumeClient() << "\n";
    out << "Suprafata locuintei inchiriate este de " << loc.suprafataUtila << " m^2\n";
    out << "Discount-ul oferit este de " << loc.discount << "%\n";
    out << "Pretul de inchiriere / m^2 este de " << loc.pretInchiriere << "$\n";
    return out;
}
