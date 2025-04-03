#include"Organizm.h"
#include"Swiat.h"
#include<iostream>

using namespace std;

Organizm::Organizm()
{
    sila = 0;
    inicjatywa = 0;
    x = 0;
    y = 0;
    wiek = 0;
    swiat = nullptr;
    znak = ' ';
    nazwa = " ";
}

Organizm::Organizm(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat, char znak, string nazwa)
{
    this->sila = sila;
    this->inicjatywa = inicjatywa;
    this->x = x;
    this->y = y;
    this->wiek = wiek;
    this->swiat = swiat;
    this->znak = znak;
    this->nazwa = nazwa;
}

char Organizm::Get_Znak() const {
    return znak;
}
int Organizm::Get_X() const {
    return x;
}
int Organizm::Get_Y() const {
    return y;
}

void Organizm::Zwieksz_Wiek()
{
    wiek++;
}

int Organizm::Get_Sila() const {
    return sila;
}

string Organizm::Get_Nazwa() const
{
    return nazwa;
}
int Organizm::Get_Wiek() const
{
    return wiek;
}

int Organizm::Get_Inicjatywa() const
{
    return inicjatywa;
}

