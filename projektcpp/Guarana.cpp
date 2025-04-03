#pragma once
#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Guarana.h"
#include "Roslina.h"
#include "Kolory.h"

Guarana::Guarana() : Roslina()
{
}

Guarana::Guarana(int x, int y, Swiat* swiat) : Roslina(0, 0, x, y, 0, swiat, 'G', "Guarana")
{

}


Guarana::Guarana(int x, int y, Swiat* swiat, int sila, int wiek) : Roslina(sila, 0, x, y, wiek, swiat, 'G', "Guarana")
{

}

Guarana::~Guarana()
{
}

void Guarana::Akcja()
{
    Roslina::Akcja();
}

void Guarana::Kolizja(Organizm* atakowany)
{
    Roslina::Kolizja(atakowany);
}

void Guarana::Rysowanie() const
{
    cout << CZERWONY << znak << NEUTRALNY;
}
