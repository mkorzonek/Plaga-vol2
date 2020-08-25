#ifndef KRAJ_H
#define KRAJ_H

#include <iostream>
#include "Patogen/patogen.h"

using namespace std;

class Kraj

{
public:
    friend class Symulator;
    friend class Widget;
    Kraj(string="Kraj",int=10000000,int=100000,int=20,int=0,float=0.5,float=0.5, float=0.5);
    ~Kraj();
    string nazwa;
    int powierzchnia;
    struct tab
    {
        float *populacja = new float[1000];
        float *chorych = new float[1000];
        float *zdrowych = new float[1000];
        float *dziennie_zarazonych = new float[1000];
        float *dziennie_uzdrowionych = new float[1000];

    };
    tab tablica;
    int dzien_zarazy;
    float ofiar;

    void Fgestosc_zaludnienia(); //oblicza gęstość zaludnienia string nazwa
    void Fzeruj();
    void Fnext_day();

private:

    float zarazliwosc;
    float wsp_zar;
    float urbanizacja;
    float wilgotnosc;
    float medycyna;
    int temperatura;
    int czas_choroby;
    int czas_zarazania;

    void Fwsp_zar(Patogen p);
    void Fczas_zar(Patogen p);
    void Foblicz(Patogen p);
    void Fczas_zar();
    void Fpopulacja();
    void Fchorych();
    void Fzdrowych();
    void Fzarazonych();
    void Fuzdrowionych();
    void Fofiar();
    void Fwczytaj(string n); //wczytuje dane z pliku


};

#endif // KRAJ_H
