#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Czlowiek.h"
#include <string>
#include "Kolory.h"

#define GORA 0
#define DOL 1
#define PRAWO 2
#define LEWO 3


Czlowiek::Czlowiek() : Zwierze()
{
    licznik_umiejetnosci=-5;
    ruch = -1;
}

Czlowiek::Czlowiek(int x, int y, Swiat* swiat) : Zwierze(5, 4, x, y, 0, swiat, 'X', "Czlowiek")
{
    licznik_umiejetnosci = -5;
    ruch = -1;
}

Czlowiek::Czlowiek(int x, int y, Swiat* swiat, int sila, int wiek, int licznik_umiejetnosci) : Zwierze(sila, 4, x, y, wiek, swiat, 'X', "Czlowiek")
{
    this->licznik_umiejetnosci = licznik_umiejetnosci;
    ruch = -1;
}


Czlowiek::~Czlowiek()
{
}

void Czlowiek::Akcja()
{
    bool czy_byl_ruch = false;
    int przesuniecie = 1;
    if (licznik_umiejetnosci < 3 && licznik_umiejetnosci>0)
    {
        srand(time(NULL));
        int szansa = rand() % 2;
        if (szansa == 1)
        {
            przesuniecie = 2;
        }
    }
    if (licznik_umiejetnosci > 2)
    {
        przesuniecie = 2;
    }

    if (ruch == GORA && y >= przesuniecie)
    {

        ostatni_x = this->x;
        ostatni_y = this->y;
        this->y = y - przesuniecie;
        czy_byl_ruch = true;
    }
    else if (ruch == DOL && y < swiat->Get_Wysokosc() - przesuniecie)
    {

        ostatni_x = this->x;
        ostatni_y = this->y;
        this->y = y + przesuniecie;
        czy_byl_ruch = true;
    }
    else if (ruch == PRAWO && x < swiat->Get_Szerokosc() - przesuniecie)
    {

        ostatni_x = this->x;
        ostatni_y = this->y;
        this->x = x + przesuniecie;
        czy_byl_ruch = true;
    }
    if (ruch == LEWO && x >= przesuniecie)
    {

        ostatni_x = this->x;
        ostatni_y = this->y;
        this->x = x - przesuniecie;
        czy_byl_ruch = true;
    }

    if (licznik_umiejetnosci > -5)
    {
        licznik_umiejetnosci--;
    }

    if (czy_byl_ruch = true)
    {
  
    string komunikat = nazwa + " przechodzi z " + to_string(x) + ',' + to_string(y) + " do " + to_string(ostatni_x) + ',' + to_string(ostatni_y);
    swiat->Dodaj_Komunikat(komunikat);
}
}

void Czlowiek::Kolizja(Organizm* atakowany)
{
	Zwierze::Kolizja(atakowany);
}

void Czlowiek::Rysowanie() const
{

    cout << NIEBIESKI << znak << NEUTRALNY;
}

void Czlowiek::Set_Ruch(int ruch)
{
    this->ruch = ruch;
}


void Czlowiek::Set_Umiejetnosc_Specjalna()
{
    if (licznik_umiejetnosci == -5)
    {
    licznik_umiejetnosci = 5;
    }
}

int Czlowiek::Get_Licznik_Umiejetnosci()
{
    return licznik_umiejetnosci;
}