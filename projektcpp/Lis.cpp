#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Lis.h"
#include <cstdlib>
#include <string>
#include "Kolory.h"

using namespace std;

#define GORA 0
#define DOL 1
#define PRAWO 2
#define LEWO 3

Lis::Lis() : Zwierze()
{
}

Lis::Lis(int x, int y, Swiat* swiat) : Zwierze(3, 7, x, y, 0, swiat, 'L', "Lis")
{

}

Lis::Lis(int x, int y, Swiat* swiat, int sila, int wiek) : Zwierze(sila, 7, x, y, wiek, swiat, 'L', "Lis")
{

}

Lis::~Lis()
{
}

void Lis::Akcja()
{
    
    srand(time(NULL));

    bool czy_znaleziono = false;

    bool czy_byla_gora = false;
    bool czy_byl_dol = false;
    bool czy_bylo_lewo = false;
    bool czy_bylo_prawo = false;


    while (czy_znaleziono == false)
    {
        int ruch = rand() % 4;
        if (ruch == GORA && y >= 1)
        { 
                if (swiat->Zwroc_Pole(y - 1, x) == nullptr)
                {
                    ostatni_x = this->x;
                    ostatni_y = this->y;
                    this->y = y - 1;
                    czy_znaleziono = true;

                }
                else if (swiat->Zwroc_Pole(y - 1, x)->Get_Sila() < this->sila)
                {
                    ostatni_x = this->x;
                    ostatni_y = this->y;
                    this->y = y - 1;
                    czy_znaleziono = true;

                
                } 
                czy_byla_gora = true;
         }

        if (ruch==DOL && y < swiat->Get_Wysokosc() - 1)
        {
            if (swiat->Zwroc_Pole(y + 1, x) == nullptr)
            {
                ostatni_x = this->x;
                ostatni_y = this->y;
                this->y = y + 1;
                czy_znaleziono = true;

            }
            else if (swiat->Zwroc_Pole(y + 1, x)->Get_Sila() < this->sila)
            {
                ostatni_x = this->x;
                ostatni_y = this->y;
                this->y = y + 1;
                czy_znaleziono = true;

            }
            czy_byl_dol = true;
        }

        if (ruch==PRAWO && x < swiat->Get_Szerokosc() - 1)
        {
            if (swiat->Zwroc_Pole(y, x + 1) == nullptr)
            {
                ostatni_x = this->x;
                ostatni_y = this->y;
                this->x = x + 1;
                czy_znaleziono = true;

            }

            else if (swiat->Zwroc_Pole(y, x + 1)->Get_Sila() < this->sila)
            {
                ostatni_x = this->x;
                ostatni_y = this->y;
                this->x = x + 1;
                czy_znaleziono = true;

            }
            czy_bylo_prawo = true;
        }


        if (ruch==LEWO && x >= 1)
        {
            if (swiat->Zwroc_Pole(y, x - 1) == nullptr)
            {
                ostatni_x = this->x;
                ostatni_y = this->y;
                this->x = x - 1;
                czy_znaleziono = true;

            }
            else if (swiat->Zwroc_Pole(y, x - 1)->Get_Sila() < this->sila)
            {
                ostatni_x = this->x;
                ostatni_y = this->y;
                this->x = x - 1;
                czy_znaleziono = true;

            }
            czy_bylo_lewo = true;
        }

        if (czy_byla_gora && czy_byl_dol && czy_bylo_prawo && czy_bylo_lewo)
        {
            break;
        }
    }

    //string komunikat = nazwa + " przechodzi z " + to_string(x) + ',' + to_string(y) + " do " + to_string(ostatni_x) + ',' + to_string(ostatni_y);
    //swiat->Dodaj_Komunikat(komunikat);
}   

void Lis::Kolizja(Organizm* atakowany)
{
	Zwierze::Kolizja(atakowany);
}

void Lis::Rysowanie() const
{

    cout << POMARANCZOWY << znak << NEUTRALNY;

}