#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Trawa.h"
#include "Roslina.h"
#include "Kolory.h"

Trawa::Trawa() : Roslina()
{
}

Trawa::Trawa(int x, int y, Swiat* swiat) : Roslina(0, 0, x, y, 0, swiat, 'T', "Trawa")
{

}

Trawa::Trawa(int x, int y, Swiat* swiat, int sila, int wiek) : Roslina(sila, 0, x, y, wiek, swiat, 'T', "Trawa")
{

}

Trawa::~Trawa()
{
}

void Trawa::Akcja()
{
	Roslina::Akcja();
}

void Trawa::Kolizja(Organizm* atakowany)
{
	Roslina::Kolizja(atakowany);
}

void Trawa::Rysowanie() const
{
	cout << ZIELONY << znak << NEUTRALNY;
}