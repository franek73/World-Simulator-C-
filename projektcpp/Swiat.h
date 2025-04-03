#pragma once
#include "Organizm.h"
#include "Czlowiek.h"


class Swiat {
private:
    Organizm** organizmy;
    Organizm*** plansza;
    Czlowiek* czlowiek;
    string* komunikaty;
    int liczba_komunikatow;
    int szerokosc;
    int wysokosc;
    int liczba_organizmow;
public:
    Swiat(int szerokosc, int wysokosc);
    
    ~Swiat();
    
    void Wykonaj_Ture(int ruch);
   
    void Rysuj_Swiat();
    
    void Dodaj_Organizm(Organizm* org_1, Organizm* org_2);
    
    void Usun_Organizm(Organizm* org);
    
    int Get_Szerokosc();
    
    int Get_Wysokosc();

    bool Sprawdz_Czy_Pole_Puste(int x, int y);
    
    void Ustaw_Na_Planszy(Organizm* org);
    
    void Ustaw_Puste_Pole(int y, int x);

    Organizm* Zwroc_Pole(int y, int x);

    void Sprawdz_Status_Umiejetnosci();

    void Wykorzystaj_Umiejetnosc();

    void Sortuj_Organizmy();

    void Zapisz_Do_Pliku();

    void Wczytaj_Z_Pliku();

    void Dodaj_Komunikat(string nowy_komunikat);

    void Generuj_Organizm(Organizm* nowy_organizm, int los, int x, int y);

};

