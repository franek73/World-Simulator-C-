#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "WilczeJagody.h"
#include "Roslina.h"
#include "Kolory.h"

WilczeJagody::WilczeJagody() : Roslina()
{
}

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat) : Roslina(99, 0, x, y, 0, swiat, 'J', "WilczeJagody")
{

}


WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat, int sila, int wiek) : Roslina(sila, 0, x, y, wiek, swiat, 'J', "WilczeJagody")
{

}

WilczeJagody::~WilczeJagody()
{
}

void WilczeJagody::Akcja()
{
	Roslina::Akcja();
}

void WilczeJagody::Kolizja(Organizm* atakowany)
{
	Roslina::Kolizja(atakowany);
}

void WilczeJagody::Rysowanie() const
{
	cout << FIOLETOWY << znak << NEUTRALNY;
}