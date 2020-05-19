#include "AgentieImobiliare.h"
using namespace std;

int main() {
    AgentieImobiliare* ag = ag->getInstance();
    vector<Apartament> Apartamente;
    vector<Casa> Case;
    // Citirea, memorarea si afisarea a n obiecte
    Gestiune<Apartament>::citireNobiecte(Apartamente);
    Gestiune<Casa>::citireNcase(Case);
    for(unsigned i = 0; i < Apartamente.size(); ++i)
        ag->inserareImobil(Apartamente[i]);
    for(unsigned i = 0; i < Case.size(); ++i)
        ag->inserareImobil(Case[i]);
    //ag->afisareImobile();
    delete ag;
    return 0;
}

/*Gestiune<Apartament> gestiuneApartament;
    Apartament ap1, ap2, ap3;
    cin >> ap1 >> ap2 >> ap3;
    gestiuneApartament += ap1;
    gestiuneApartament += ap2;
    gestiuneApartament += ap3;
    //cout << gestiuneApartament;
    cout << gestiuneApartament.cautareLocuinta("Vlad", "Andrei");*/
    /*
    // testare Copy-Constructor
    Gestiune<Apartament> gest1;
    Gestiune<Apartament> gest2(gest1);
    Apartament ap;
    cin >> ap;
    gest2 += ap;
    cout << gest2;
    cout << gest1;*/
    /*
    // testare operator =
    Gestiune<Apartament> gest1, gest2;
    gest1 = gest2;
    Apartament ap;
    cin >> ap;
    gest1 += ap;
    cout << gest1;
    cout << gest2;*/
    /*vector<Apartament> x;
    vector<Casa> y;
    Gestiune<Apartament>::citireNobiecte(x);
    Gestiune<Casa>::citireNcase(y);*/
