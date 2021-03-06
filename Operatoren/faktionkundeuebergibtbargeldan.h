#ifndef FAKTIONKUNDEUEBERGIBTBARGELDAN_H
#define FAKTIONKUNDEUEBERGIBTBARGELDAN_H


#include <QDebug>
#include "Bilanzen/fallebilanzen.h"
#include "ffinanztransaktion.h"


class FAktionKundeUebergibtBargeldAn : public FFinanzTransaktion

{

public:

    FAktionKundeUebergibtBargeldAn();
    FAktionKundeUebergibtBargeldAn(FGeld BETRAG, int VonPersonenNR, int NachPersonenNR);

    void Execute_on(FAlleDaten *AlleDaten);



private:

    // Daten
    FGeld Betrag;
    int VonPersonenNr;
    int NachPersonenNr;


};

#endif
