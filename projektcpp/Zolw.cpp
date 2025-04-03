#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Zolw.h"
#include <cstdlib>
#include "Kolory.h"

using namespace std;

#define GORA 0
#define DOL 1
#define PRAWO 2
#define LEWO 3

Zolw::Zolw() : Zwierze()
{
}

Zolw::Zolw(int x, int y, Swiat* swiat) : Zwierze(2, 1, x, y, 0, swiat, 'Z', "Zolw")
{

}

Zolw::Zolw(int x, int y, Swiat* swiat, int sila, int wiek) : Zwierze(sila, 1, x, y, wiek, swiat, 'Z', "Zolw")
{

}

Zolw::~Zolw()
{
}

void Zolw::Akcja()
{
    srand(time(NULL));
    int czy_ruch = rand() % 4;
    if (czy_ruch==0)
    {
        Zwierze::Akcja();
    }
 
}

void Zolw::Kolizja(Organizm* atakowany)
{
    Zwierze::Kolizja(atakowany);
}

void Zolw::Rysowanie() const
{
    cout << BRAZOWY << znak << NEUTRALNY;
}