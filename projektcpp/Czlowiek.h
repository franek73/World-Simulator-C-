#pragma once
#include <iostream>
#include "Zwierze.h"
using namespace std;

class Czlowiek : public Zwierze {
private:
    int licznik_umiejetnosci;
    int ruch;
public:
    Czlowiek();

    Czlowiek(int x, int y, Swiat* swiat);

    Czlowiek(int x, int y, Swiat* swiat, int sila, int wiek, int licznik_umiejetnosci);

    ~Czlowiek();

    void Akcja();

    void Kolizja(Organizm* drugi_zwierz);

    void Rysowanie() const;

    void Set_Umiejetnosc_Specjalna();

    int Get_Licznik_Umiejetnosci();

    void Set_Ruch(int ruch);
};