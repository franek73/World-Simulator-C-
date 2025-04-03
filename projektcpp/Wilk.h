#pragma once
#include <iostream>
#include "Swiat.h"
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk();

    Wilk(int x, int y, Swiat* swiat);

    Wilk(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Wilk();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
