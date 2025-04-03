#include<iostream>
#include"Swiat.h"
#include<windows.h>
#include<conio.h>
#include"Organizm.h"
#include <stdlib.h>

#define GORA 72

#define DOL 80

#define PRAWO 77

#define LEWO 75

#define ESCAPE 13

#define UMIEJETNOSC 120

#define ZAPIS 115

#define WCZYTYWANIE 119

using namespace std;

int main() {

	int znak = 0;
	char c = ' ';
	int N = 20, M = 20;
	cout << "Wpisz wymiary: ";
	cin >> N >> M;
	Swiat nowy_swiat(N, M);
	system("cls");
	nowy_swiat.Rysuj_Swiat();
	while (znak != ESCAPE)
	{
		znak = _getch();
		
			system("cls");
			if (znak == GORA)
			{
				nowy_swiat.Wykonaj_Ture(0);
			}
			else if (znak == DOL)
			{
				nowy_swiat.Wykonaj_Ture(1);
			}
			if (znak == PRAWO)
			{
				nowy_swiat.Wykonaj_Ture(2);
			}
			if (znak == LEWO)
			{
				nowy_swiat.Wykonaj_Ture(3);
			}
			if (znak == UMIEJETNOSC)
			{
				nowy_swiat.Wykorzystaj_Umiejetnosc();
			}
			if (znak == ZAPIS)
			{
				nowy_swiat.Zapisz_Do_Pliku();
			}
			if (znak == WCZYTYWANIE)
			{
				nowy_swiat.Wczytaj_Z_Pliku();
			}
		
			nowy_swiat.Rysuj_Swiat();
	
	}
	return 0;
}