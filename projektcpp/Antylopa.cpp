#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Antylopa.h"
#include <cstdlib>
#include "Kolory.h"

using namespace std;

#define GORA 0
#define DOL 1
#define PRAWO 2
#define LEWO 3

Antylopa::Antylopa() : Zwierze()
{
}

Antylopa::Antylopa(int x, int y, Swiat* swiat) : Zwierze(4, 4, x, y, 0, swiat, 'A', "Antylopa")
{

}

Antylopa::Antylopa(int x, int y, Swiat* swiat, int sila, int wiek) : Zwierze(sila, 4, x, y, wiek, swiat, 'A', "Antylopa")
{

}


Antylopa::~Antylopa()
{
}

void Antylopa::Akcja()
{
    Zwierze::Akcja();
}

void Antylopa::Kolizja(Organizm* atakowany)
{
    Zwierze::Kolizja(atakowany);
}

void Antylopa::Rysowanie() const
{
    cout << BRAZOWY << znak << NEUTRALNY;
}