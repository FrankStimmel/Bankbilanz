#ifndef FAKTIONKUNDEZAHLTSPARBUCHGELDEIN_H
#define FAKTIONKUNDEZAHLTSPARBUCHGELDEIN_H


#include <QDebug>
#include "Bilanzen/fallebilanzen.h"
#include "ffinanztransaktion.h"


class FAktionKundeZahltSparbuchgeldEin : public FFinanzTransaktion

{

public:

    FAktionKundeZahltSparbuchgeldEin();
    FAktionKundeZahltSparbuchgeldEin(FGeld BETRAG, int BANKNR, int BANKKUNDENNR);

    void Execute_on(FAlleDaten *AlleDaten);



private:

    // Daten
    FGeld Betrag;
    int BankKundenNr;
    int BankNr;

};

#endif // FAKTIONKUNDEZAHLTSPARBUCHGELDEIN_H
