#ifndef AGENTIEIMOBILIARE_H_INCLUDED
#define AGENTIEIMOBILIARE_H_INCLUDED
#include "Gestiune.h"
#pragma once

class AgentieImobiliare {
private:
    static AgentieImobiliare* agentie;
    std::string numeManager;
    std::string prenumeManager;
    std::string dataInfiintare;
    Gestiune<Apartament> gestiuneApartamente;
    Gestiune<Casa> gestiuneCase;
    AgentieImobiliare(const std::string& NumeManager = "", const std::string& PrenumeManager = "", const std::string& DataInfiintare = "");
public:
    AgentieImobiliare(AgentieImobiliare& ) = delete; // Sterg constructorul de copiere
    void operator = (const AgentieImobiliare& ) = delete; // Sterg operatorul de atribuire
    static AgentieImobiliare* getInstance();
    std::string getNumeManager() const;
    std::string getPrenumeManager() const;
    std::string getDataInfiintare() const;
    void inserareImobil(Locuinta&);
    void afisareImobile() const;
};

#endif // AGENTIEIMOBILIARE_H_INCLUDED
