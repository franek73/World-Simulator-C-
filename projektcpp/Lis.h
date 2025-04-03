#pragma once
#include <iostream>
#include "Swiat.h"
#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis();

    Lis(int x, int y, Swiat* swiat);

    Lis(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Lis();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
