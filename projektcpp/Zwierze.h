#pragma once
#include <iostream>
#include "Organizm.h"
using namespace std;


class Zwierze : public Organizm {
protected:
    int ostatni_x;
    int ostatni_y;
public:
    Zwierze();

    Zwierze(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat, char znak, string nazwa);

    ~Zwierze();

    virtual void Akcja();

    virtual void Kolizja(Organizm* drugi_zwierz);
    
    virtual void Rysowanie() const=0;

    virtual int Get_Ostatni_X() const;

    virtual int Get_Ostatni_Y() const;

    virtual void Wroc_Do_Ostatniej_Pozycji();

    virtual bool Czy_Odparl_Atak(Organizm* drugi_zwierz);

    virtual bool Czy_Uciekl(Organizm* drugi_zwierz);
    
    virtual void Set_X(int x);
    
    virtual void Set_Y(int y);

    virtual void Zwieksz_Sile(Organizm* drugi_zwierz);

    virtual bool Czy_Trujace(Organizm* drugi_zwierz);


};
