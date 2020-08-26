
Czytacz {

Kraj[] Czytacz::wczytaj(string n)
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
    Kraj [] kraje = []
    while(getline(plik,linia))
    {
        nazwa
        medycyna
        saad
        asd
        saad
        asd
        if(aktualny_nr==nr_linii) nazwa=linia;
        if(aktualny_nr==nr_linii+1) tablica.populacja[1]=atoi(linia.c_str()); //atoi(linia.c_str()) przekształca string na int
        if(aktualny_nr==nr_linii+2) powierzchnia=atoi(linia.c_str());
        if(aktualny_nr==nr_linii+3) temperatura=atoi(linia.c_str());
        if(aktualny_nr==nr_linii+4) urbanizacja=atof(linia.c_str());
        if(aktualny_nr==nr_linii+5) wilgotnosc=atof(linia.c_str());
        if(aktualny_nr==nr_linii+6) medycyna=atof(linia.c_str());

        aktualny_nr++;
        kraje[i] = new Kraj(nazwa, medycyna, sasd, ,asdasd ,asdd)
    }

    plik.close();
    return kraje

}
}