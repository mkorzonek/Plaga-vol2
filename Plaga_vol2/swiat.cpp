#include "swiat.h"

Swiat::Swiat()
{
    liczba_krajow=2;
    nazwa="Ziemia";
    dzien_zarazy=1;
}

Swiat::~Swiat()
{

}

void Swiat::Foblicz(Kraj k)
{
    Fpopulacja(k);
    Fzarazonych(k);
    Fuzdrowionych(k);
    Fchorych(k);
    Fzdrowych(k);
}

void Swiat::Fpopulacja(Kraj k)
{
    tablica.populacja[dzien_zarazy]+=k.tablica.populacja[k.dzien_zarazy];
}

void Swiat::Fzarazonych(Kraj k)
{
    tablica.dziennie_zarazonych[dzien_zarazy]+=k.tablica.dziennie_zarazonych[k.dzien_zarazy];
}

void Swiat::Fuzdrowionych(Kraj k)
{
    tablica.dziennie_uzdrowionych[dzien_zarazy]+=k.tablica.dziennie_uzdrowionych[k.dzien_zarazy];
}

void Swiat::Fzdrowych(Kraj k)
{
    tablica.zdrowych[dzien_zarazy]+=k.tablica.zdrowych[k.dzien_zarazy];
}

void Swiat::Fchorych(Kraj k)
{
    tablica.chorych[dzien_zarazy]+=k.tablica.chorych[k.dzien_zarazy];
}

//void Swiat::Fofiar(Kraj k)
//{
//}
