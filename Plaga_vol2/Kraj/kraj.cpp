#include <iostream>
#include <fstream>
#include <cstdlib>
#include "kraj.h"
#include "Patogen/patogen.h"
#include <cmath>



using namespace std;

Kraj::Kraj(string n, int p, int pow,int temp,int o,float u,float w,float m)
{

    nazwa=n;
    tablica.populacja[0]=p;
    powierzchnia=pow;
    temperatura=temp;
    ofiar=o;
    urbanizacja=u;
    wilgotnosc=w;
    medycyna=m;
    czas_choroby=0;

}
Kraj::~Kraj()
{
}

void Kraj::Fwczytaj(string n)
{

    fstream plik;
    plik.open(n+".txt",ios::in);

    if(plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku";
        exit(0);
    }
    int nr_linii=1;
    int aktualny_nr=1;
    string linia;
    while(getline(plik,linia))
    {
        if(aktualny_nr==nr_linii) nazwa=linia;
        if(aktualny_nr==nr_linii+1) tablica.populacja[1]=atoi(linia.c_str()); //atoi(linia.c_str()) przekształca string na int
        if(aktualny_nr==nr_linii+2) powierzchnia=atoi(linia.c_str());
        if(aktualny_nr==nr_linii+3) temperatura=atoi(linia.c_str());
        if(aktualny_nr==nr_linii+4) urbanizacja=atof(linia.c_str());
        if(aktualny_nr==nr_linii+5) wilgotnosc=atof(linia.c_str());
        if(aktualny_nr==nr_linii+6) medycyna=atof(linia.c_str());

        aktualny_nr++;
    }

    plik.close();
}

void Kraj::Fpopulacja() //Funkcja do poprawienia po dodaniu ofiar
{
    tablica.populacja[dzien_zarazy]=tablica.populacja[1];
}

void Kraj::Fzarazonych()
{
    if(2<=dzien_zarazy)
    {
        tablica.dziennie_zarazonych[dzien_zarazy]=ceil(tablica.chorych[dzien_zarazy-1]*wsp_zar);

        if(tablica.populacja[dzien_zarazy]<=tablica.chorych[dzien_zarazy])
        {
            tablica.dziennie_zarazonych[dzien_zarazy]=ceil(tablica.populacja[dzien_zarazy]-tablica.chorych[dzien_zarazy]);
        }
    }

}
void Kraj::Fuzdrowionych()
{
    if(0<=dzien_zarazy-czas_zarazania)
    {
        tablica.dziennie_uzdrowionych[dzien_zarazy]=tablica.dziennie_zarazonych[dzien_zarazy-czas_zarazania];
    }

}

void Kraj::Fzdrowych()
{
    tablica.zdrowych[dzien_zarazy]=tablica.populacja[dzien_zarazy]-tablica.chorych[dzien_zarazy];
}
void Kraj::Fchorych()
{

    for(int i=0;i<=dzien_zarazy;i++)
    {
        tablica.chorych[dzien_zarazy]+=(tablica.dziennie_zarazonych[i]-tablica.dziennie_uzdrowionych[i]);

        if(tablica.chorych[dzien_zarazy]>=tablica.populacja[dzien_zarazy])
        {
            tablica.chorych[dzien_zarazy]=tablica.populacja[dzien_zarazy];
            tablica.dziennie_zarazonych[dzien_zarazy]=0;
        }
        if(tablica.chorych[dzien_zarazy]<=0)
        {
            tablica.chorych[dzien_zarazy]=0;
        }
    }


}

void Kraj::Fzeruj()
{
    dzien_zarazy=0;
    for (int i=0;i<1000;i++)
    {

        tablica.chorych[i]=0;
        tablica.populacja[i]=0;
        tablica.zdrowych[i]=0;
        tablica.dziennie_zarazonych[i]=0;
        tablica.dziennie_uzdrowionych[i]=0;
    }
}

void Kraj::Fnext_day()
{
    if(dzien_zarazy>0)
    {
        dzien_zarazy++;
    }
}

void Kraj::Fwsp_zar(Patogen p)
{
    zarazliwosc=0;

    if(p.ptaki_1==1) zarazliwosc+=5;
    if(p.ptaki_2==1) zarazliwosc+=7;
    if(p.gryzonie_1==1) zarazliwosc+=5*(1+urbanizacja);
    if(p.gryzonie_2==1) zarazliwosc+=10*(1+urbanizacja);
    if(p.zw_gospodarcze_1==1) zarazliwosc+=5*(1+(1-urbanizacja));
    if(p.zw_gospodarcze_2==1) zarazliwosc+=10*(1+(1-urbanizacja));
    if(p.woda_1==1) zarazliwosc+=5;
    if(p.woda_2==1) zarazliwosc+=5;
    if(p.powietrze_1==1) zarazliwosc+=5;
    if(p.powietrze_2==1) zarazliwosc+=5;
    if(p.krew_1==1) zarazliwosc+=5;
    if(p.krew_2==1) zarazliwosc+=5;
    if(p.owady_1==1) zarazliwosc+=5;
    if(p.owady_2==1) zarazliwosc+=5;

    wsp_zar=zarazliwosc/100;
}

void Kraj::Fczas_zar(Patogen p)
{
    czas_zarazania=p.czas_inkubacji+czas_choroby;
}

void Kraj::Foblicz(Patogen p)
{
    Fwsp_zar(p);
    Fczas_zar(p);
    Fpopulacja();
    Fzarazonych();
    Fuzdrowionych();
    Fchorych();
    Fzdrowych();

}
void Kraj::Fofiar()
{

}



