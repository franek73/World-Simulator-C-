#pragma once
#include <iostream>
#include "Swiat.h"
#include "Roslina.h"

class Trawa : public Roslina {
public:
    Trawa();

    Trawa(int x, int y, Swiat* swiat);

    Trawa(int x, int y, Swiat* swiat, int sila, int wiek);  

    ~Trawa();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
