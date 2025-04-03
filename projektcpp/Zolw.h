#pragma once
#include <iostream>
#include "Swiat.h"
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw();

    Zolw(int x, int y, Swiat* swiat);

    Zolw(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Zolw();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
