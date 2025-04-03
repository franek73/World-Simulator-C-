#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Mlecz.h"
#include "Roslina.h"
#include "Kolory.h"

Mlecz::Mlecz() : Roslina()
{
}

Mlecz::Mlecz(int x, int y, Swiat* swiat) : Roslina(0, 0, x, y, 0, swiat, 'M', "Mlecz")
{

}


Mlecz::Mlecz(int x, int y, Swiat* swiat, int sila, int wiek) : Roslina(sila, 0, x, y, wiek, swiat, 'M', "Mlecz")
{

}

Mlecz::~Mlecz()
{
}

void Mlecz::Akcja()
{
    for (int i = 0; i < 3; i++)
    {
    srand(time(NULL));
    int czy_zasieje = rand() % 4;
    if (czy_zasieje == 0)
    {
        swiat->Dodaj_Organizm(this, this);
        break;
    }
    }
	
}

void Mlecz::Kolizja(Organizm* atakowany)
{
	Roslina::Kolizja(atakowany);
}

void Mlecz::Rysowanie() const
{
    cout << ZOLTY << znak << NEUTRALNY;
}