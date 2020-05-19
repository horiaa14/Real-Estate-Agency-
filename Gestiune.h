#ifndef GESTIUNE_H_INCLUDED
#define GESTIUNE_H_INCLUDED
#include <set>
#include <utility>
#include "Casa.h"
#include "Apartament.h"
#include "ExceptiaMea.h"
#pragma once

template<typename T>
class Gestiune {
private:
    static int nrLocuinta;
    std::set<std::pair<Locuinta*, T*>> s;
public:
    Gestiune() = default;

    ~Gestiune() {
        nrLocuinta = 0;
        for(auto& it : s) {
            delete(it.first);
            delete(it.second);
        }
        s.clear();
    }

    Gestiune(const Gestiune& obGest) {
        nrLocuinta = obGest.nrLocuinta;
        for(auto& it : obGest.s) {
            Locuinta* locuinta = new Locuinta(*it.first);
            T* tipLocuinta = new T(*it.second);
            s.insert(std::make_pair(locuinta, tipLocuinta));
        }
    }

    Gestiune<T>& operator = (const Gestiune<T>& obGest) {
        if(this == &obGest)
            return *this;
        for(auto& it : s) {
            delete(it.first);
            delete(it.second);
        }
        s.clear();
        nrLocuinta = obGest.nrLocuinta;
        for(auto& it : obGest.s) {
            Locuinta* locuinta = new Locuinta(*it.first);
            T* tipLocuinta = new T(*it.second);
            s.insert(std::make_pair(locuinta, tipLocuinta));
        }
        return *this;
    }

    friend void operator += (Gestiune<T>& obGest, T& tipLocuinta) {
        // Inseram o noua locuinta in set
        ++Gestiune<T>::nrLocuinta;
        obGest.s.insert(std::make_pair(dynamic_cast<Locuinta*>(&tipLocuinta), &tipLocuinta)); // RTTI raportat la template-uri
    }

    int cautareLocuinta(const std::string& nume, const std::string& prenume) {
        // Functia returneaza numarul de locuinte inchiriate pentru un anumit client
        int ans = 0;
        typename std::set<std::pair<Locuinta*, T*>>::iterator s_it;
        for(s_it = s.begin(); s_it != s.end(); ++s_it)
            if(s_it->first->getNumeClient() == nume && s_it->first->getPrenumeClient() == prenume)
                ++ans;
        return ans;
    }

    static void citireNobiecte(std::vector<T>& v) {
        int nrLoc;
        try {
            std::cout << "Introduceti numarul de locuinte: ";
            std::cin >> nrLoc;
            if(nrLoc <= 0)
                throw myException("Trebuie sa introduceti informatii despre cel putin o locuinta!");

            for(int i = 0; i < nrLoc; ++i) {
                T loc;
                std::cin >> loc;
                v.emplace_back(loc);
            }
        }
        catch(myException& error) {
            std::cout << "A aparut o eroare la citirea obiectelor!\n";
            std::cout << error.what();
            exit(1);
        }

        std::cout << "Informatiile despre cele " << nrLoc << " locuinte sunt:\n";
        for(int i = 0; i < nrLoc; ++i)
            std::cout << v[i] << "\n";
    }

    // Supraincarcarea operatorului de afisare
    friend std::ostream& operator << (std::ostream& out, const Gestiune<T>& obGest) {
        out << "Informatiile despre cele " << obGest.s.size() << " locuinte:\n";
        for(auto it : obGest.s)
            out << *it.second;
        return out;
    }
};

template<typename T>
int Gestiune<T>::nrLocuinta = 0;

// Construim o specializare pentru tipul Casa
template<>
class Gestiune<Casa> {
private:
    static int nrCase;
    std::set<std::pair<Locuinta*, Casa*>> s;
public:
    Gestiune() {
        nrCase = 0;
    }

    ~Gestiune() {
        nrCase = 0;
        for(auto& it : s) {
            delete(it.first);
            delete(it.second);
        }
        s.clear();
    }

    Gestiune(const Gestiune<Casa>& obGest) {
        nrCase = obGest.nrCase;
        for(auto& it : obGest.s) {
            Locuinta* locuinta = new Locuinta(*it.first);
            Casa* casa = new Casa(*it.second);
            s.insert(std::make_pair(locuinta, casa));
        }
    }

    Gestiune<Casa>& operator = (const Gestiune<Casa>& obGest) {
        if(this == &obGest)
            return *this;
        for(auto& it : s) {
            delete(it.first);
            delete(it.second);
        }
        s.clear();
        nrCase = obGest.nrCase;
        for(auto& it : obGest.s) {
            Locuinta* locuinta = new Locuinta(*it.first);
            Casa* casa = new Casa(*it.second);
            s.insert(std::make_pair(locuinta, casa));
        }
        return *this;
    }

     friend void operator += (Gestiune<Casa>& obGest, Casa& casa) {
        // Inseram o noua locuinta in set
        ++Gestiune<Casa>::nrCase;
        obGest.s.insert(std::make_pair(dynamic_cast<Locuinta*>(&casa), &casa)); // RTTI raportat la template-uri
    }

    static void citireNcase(std::vector<Casa>& v) {
        try {
            std::cout << "Introduceti numarul de case: ";
            std::cin >> nrCase;
            if(nrCase <= 0)
                throw(std::logic_error("Trebuie sa introduceti informatii despre cel putin o casa!"));
            for(int i = 0; i < nrCase; ++i) {
                Casa casa;
                std::cin >> casa;
                v.emplace_back(casa);
            }
        }
        catch(std::logic_error& error) {
            std::cout << "A aparut o eroare la citirea caselor!\n";
            std::cout << error.what();
            exit(1);
        }
        std::cout << "Informatiile despre cele " << nrCase << " case sunt:\n";
        for(unsigned i = 0; i < v.size(); ++i)
            std::cout << v[i] << "\n";
    }

    friend std::ostream& operator << (std::ostream& out, const Gestiune<Casa>& obGest) {
        out << "Informatiile despre cele " << obGest.s.size() << " case:\n";
        for(auto it : obGest.s)
            out << *it.second;
        return out;
    }

    double calculeazaChirie() {
        double ans = 0;
        for(auto& it : s)
            ans += (*it.second).getPretChirieCasa();
        return ans;
    }
};

#endif // GESTIUNE_H_INCLUDED
