#ifndef LOCUINTA_H_INCLUDED
#define LOCUINTA_H_INCLUDED
#include <iostream>
#pragma once

class Locuinta {
protected:
    std::string numeClient;
    std::string prenumeClient;
    double suprafataUtila;
    double discount;
    double pretInchiriere; // Pretul de inchiriere / m^2
public:
    Locuinta(const std::string& nume = "", const std::string& prenume = "", double Suprafata = 0, double Discount = 0, double PretInchiriere = 0);
    virtual ~Locuinta();
    std::string getNumeClient() const;
    void setNumeClient(std::string&);
    std::string getPrenumeClient() const;
    void setPrenumeClient(std::string&);
    double getSuprafataUtila() const;
    void setSuprafataUtila(double);
    double getDiscount() const;
    void setDiscount(double);
    double getPretInchiriere() const;
    void setPretInchiriere(double);
    virtual void afisareInformatiiLocuinta();
    friend std::istream& operator >>(std::istream&, Locuinta&);
    friend std::ostream& operator << (std::ostream&, const Locuinta&);
};

#endif // LOCUINTA_H_INCLUDED
