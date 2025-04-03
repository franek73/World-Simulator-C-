#include <iostream>
#include "Roslina.h"
#include "Zwierze.h"
#include <cstdlib>

using namespace std;

Roslina::Roslina() : Organizm()
{

}

Roslina::Roslina(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat, char znak, string nazwa) : Organizm(sila, inicjatywa, x, y, wiek, swiat, znak, nazwa)
{

}

    Roslina::~Roslina() {}

    
    void Roslina::Akcja() {

        srand(time(NULL));
        int czy_zasieje = rand() % 4;
        if (czy_zasieje == 0)
        {
            swiat->Dodaj_Organizm(this, this);
        }
       
    }

    void Roslina::Kolizja(Organizm* atakowany) {
       
    }
    
    void Roslina::Set_X(int x)
    {
        this->x = x;
    }

    void Roslina::Set_Y(int y)
    {
        this->y = y;
    }
