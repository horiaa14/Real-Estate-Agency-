#ifndef APARTAMENT_H_INCLUDED
#define APARTAMENT_H_INCLUDED
#include "Locuinta.h"
#pragma once

class Apartament: public Locuinta {
private:
    int nrEtaj;
public:
    Apartament(const std::string& nume = "", const std::string& prenume = "", double Suprafata = 0, double Discount = 0, double PretInchiriere = 0, int etaj = 0);
    int getNrEtaj() const;
    void setEtaj(int);
    void afisareInformatiiLocuinta();
    double getPretChirieApartament() const;
    friend std::istream& operator >> (std::istream&, Apartament&);
    friend std::ostream& operator << (std::ostream&, const Apartament&);
};

#endif // APARTAMENT_H_INCLUDED
