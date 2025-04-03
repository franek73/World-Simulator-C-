#pragma once
#include <iostream>
#include "Swiat.h"
#include "Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz();

    Mlecz(int x, int y, Swiat* swiat);

    Mlecz(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Mlecz();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
