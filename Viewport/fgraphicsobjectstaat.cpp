#include "fgraphicsobjectstaat.h"



FGraphicsObjectStaat::FGraphicsObjectStaat(QGraphicsItem *parent) : QGraphicsObject(parent){
    FEinstellungen Einstel;
    AktuellerStiftFuerDenRand  = Einstel.Pen_SchwarzerStift();
    AktuelleObjectFarbe        = Einstel.Object_Color();
    }


FGraphicsObjectStaat::FGraphicsObjectStaat(int IdNUMMER, QGraphicsItem *parent) : QGraphicsObject(parent) {
    FEinstellungen Einstel;
    IdNummer                  = IdNUMMER;
    AktuellerStiftFuerDenRand = Einstel.Pen_SchwarzerStift();
    AktuelleObjectFarbe       = Einstel.Object_Color();
    }


//##################################################################################################################################


QRectF FGraphicsObjectStaat::boundingRect() const{        // Dieser Bereich ist anklickbar!
    return QRectF(0, 0, 170, 80);
    }

//###################################################################################################################################


void FGraphicsObjectStaat::Neu_zeichnen(FAlleDaten AlleDATEN){
    AlleDaten = AlleDATEN;
    update();
    }


//###################################################################################################################################


void FGraphicsObjectStaat::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    // Einstellungen
    FEinstellungen Einstel;
    QColor hellgrau        = Einstel.Hellgrau_Color();
    QPen PenSchwarzerStift = Einstel.Pen_SchwarzerStift();
    QFont serifFont        = Einstel.Font_Gross();
    QFont serifFont2       = Einstel.Font_Klein();


    // Kasten um alles
    painter->setPen(PenSchwarzerStift);
    painter->setBrush(Einstel.SehrSehrHellgrau_Color());
    painter->drawRect(0,0,170,80);

    // Hintergrund der Person
    painter->setBrush(AktuelleObjectFarbe);
    painter->drawRect(0,0,170,30);

    // Text für die Person
    painter->setFont(serifFont);
    painter->drawText(60,23,AlleDaten.Staat.Name);

    // Schulden Anzeige
    painter->setFont(serifFont2);
    Zeichne_Kasten_in_der_Bilanz(painter, 90, 37, 10,
                                 "Schulden:",
                                 AlleDaten.Staat.SchuldenAnBanken[0] + AlleDaten.Staat.SchuldenAnBanken[1],
                                 hellgrau,
                                 AlleDaten.Staat.DickerRahmenSchuldenAnBanken);
    }


//####################################################################################################################################


void FGraphicsObjectStaat::Zeichne_Kasten_in_der_Bilanz(QPainter* p,
                                                        float x, float y, float xText,
                                                        QString Text,
                                                        FGeld Zahlenwert,
                                                        QColor Farbe,
                                                        bool fetterRahmen){

    // Stift
    FEinstellungen Einstel;


    // Beschriftung zeichnen
    p->setPen(Einstel.Pen_SchwarzerStift());
    p->drawText(xText, y+18, Text);


    // Negative Werte als Warnung mit rotem Hintergrund zeichnen.
    if( Zahlenwert.Get_Cents() < 0 ){
        p->setBrush(Qt::red);
        p->setPen(Einstel.Pen_SchwarzerStift());
        p->drawRect(x,   y, 60, 25);
        p->drawText(x+5, y+18, Zahlenwert.Get_Euro_as_QString());
        }


    // Positive Werte mit der Farbe zeichnen.
    else if( Zahlenwert.Get_Cents() > 0 ){

        // Rahmen
        if(fetterRahmen)  p->setPen(Einstel.Pen_Dicker_RoterStift());
        else              p->setPen(Einstel.Pen_SchwarzerStift());

        p->setBrush(Farbe);
        p->drawRect(x, y, 60, 25);

        // Zahlentext
        p->setPen(Einstel.Pen_SchwarzerStift());
        p->setBrush(Farbe);
        p->drawText(x+5, y+18, Zahlenwert.Get_Euro_as_QString());
        }


    // Werte nahe 0 nur zeichnen, wenn der Rahmen fett ist.
    else{
        if(fetterRahmen){

            // Rahmen
            p->setPen(Einstel.Pen_Dicker_RoterStift());
            p->setBrush(Einstel.Hellgrau_Color());
            p->drawRect(x, y, 60, 25);

            // Zahlentext
            p->setPen(Einstel.Pen_SchwarzerStift());
            p->drawText(x+5, y+18, "");
            }
        }

    }


//####################################################################################################################################


void FGraphicsObjectStaat::Set_Object_visual_marked(bool wert){
    FEinstellungen Einstel;
    if(wert == true){
        AktuellerStiftFuerDenRand = Einstel.Pen_Dicker_SchwarzerStift();
        AktuelleObjectFarbe       = Einstel.ObjectAktiv_Color();
        }
    else{
        AktuellerStiftFuerDenRand = Einstel.Pen_SchwarzerStift();
        AktuelleObjectFarbe       = Einstel.Object_Color();
        }
    update();
    }


//####################################################################################################################################


void FGraphicsObjectStaat::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mouseReleaseEvent(event);
    emit IdNummer_vom_Staat_wurde_gesendet(DER_STAAT,true);
    }





