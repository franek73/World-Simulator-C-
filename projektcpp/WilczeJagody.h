#pragma once
#include <iostream>
#include "Swiat.h"
#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
    WilczeJagody();

    WilczeJagody(int x, int y, Swiat* swiat);

    WilczeJagody(int x, int y, Swiat* swiat, int sila, int wiek);

    ~WilczeJagody();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
