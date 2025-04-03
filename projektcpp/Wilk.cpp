#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Kolory.h"

Wilk::Wilk() : Zwierze()
{
}

Wilk::Wilk(int x, int y, Swiat* swiat) : Zwierze(9, 5, x, y, 0, swiat, 'W', "Wilk")
{

}

Wilk::Wilk(int x, int y, Swiat* swiat, int sila, int wiek) : Zwierze(sila, 5, x, y, wiek, swiat, 'W', "Wilk")
{

}

Wilk::~Wilk()
{
}

void Wilk::Akcja()
{
	Zwierze::Akcja();
}

void Wilk::Kolizja(Organizm* atakowany)
{
	Zwierze::Kolizja(atakowany);
}

void Wilk::Rysowanie() const
{
	cout << SZARY << znak << NEUTRALNY;
}