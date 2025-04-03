#pragma once
#include <iostream>
#include "Swiat.h"
#include "Organizm.h"

class Roslina : public Organizm {
public:

    Roslina();

    Roslina(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat, char znak, string nazwa);

    ~Roslina();

    virtual void Akcja();

    virtual void Kolizja(Organizm* atakowany);

    virtual void Rysowanie() const = 0;

    virtual void Set_X(int x);

    virtual void Set_Y(int y);


};