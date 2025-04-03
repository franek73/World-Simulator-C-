#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Owca.h"
#include "Kolory.h"

Owca::Owca() : Zwierze()
{
}

Owca::Owca(int x, int y, Swiat* swiat) : Zwierze(4, 4, x, y, 0, swiat, 'O', "Owca")
{
	
}

Owca::Owca(int x, int y, Swiat* swiat, int sila, int wiek) : Zwierze(sila, 4, x, y, wiek, swiat, 'O', "Owca")
{

}

Owca::~Owca()
{
}

void Owca::Akcja()
{
	Zwierze::Akcja();
}

void Owca::Kolizja(Organizm* atakowany)
{
	Zwierze::Kolizja(atakowany);
}

void Owca::Rysowanie() const
{
	cout << BIALY << znak << NEUTRALNY;
}