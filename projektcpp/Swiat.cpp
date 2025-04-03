#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Mlecz.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Czlowiek.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "WilczeJagody.h"
#include<iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) 
{
	srand(time(NULL));

	this->komunikaty = new string[0];
	this->liczba_komunikatow = 0;

	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	
	this->plansza = new Organizm** [wysokosc];
	this->organizmy = new Organizm* [szerokosc*wysokosc];
	
	for (int i = 0; i < wysokosc; i++)
	{
		plansza[i] = new Organizm* [szerokosc];
		for (int y = 0; y < szerokosc; y++)
		{
			plansza[i][y] = nullptr;
		}
	}

	this->liczba_organizmow = szerokosc * wysokosc / 4;

	int x = rand() % szerokosc;
	int y = rand() % wysokosc;
	Czlowiek* czlek= new Czlowiek(x, y, this);
	this->czlowiek = czlek;
		organizmy[0] = czlek;
	    plansza[y][x] = czlek;

    int i = 1;
	for (; i < liczba_organizmow; )
	{
		bool czy_znaleziono_miejsce = false;
		/*
		Organizm* nowy_organizm = nullptr;
		int los = rand() % 10;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Generuj_Organizm(nowy_organizm, los, x, y);
				organizmy[i] = nowy_organizm;
				plansza[y][x] = nowy_organizm;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}
		*/
		
		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc-1 + 1);
			int y = rand() % (wysokosc-1 + 1);
			if (plansza[y][x]==nullptr)
			{
			
			Organizm* owca = new Owca(x, y, this);
			organizmy[i] = owca;
			plansza[y][x] = owca;
			czy_znaleziono_miejsce = true;
			i++;
		    }
	     }

		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* wilk = new Wilk(x, y, this);
				organizmy[i] = wilk;
				plansza[y][x] = wilk;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}

		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* lis = new Lis(x, y, this);
				organizmy[i] = lis;
				plansza[y][x] = lis;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}
		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* zolw = new Zolw(x, y, this);
				organizmy[i] = zolw;
				plansza[y][x] = zolw;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}
		
		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* antylopa = new Antylopa(x, y, this);
				organizmy[i] = antylopa;
				plansza[y][x] = antylopa;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}

		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* trawa = new Trawa(x, y, this);
				organizmy[i] = trawa;
				plansza[y][x] = trawa;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}

		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* mlecz = new Mlecz(x, y, this);
				organizmy[i] = mlecz;
				plansza[y][x] = mlecz;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}

		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* guarana = new Guarana(x, y, this);
				organizmy[i] = guarana;
				plansza[y][x] = guarana;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}
		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* wilczejagody = new WilczeJagody(x, y, this);
				organizmy[i] = wilczejagody;
				plansza[y][x] = wilczejagody;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}

		czy_znaleziono_miejsce = false;

		while (czy_znaleziono_miejsce == false)
		{
			int x = rand() % (szerokosc - 1 + 1);
			int y = rand() % (wysokosc - 1 + 1);
			if (plansza[y][x] == nullptr)
			{

				Organizm* barszczsosnowskiego = new BarszczSosnowskiego(x, y, this);
				organizmy[i] = barszczsosnowskiego;
				plansza[y][x] = barszczsosnowskiego;
				czy_znaleziono_miejsce = true;
				i++;
			}
		}
		
	}

	this->liczba_organizmow = i;

}

void Swiat::Generuj_Organizm(Organizm* nowy_organizm, int los, int x, int y)
{
	if (los == 1)
	{
		nowy_organizm = new Owca(x, y, this);
	}
	if (los == 2)
	{
		nowy_organizm = new Wilk(x, y, this);
	}
	if (los == 3)
	{
		nowy_organizm = new Lis(x, y, this);
	}
	if (los == 4)
	{
		nowy_organizm = new Zolw(x, y, this);
	}
	if (los == 5)
	{
		nowy_organizm = new Antylopa(x, y, this);
	}
	if (los == 6)
	{
		nowy_organizm = new Trawa(x, y, this);
	}
	if (los == 7)
	{
		nowy_organizm = new Guarana(x, y, this);
	}
	if (los == 8)
	{
		nowy_organizm = new WilczeJagody(x, y, this);
	}
	if (los == 9)
	{
		nowy_organizm = new BarszczSosnowskiego(x, y, this);
	}
	if (los == 0)
	{
		nowy_organizm = new Mlecz(x, y, this);
	}
}


void Swiat::Wykonaj_Ture(int ruch) {

	for (int i = 0; i < liczba_organizmow; i++)
	{
		Organizm* org = organizmy[i];
		org->Zwieksz_Wiek();
	}

	Sortuj_Organizmy();
	czlowiek->Set_Ruch(ruch);

	for (int i = 0; i < liczba_organizmow; i++)
	{

		Organizm* org = organizmy[i];
		
		if (org != nullptr)
		{
			int old_x = org->Get_X();
			int old_y = org->Get_Y();
			if (org->Get_Wiek() > 0) {
				org->Akcja();
				if (old_x != org->Get_X() || old_y != org->Get_Y())
				{

					if (plansza[org->Get_Y()][org->Get_X()] != nullptr)
					{
						org->Kolizja(plansza[org->Get_Y()][org->Get_X()]);

					}
					else
					{
						plansza[org->Get_Y()][org->Get_X()] = org;
						plansza[old_y][old_x] = nullptr;
					}
				}
			}
	    }
	}
	for (int i = 0; i < liczba_organizmow; i++)
	{
		if (organizmy[i] == nullptr)
		{
	
		   for (int j = i; j < liczba_organizmow - 1; j++)
		   {
			organizmy[j] = organizmy[j + 1];
		   }
		   liczba_organizmow--;
		i--;
		
	    }
	}

}

void Swiat::Rysuj_Swiat() {

	for (int i = 0; i < wysokosc; i++)
	{

		for (int y = 0; y < szerokosc; y++)
		{
			Organizm* org = plansza[i][y];
			if (org == nullptr)
			{
				cout << ".";
			}
			else
				org->Rysowanie();
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < liczba_komunikatow; i++)
	{
		cout << komunikaty[i] << endl;
	}


	this->liczba_komunikatow = 0;
	delete[] komunikaty;
	this->komunikaty = new string[0];

	cout << endl;

	Sprawdz_Status_Umiejetnosci();
	cout << "Zapis gry - s, Wczytanie gry - w"<<endl;
	cout << "Poruszanie sie - strzalki, Umiejetnosc specjalna - x"<<endl;
}
void Swiat::Dodaj_Organizm(Organizm* org_1, Organizm* org_2) {
	bool czy_znaleziono_miejsce = false;
	int x, y;

	if (Sprawdz_Czy_Pole_Puste(org_1->Get_Y() - 1, org_1->Get_X()))
	{
		czy_znaleziono_miejsce = true;
		x = org_1->Get_X();
		y = org_1->Get_Y()-1;
	}
	else if (Sprawdz_Czy_Pole_Puste(org_1->Get_Y() + 1, org_1->Get_X()))
	{
		czy_znaleziono_miejsce = true;
		x = org_1->Get_X();
		y = org_1->Get_Y()+1;
	}
	else if (Sprawdz_Czy_Pole_Puste(org_1->Get_Y(), org_1->Get_X() - 1)) {
		czy_znaleziono_miejsce = true;
		x = org_1->Get_X()-1;
		y = org_1->Get_Y();
	}
	else if (Sprawdz_Czy_Pole_Puste(org_1->Get_Y(), org_1->Get_X() + 1)) {
		czy_znaleziono_miejsce = true;
		x = org_1->Get_X()+1;
		y = org_1->Get_Y();
	}
	else if (Sprawdz_Czy_Pole_Puste(org_2->Get_Y() - 1, org_2->Get_X())) {
		czy_znaleziono_miejsce = true;
		x = org_2->Get_X();
		y = org_2->Get_Y()-1;
	}
	else if (Sprawdz_Czy_Pole_Puste(org_2->Get_Y() + 1, org_2->Get_X())) {
		czy_znaleziono_miejsce = true;
		x = org_2->Get_X();
		y = org_2->Get_Y()+1;
	}
	else if (Sprawdz_Czy_Pole_Puste(org_2->Get_Y(), org_2->Get_X() - 1)) {
		czy_znaleziono_miejsce = true;
		x = org_2->Get_X()-1;
		y = org_2->Get_Y();
	}
	else if (Sprawdz_Czy_Pole_Puste(org_2->Get_Y(), org_2->Get_X() + 1)) {
		czy_znaleziono_miejsce = true;
		x = org_2->Get_X()+1;
		y = org_2->Get_Y();
	}

	bool czy_zwierze = true;

	if (czy_znaleziono_miejsce)
	{
		Organizm* nowy_organizm=nullptr;
	if (org_1->Get_Znak() == 'O')
	{
		nowy_organizm = new Owca(x, y, this);
	}
	if (org_1->Get_Znak() == 'W')
	{
		nowy_organizm = new Wilk(x, y, this);
	}
	if (org_1->Get_Znak() == 'L')
	{
		nowy_organizm = new Lis(x, y, this);
	}
	if (org_1->Get_Znak() == 'Z')
	{
		nowy_organizm = new Zolw(x, y, this);
	}
	if (org_1->Get_Znak() == 'A')
	{
		nowy_organizm = new Antylopa(x, y, this);
	}
	if (org_1->Get_Znak() == 'T')
	{
		nowy_organizm = new Trawa(x, y, this);
		czy_zwierze = false;
	}
	if (org_1->Get_Znak() == 'G')
	{
		nowy_organizm = new Guarana(x, y, this);
		czy_zwierze = false;
	}
	if (org_1->Get_Znak() == 'J')
	{
		nowy_organizm = new WilczeJagody(x, y, this);
		czy_zwierze = false;
	}
	if (org_1->Get_Znak() == 'B')
	{
		nowy_organizm = new BarszczSosnowskiego(x, y, this);
		czy_zwierze = false;
	}
	if (org_1->Get_Znak() == 'M')
	{
		nowy_organizm = new Mlecz(x, y, this);
		czy_zwierze = false;
	}
	organizmy[liczba_organizmow] = nowy_organizm;
	plansza[y][x] = nowy_organizm;
	
	if (czy_zwierze)
	{
		string komunikat = "Dwa orgaznizmy gatunku: " + org_1->Get_Nazwa() + " rozmnazaja sie";
		Dodaj_Komunikat(komunikat);
	}
	else {
		string komunikat = org_1->Get_Nazwa() + " rozsiewa sie";
		Dodaj_Komunikat(komunikat);
	}
	liczba_organizmow++;
}
}
void Swiat::Usun_Organizm(Organizm* org) {

	
	for (int i = 0; i < liczba_organizmow; i++)
	{
		if (organizmy[i] == org)
		{
		
				organizmy[i] = nullptr;
			
		}
	}
	delete org;
}
int Swiat::Get_Szerokosc() {
	return szerokosc;
}

int Swiat::Get_Wysokosc() {
	return wysokosc;
}

bool Swiat::Sprawdz_Czy_Pole_Puste(int y, int x)
{
	if (x >= 0 && x < szerokosc && y>=0 && y < wysokosc)
	{
	if (plansza[y][x] == nullptr)
		return true;
	else return false;
    }
	else return false;

}
void Swiat::Ustaw_Na_Planszy(Organizm* org)
{
	plansza[org->Get_Y()][org->Get_X()] = org;

}

void Swiat::Ustaw_Puste_Pole(int y, int x)
{
	plansza[y][x] = nullptr;
	
}

Organizm* Swiat::Zwroc_Pole(int y, int x)
{
	if (x > 0 && x < szerokosc && y>0 && y < wysokosc)
	{
		return plansza[y][x];
	}
	else return nullptr;
}

void Swiat::Sprawdz_Status_Umiejetnosci()
{
	int status = czlowiek->Get_Licznik_Umiejetnosci();
	if (status == -5)
	{
		cout << "Jesli chcesz uzyc umiejetnosc specjalna wcisnij x" << endl;
	}
	else if (status >0)
	{
		cout << "Umiejetnosc specjalna w uzyciu" << endl;
	}
	else if (status <= 0 && status > -5)
	{
		cout << "Nie mozna w tym momencie uzyc umiejetnosci specjalnej" << endl;
	}
}

void Swiat::Wykorzystaj_Umiejetnosc()
{
	czlowiek->Set_Umiejetnosc_Specjalna();
}

void Swiat::Sortuj_Organizmy()
{
	for (int i = 0; i < liczba_organizmow; i++) {
		for (int j = 0; j < liczba_organizmow - i - 1; j++) {
			if (organizmy[j]->Get_Inicjatywa() < organizmy[j + 1]->Get_Inicjatywa() || (organizmy[j]->Get_Inicjatywa() == organizmy[j + 1]->Get_Inicjatywa() && organizmy[j]->Get_Wiek() < organizmy[j + 1]->Get_Wiek()))
			{
				swap(organizmy[j], organizmy[j + 1]);
			}
		}
	}
}

void Swiat::Zapisz_Do_Pliku()
{
	ofstream plik("zapis.txt");

	if (plik.is_open()) {
		plik<<szerokosc<< endl;
		plik << wysokosc << endl;
		plik << liczba_organizmow << endl;

		for (int i = 0; i < liczba_organizmow; i++)
		{
			Organizm* org = organizmy[i];
			if (org->Get_Znak() == 'X')
			{
				plik << org->Get_Znak() << " " << org->Get_X() << " " << org->Get_Y() << " " << org->Get_Sila() << " " << org->Get_Wiek() << " " << org->Get_Nazwa() << " " << czlowiek->Get_Licznik_Umiejetnosci() << endl;
			}
			else {
			plik << org->Get_Znak() << " " << org->Get_X() << " " << org->Get_Y() << " " << org->Get_Sila() << " " << org->Get_Wiek() << " " << org->Get_Nazwa() << endl;
		     }
		}
		plik.close();
	}
     else {
     cout << "Nie udalo sie zapisac"<<endl;
	}
	
}


void Swiat::Wczytaj_Z_Pliku()
{
	ifstream plik("zapis.txt");
	if (plik.is_open()) {

		plik >> szerokosc;
		plik >> wysokosc;
		plik >> liczba_organizmow;

		this->plansza = new Organizm * *[wysokosc];
		this->organizmy = new Organizm * [szerokosc * wysokosc];

		for (int i = 0; i < wysokosc; i++)
		{
			plansza[i] = new Organizm * [szerokosc];
			for (int y = 0; y < szerokosc; y++)
			{
				plansza[i][y] = nullptr;
			}
		}


		for (int i = 0; i < liczba_organizmow; i++)
		{
			char znak;
			int licznik_umiejetnosci;
			int x, y, sila, wiek;
			string nazwa;
			plik >> znak >> x >> y >> sila >> wiek >> nazwa;
			if (znak == 'X')
			{
				plik >> licznik_umiejetnosci;
				Czlowiek* czlek = new Czlowiek(x, y, this, sila, wiek, licznik_umiejetnosci);
				czlowiek = czlek;
				organizmy[i] = czlek;
				plansza[y][x] = czlek;
			}
			else {
				Organizm* nowy_organizm = nullptr;
				if (znak == 'O')
				{
					nowy_organizm = new Owca(x, y, this, sila, wiek);
				}
				if (znak == 'W')
				{
					nowy_organizm = new Wilk(x, y, this, sila, wiek);
				}
				if (znak == 'L')
				{
					nowy_organizm = new Lis(x, y, this, sila, wiek);
				}
				if (znak == 'Z')
				{
					nowy_organizm = new Zolw(x, y, this, sila, wiek);
				}
				if (znak == 'A')
				{
					nowy_organizm = new Antylopa(x, y, this, sila, wiek);
				}
				if (znak == 'T')
				{
					nowy_organizm = new Trawa(x, y, this, sila, wiek);
				}
				if (znak == 'G')
				{
					nowy_organizm = new Guarana(x, y, this, sila, wiek);
				}
				if (znak == 'J')
				{
					nowy_organizm = new WilczeJagody(x, y, this, sila, wiek);
				}
				if (znak == 'B')
				{
					nowy_organizm = new BarszczSosnowskiego(x, y, this, sila, wiek);
				}
				if (znak == 'M')
				{
					nowy_organizm = new Mlecz(x, y, this, sila, wiek);
				}
				organizmy[i] = nowy_organizm;
				plansza[y][x] = nowy_organizm;
			}
		}
		plik.close();
	}
	else {
		cout << "Nie udalo sie wczytac" << endl;
	}
}



Swiat::~Swiat()
{
	delete czlowiek;
	czlowiek = nullptr;

	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			if (plansza[i][j] != nullptr)
			{
				delete plansza[i][j];
				plansza[i][j] = nullptr;
			}
		}
		delete[] plansza[i];
	}
	delete[] plansza;
	plansza = nullptr;

	for (int i = 0; i < liczba_organizmow; i++)
	{
		delete organizmy[i];
		organizmy[i] = nullptr;
	}
	delete[] organizmy;
	organizmy = nullptr;
}

void Swiat::Dodaj_Komunikat(string nowy_komunikat) {

	string* nowa_tablica = new string[liczba_komunikatow + 1];

	for (int i = 0; i < liczba_komunikatow; i++) {
		nowa_tablica[i] = komunikaty[i];
	}

	nowa_tablica[liczba_komunikatow] = nowy_komunikat;

	liczba_komunikatow++;

	delete[] komunikaty;

	komunikaty = nowa_tablica;
}
