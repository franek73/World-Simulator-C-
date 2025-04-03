#include <iostream>
#include "Zwierze.h"
#include "Organizm.h"
#include "Swiat.h"
#include <cstdlib>
#include <string>

using namespace std;

#define GORA 0
#define DOL 1
#define PRAWO 2
#define LEWO 3

    Zwierze::Zwierze() : Organizm()
    {
        ostatni_x = x;
        ostatni_y = y;
    }

    Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat, char znak, string nazwa) : Organizm(sila, inicjatywa, x, y, wiek, swiat, znak, nazwa)
    {
        ostatni_x = x;
        ostatni_y = y;
    }

    Zwierze::~Zwierze() {}
    
    void Zwierze::Akcja() {
       
        srand(time(NULL));
        bool czy_byl_ruch = false;
        int przemieszczenie = 1;

        if (znak == 'A')
        {
            przemieszczenie = 2;
        }

        while (czy_byl_ruch == false)
        {
            int ruch = rand() % 4;
            if (ruch == GORA)
            {
                if (y >= przemieszczenie)
                {

                    ostatni_x = this->x;
                    ostatni_y = this->y;
                this->y = y - przemieszczenie;
                czy_byl_ruch = true;
            }

            }
            else if (ruch == DOL)
            {
                if (y < swiat->Get_Wysokosc()- przemieszczenie)
                {

                    ostatni_x = this->x;
                    ostatni_y = this->y;
                    this->y = y + przemieszczenie;
                    czy_byl_ruch = true;
                }

            }
            else if (ruch == PRAWO)
            {
                if (x < swiat->Get_Szerokosc()- przemieszczenie)
                {

                    ostatni_x = this->x;
                    ostatni_y = this->y;
                    this->x = x + przemieszczenie;
                    czy_byl_ruch = true;
                }

            }
            else if (ruch == LEWO)
            {
                if (x >= przemieszczenie)
                {
                    ostatni_x = this->x;
                    ostatni_y = this->y;
                    this->x = x - przemieszczenie;
                    czy_byl_ruch = true;
                }

            }
         }
      // string komunikat = nazwa + " przechodzi z " + to_string(x) + ',' + to_string(y) + " do " + to_string(ostatni_x) + ',' + to_string(ostatni_y);
      //  swiat->Dodaj_Komunikat(komunikat);
    }

    void Zwierze::Kolizja(Organizm* drugi_zwierz)
    {
        if (znak == drugi_zwierz->Get_Znak())
        {
            if (Get_Wiek() > 0 && drugi_zwierz->Get_Wiek() > 0)
            {
               swiat->Dodaj_Organizm(this, drugi_zwierz);
               this->Wroc_Do_Ostatniej_Pozycji();
             }
            else this->Wroc_Do_Ostatniej_Pozycji();
        }
        else if (znak != drugi_zwierz->Get_Znak())
                {
                  if (Czy_Trujace(drugi_zwierz)) {}
                  else if (Czy_Odparl_Atak(drugi_zwierz)) {}
                  else if (Czy_Uciekl(drugi_zwierz)) {}
                  else if (sila > drugi_zwierz->Get_Sila() || sila == drugi_zwierz->Get_Sila())
                         {
                           Zwieksz_Sile(drugi_zwierz);
                           string komunikat = Get_Nazwa() + " zjada " + drugi_zwierz->Get_Nazwa();
                           swiat->Dodaj_Komunikat(komunikat);
                           swiat->Usun_Organizm(drugi_zwierz);
                           swiat->Ustaw_Puste_Pole(Get_Ostatni_Y(), Get_Ostatni_X());
                           swiat->Ustaw_Na_Planszy(this);
                         }
                  else if (sila < drugi_zwierz->Get_Sila())
                         {
                          string komunikat = drugi_zwierz->Get_Nazwa() + " zjada " + Get_Nazwa();
                          swiat->Dodaj_Komunikat(komunikat);
                          swiat->Ustaw_Puste_Pole(Get_Ostatni_Y(), Get_Ostatni_X());
                          swiat->Usun_Organizm(this);
                         }
                }    
    }

    int Zwierze::Get_Ostatni_X() const {
        return ostatni_x;
    }
    int Zwierze::Get_Ostatni_Y() const {
        return ostatni_y;
    }

    void Zwierze::Wroc_Do_Ostatniej_Pozycji()
    {
       // string komunikat = Get_Nazwa() + " wraca z " + to_string(x) + "," + to_string(y) + " do " + to_string(ostatni_x) + "," + to_string(ostatni_y);
       // swiat->Dodaj_Komunikat(komunikat);
        x = ostatni_x;
        y = ostatni_y;
    }

    bool Zwierze::Czy_Odparl_Atak(Organizm* drugi_zwierz)
    {
        if (drugi_zwierz->Get_Znak() == 'Z' && sila < 5)
        {
            string komunikat= "Zolw odparl atak";
            swiat->Dodaj_Komunikat(komunikat);
            this->Wroc_Do_Ostatniej_Pozycji();
            return true;
        }
        else return false;
    }

    bool Zwierze::Czy_Uciekl(Organizm* drugi_zwierz)
    {
        srand(time(NULL));
        int czy_ucieknie = rand() % 2;
        bool czy_uciekla = false;
  
        if (drugi_zwierz->Get_Znak() == 'A' && czy_ucieknie == 1)
        {
            if (swiat->Sprawdz_Czy_Pole_Puste(drugi_zwierz->Get_Y(), drugi_zwierz->Get_X() - 1))
            {
                drugi_zwierz->Set_X(drugi_zwierz->Get_X() - 1);
                czy_uciekla = true;
            }
            else if (swiat->Sprawdz_Czy_Pole_Puste(drugi_zwierz->Get_Y(), drugi_zwierz->Get_X() + 1))
            {
                drugi_zwierz->Set_X(drugi_zwierz->Get_X() + 1);
                czy_uciekla = true;
            }
            else if (swiat->Sprawdz_Czy_Pole_Puste(drugi_zwierz->Get_Y() - 1, drugi_zwierz->Get_X()))
            {
                drugi_zwierz->Set_Y(drugi_zwierz->Get_Y() - 1);
                czy_uciekla = true;
            }
            else if (swiat->Sprawdz_Czy_Pole_Puste(drugi_zwierz->Get_Y() + 1, drugi_zwierz->Get_X()))
            {
                drugi_zwierz->Set_Y(drugi_zwierz->Get_Y() + 1);
                czy_uciekla = true;
            }
        }
        if (czy_uciekla)
        {
            swiat->Ustaw_Na_Planszy(drugi_zwierz);
            string komunikat= "Antylopa uciekla";
            swiat->Dodaj_Komunikat(komunikat);
            swiat->Ustaw_Puste_Pole(Get_Ostatni_Y(), Get_Ostatni_X());
            swiat->Ustaw_Na_Planszy(this);
            return true;
        }
        else return false;
    }

    void Zwierze::Set_X(int x)
    {
        this->x = x;
    }

    void Zwierze::Set_Y(int y)
    {
        this->y = y;
    }

    void Zwierze::Zwieksz_Sile(Organizm* drugi_zwierz)
    {
        if (drugi_zwierz->Get_Znak() == 'G')
        {
            this->sila = sila + 3;
            string komunikat = Get_Nazwa() + " zwieksza sile o 3";
            swiat->Dodaj_Komunikat(komunikat);
        }
    }

    bool Zwierze::Czy_Trujace(Organizm* drugi_zwierz)
    {
        
        if (drugi_zwierz->Get_Znak() == 'J' || drugi_zwierz->Get_Znak() == 'B')
        {
            string komunikat = drugi_zwierz->Get_Nazwa() + " zabija " + Get_Nazwa();
            swiat->Dodaj_Komunikat(komunikat);
            swiat->Ustaw_Puste_Pole(Get_Ostatni_Y(), Get_Ostatni_X());
            swiat->Ustaw_Puste_Pole(Get_Y(), Get_X());
            swiat->Usun_Organizm(drugi_zwierz);
            swiat->Usun_Organizm(this);
            return true;
        }

        else return false;
        
        return false;
    }
