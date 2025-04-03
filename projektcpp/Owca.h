#pragma once
#include <iostream>
#include "Swiat.h"
#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca();

    Owca(int x, int y, Swiat* swiat);

    Owca(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Owca();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
