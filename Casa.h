#ifndef CASA_H_INCLUDED
#define CASA_H_INCLUDED
#include <vector>
#include "Locuinta.h"
#pragma once

class Casa: public Locuinta {
private:
    double suprafataCurte;
    double pretInchiriereCurte; // pret inchiriere curte / m^2
    std::vector<double> suprafataEtaj;
public:
    Casa(const std::string& nume = "", const std::string& prenume = "", double Suprafata = 0, double Discount = 0, double PretInchiriere = 0, double SuprafataCurte = 0
         , double PretInchiriereCurte = 0);

    double getSuprafataCurte() const;
    void setSuprafataCurte(double);
    double getPretInchiriereCurte() const;
    void setPretInchiriereCurte(double);
    double getPretChirieCasa() const;
    void afisareInformatiiLocuinta();
    friend std::istream& operator >> (std::istream&, Casa&);
    friend std::ostream& operator << (std::ostream&, const Casa&);
};

#endif // CASA_H_INCLUDED
