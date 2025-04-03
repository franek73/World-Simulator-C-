#pragma once
#include <iostream>
using namespace std;

class Swiat;

class Organizm {
protected:
    int sila;
    int inicjatywa;
    int x;
    int y;
    int wiek;
    char znak;
    string nazwa;
    Swiat* swiat;
public:
    Organizm();

    Organizm(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat, char znak, string nazwa);

    ~Organizm() {}

    virtual void Akcja() = 0;
    
    virtual void Kolizja(Organizm* organizm) = 0; 
    
    virtual void Rysowanie() const=0;

    char Get_Znak() const;
   
    int Get_X() const;
    
    int Get_Y() const;

    virtual void Zwieksz_Wiek();

    virtual int Get_Sila() const;

    string Get_Nazwa() const;

    virtual int Get_Wiek() const;

    virtual int Get_Inicjatywa() const;

    virtual void Set_X(int x)=0;

    virtual void Set_Y(int y)=0;

};
