#pragma once
#include <iostream>
#include "Swiat.h"
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego();

    BarszczSosnowskiego(int x, int y, Swiat* swiat);

    BarszczSosnowskiego(int x, int y, Swiat* swiat, int sila, int wiek);

    ~BarszczSosnowskiego();

    void Akcja();

    void Kolizja(Organizm* atakowany);

    void Rysowanie() const;
};
