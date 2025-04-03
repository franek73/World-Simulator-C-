#pragma once
#include <iostream>
#include "Swiat.h"
#include "Roslina.h"

class Guarana : public Roslina {
public:
    Guarana();

    Guarana(int x, int y, Swiat* swiat);

    Guarana(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Guarana();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
