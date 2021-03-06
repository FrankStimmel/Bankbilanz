#include "fstaat.h"


FStaat::FStaat(){
    SchuldenAnBanken << FGeld("",0.0) << FGeld("",0.0);
    }


FStaat::FStaat(QString NAME){
    Name     = NAME;
    SchuldenAnBanken << FGeld("",0.0) << FGeld("",0.0);

    DickerRahmenSchuldenAnBanken = false;
    }


//####################################################################################################################################


void FStaat::Reset_Staatsbilanz_to_Null(){
    SchuldenAnBanken[0] = FGeld("",0.0);
    SchuldenAnBanken[1] = FGeld("",0.0);
    }


//#########################################################################################################################


QString FStaat::Checken_ob_Bilanz_valide_ist_sonst_Fehlermeldung(){

    if(SchuldenAnBanken[0].Get_Cents() < 0 ){
        return("In der Bilanz des Staates: \n\n"
               "Die Schulden an die Bank A dürfen nicht negativ sein.");
        }

    if(SchuldenAnBanken[1].Get_Cents() < 0 ){
        return("In der Bilanz des Staates: \n\n"
               "Die Schulden an die Bank B dürfen nicht negativ sein.");
        }

    return("");
    }
