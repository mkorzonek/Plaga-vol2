#include "symulator.h"
#include "Kraj/kraj.h"
#include "swiat.h"
#include "widget.h"

Symulator::Symulator(Kraj [] *kraje)
{

}
Symulator::~Symulator()
{

}

void Symulator::Fstart()
{   
    pacjent_0=1;
    for(int i=0;i<ziemia.liczba_krajow;i++)
    {
        k[i].Fzeruj();
    }
    ziemia.Fzeruj();
    obecny_kraj=200;
    k[0].Fwczytaj("polska");
    k[1].Fwczytaj("niemcy");
    Foblicz();
}

void Symulator::Ffirstclick()
{
    pacjent_0=0;
    k[obecny_kraj].dzien_zarazy++;
    ziemia.dzien_zarazy++;
    k[obecny_kraj].tablica.dziennie_zarazonych[k[obecny_kraj].dzien_zarazy]=1;
    Foblicz();
}
void Symulator::Fnext_day()
{
    for (int i=0;i<ziemia.liczba_krajow;i++)
    {
        kraje[i].Fnext_day();
    }
    ziemia.Fnext_day();
    Foblicz();
}

void Symulator::Foblicz()
{
    for(int i=0;i<ziemia.liczba_krajow;i++)
    {
        k[i].Foblicz(wirus);
    }
    for(int i=0;i<ziemia.liczba_krajow;i++)
    {
       ziemia.Foblicz(k[i]);
    }
}
void Symulator::Fwsp_zar()
{
    for(int i=0;i<ziemia.liczba_krajow;i++)
    {
        k[i].Fwsp_zar(wirus);
    }
}



