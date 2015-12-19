#ifndef FAKTIONEINJAHRISTVORBEI_H
#define FAKTIONEINJAHRISTVORBEI_H


#include <QDebug>
#include "Bilanzen/fallebilanzen.h"
#include "ffinanztransaktion.h"


class FAktionEinJahrIstVorbei : public FFinanzTransaktion

{

public:

    FAktionEinJahrIstVorbei();


    void Execute_on(FAlleDaten *AlleDaten);


    // Daten
    QString Fehlerbeschreibung;


    // Methoden
    QString Runden(double wert);




};

#endif