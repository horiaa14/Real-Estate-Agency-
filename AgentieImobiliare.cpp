#include "AgentieImobiliare.h"

AgentieImobiliare* AgentieImobiliare::agentie = nullptr;

AgentieImobiliare* AgentieImobiliare::getInstance() {
    if(agentie == nullptr)
        agentie = new AgentieImobiliare;
    return agentie;
}

AgentieImobiliare::AgentieImobiliare(const std::string& NumeManager, const std::string& PrenumeManager, const std::string& DataInfiintare) {
    numeManager = NumeManager;
    prenumeManager = PrenumeManager;
    dataInfiintare = DataInfiintare;
}

std::string AgentieImobiliare::getNumeManager() const {
    return numeManager;
}

std::string AgentieImobiliare::getPrenumeManager() const {
    return prenumeManager;
}

std::string AgentieImobiliare::getDataInfiintare() const {
    return dataInfiintare;
}

void AgentieImobiliare::inserareImobil(Locuinta& loc) {
    if(Apartament* aux = dynamic_cast<Apartament*>(&loc))
        gestiuneApartamente += *aux;

    if(Casa* aux = dynamic_cast<Casa*>(&loc))
        gestiuneCase += *aux;
}

void AgentieImobiliare::afisareImobile() const {
    std::cout << "Imobilele agentiei sunt:\n";
    std::cout << gestiuneApartamente << "\n" << gestiuneCase << "\n";
}
