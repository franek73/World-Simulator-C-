#pragma once
#include <iostream>
#include "Swiat.h"
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa();

    Antylopa(int x, int y, Swiat* swiat);

    Antylopa(int x, int y, Swiat* swiat, int sila, int wiek);

    ~Antylopa();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
