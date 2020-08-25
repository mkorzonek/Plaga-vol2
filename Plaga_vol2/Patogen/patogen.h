#ifndef PATOGEN_H
#define PATOGEN_H


#include <iostream>
#include "Transmisja/transmisja.h"
#include "Odpornosc/odpornosc.h"
#include "Odpornosc/cechy.h"

using namespace std;
class Patogen : public Transmisja, public Odpornosc, public Cechy
{

public:
    friend class Widget;
    Patogen();
    string nazwa;

};

#endif // PATOGEN_H
