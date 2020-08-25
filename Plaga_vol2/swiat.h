#ifndef SWIAT_H
#define SWIAT_H

#include "Kraj/kraj.h"

class Swiat: public Kraj
{
public:
friend class Symulator;
    Swiat();
    ~Swiat();
    int liczba_krajow;

private:
    void Foblicz(Kraj k);
    void Fpopulacja(Kraj k);
    void Fzarazonych(Kraj k);
    void Fuzdrowionych(Kraj k);
    void Fchorych(Kraj k);
    void Fzdrowych(Kraj k);
    void Fofiar(Kraj k);


};

#endif // SWIAT_H
