#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "BarszczSosnowskiego.h"
#include "Roslina.h"
#include "Kolory.h"

using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego() : Roslina()
{
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(99, 0, x, y, 0, swiat, 'B', "BarszczSosnowskiego")
{

}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat, int sila, int wiek) : Roslina(sila, 0, x, y, wiek, swiat, 'B', "BarszczSosnowskiego")
{

}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}

void BarszczSosnowskiego::Akcja()
{
	
	Organizm* zwierze = swiat->Zwroc_Pole(Get_Y() - 1, Get_X());
	if (zwierze != nullptr)
	{
		if (zwierze->Get_Znak() != 'B' && zwierze->Get_Znak() != 'J' && zwierze->Get_Sila() > 0)
		{
			swiat->Ustaw_Puste_Pole(zwierze->Get_Y(), zwierze->Get_X());
			string komunikat = "Barszcz sosnowskiego zabija " + zwierze->Get_Nazwa();
			swiat->Dodaj_Komunikat(komunikat);
			swiat->Usun_Organizm(zwierze);
		}
	}
	zwierze = swiat->Zwroc_Pole(Get_Y() + 1, Get_X());
	if (zwierze != nullptr)
	{
		if (zwierze->Get_Znak() != 'B' && zwierze->Get_Znak() != 'J' && zwierze->Get_Sila() > 0)
		{
			swiat->Ustaw_Puste_Pole(zwierze->Get_Y(), zwierze->Get_X());
			string komunikat = "Barszcz sosnowskiego zabija " + zwierze->Get_Nazwa();
			swiat->Dodaj_Komunikat(komunikat);
			swiat->Usun_Organizm(zwierze);
		}
	}
	zwierze = swiat->Zwroc_Pole(Get_Y(), Get_X() - 1);
	if (zwierze != nullptr)
	{
		if (zwierze->Get_Znak() != 'B' && zwierze->Get_Znak() != 'J' && zwierze->Get_Sila() > 0)
		{
			swiat->Ustaw_Puste_Pole(zwierze->Get_Y(), zwierze->Get_X());
			string komunikat = "Barszcz sosnowskiego zabija " + zwierze->Get_Nazwa();
			swiat->Dodaj_Komunikat(komunikat);
			swiat->Usun_Organizm(zwierze);
		}
	}
	zwierze = swiat->Zwroc_Pole(Get_Y(), Get_X() + 1);
	if (zwierze != nullptr)
	{
		if (zwierze->Get_Znak() != 'B' && zwierze->Get_Znak() != 'J' && zwierze->Get_Sila() > 0)
		{
			swiat->Ustaw_Puste_Pole(zwierze->Get_Y(), zwierze->Get_X());
			string komunikat = "Barszcz sosnowskiego zabija " + zwierze->Get_Nazwa();
			swiat->Dodaj_Komunikat(komunikat);
			swiat->Usun_Organizm(zwierze);
		}
	}
	
}

void BarszczSosnowskiego::Kolizja(Organizm* atakowany)
{
	Roslina::Kolizja(atakowany);
}

void BarszczSosnowskiego::Rysowanie() const
{

	cout << ZIELONY << znak << NEUTRALNY;
}