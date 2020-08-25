#ifndef TRANSMISJA_H
#define TRANSMISJA_H

#include "zwierzeta.h"

class Transmisja :  public Zwierzeta
{
public:
    friend class Widget;
    Transmisja();
    bool krew_1;
    bool krew_2;
    bool powietrze_1;
    bool powietrze_2;
    bool woda_1;
    bool woda_2;


};

#endif // TRANSMISJA_H
