#ifndef FAKTIONSTAATUEBERWEISTGIRALGELDAN_H
#define FAKTIONSTAATUEBERWEISTGIRALGELDAN_H


#include <QDebug>
#include "Bilanzen/fallebilanzen.h"
#include "ffinanztransaktion.h"


class FAktionStaatUeberweistGiralgeldAn : public FFinanzTransaktion

{

public:

    FAktionStaatUeberweistGiralgeldAn();
    FAktionStaatUeberweistGiralgeldAn(FGeld BETRAG, int NACHBANKNR, int NACHBANKKUNDENNR);

    void Execute_on(FAlleDaten *AlleDaten);
    void Dicke_Rahmen_zeichnen(FAlleDaten *AlleDaten, bool wert);



private:

    // Daten
    FGeld Betrag;
    int NachBankNr;
    int NachBankKundenNr;

};

#endif
