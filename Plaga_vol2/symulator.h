#ifndef SYMULATOR_H
#define SYMULATOR_H

#include "swiat.h"
#include "Kraj/kraj.h"
#include "Patogen/patogen.h"

;
class Symulator
{
public:
   friend class Widget;
    int obecny_kraj;
    int pacjent_0;
    Symulator();
    ~Symulator();
    void Fwsp_zar();
    void Ffirstclick();
    void Fstart();
    void Fnext_day();
    void Foblicz();

    void Fdelete();

    Patogen wirus;
    Swiat ziemia;
    Kraj *k=new Kraj[ziemia.liczba_krajow];


};


#endif // SYMULATOR_H
