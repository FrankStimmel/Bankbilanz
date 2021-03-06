#ifndef FSTAAT_H
#define FSTAAT_H

#include "fgeld.h"
#include <QtGui>


class FStaat

{

public:

    // Konstruktor
    FStaat();
    FStaat(QString NAME);


    // Daten
    QString Name;
    QVector <FGeld> SchuldenAnBanken;

    bool DickerRahmenSchuldenAnBanken;


    // Methoden
    void Reset_Staatsbilanz_to_Null();
    QString Checken_ob_Bilanz_valide_ist_sonst_Fehlermeldung();



};

#endif // FSTAAT_H
