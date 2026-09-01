#include <exception>
#include <iostream>
#include "Koncert.h"
#include "karta.h"
using namespace std;
int main()
{
	int brElemenata = 10;
	int brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka

	try{
		int cena[] = { 2000, 3000, 3500, 2500, 4000, 3000, 4500 };
		Koncert<int> koncert(brElemenata);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			koncert.Dodaj(cena[i]);
		cout << "Prodate karte: " << endl;
		cout << koncert << endl; //koncert.Ispisi(cout);
		// 1 bod
		int pragCene = 3800, umanjenje = 200;
		koncert.Umanjenje(pragCene, umanjenje);
		cout << "Umanjenje cene: " << endl;
		cout << koncert << endl; //koncert.Ispisi(cout);
		// 1 bod
		int ukupno = koncert.UkupnaZarada();
		cout << "Ukupna zarada: " << ukupno << endl;
		// 1 bod
		int najKarta = koncert.NajskupljaKarta();
		cout << "Najskuplja karta: " << endl;
		cout << najKarta << endl;
		// 1 bod
		int zadato = 2900, manje = 0, vece = 0;
		koncert.NajblizeCene(zadato, manje, vece);
		cout << "Najblize dve cene: " << endl;
		cout << manje << " " << vece << endl;
		// 1 bod
		char fajl[] = "KoncertPrvi.txt";
		koncert.Sacuvaj(fajl);
		// 1 bod
		Koncert<int> koncertUcitan;
		koncertUcitan.Ucitaj(fajl);
		cout << "Ucitan iz datoteke: " << endl;
		cout << koncertUcitan << endl; //koncertUcitan.Ispisi(cout);
	}
	catch (exception* e) {
		cout << e->what() << endl;
		delete e;
	}
	try
	{
		int oznake[] = { 123, 234, 345, 456, 567, 678, 789 };
		int cene[] = { 2000, 3000, 3500, 2500, 4000, 3000, 4500 };
		float popusti[] = { 10.0, 15.0, 4.0, 8.0, 15.0, 10.0, 20.0 };
		Koncert<Karta> koncert(brElemenata);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			koncert.Dodaj(Karta(oznake[i], cene[i], popusti[i]));
		}
		// 1 bod
		cout << "Prodate karte: " << endl;
		cout << koncert << endl; //koncert.Ispisi(cout);
		// 2 bod
		int pragCene = 3300, umanjenje = 200;
		koncert.Umanjenje(pragCene, umanjenje);
		cout << "Umanjenje cene: " << endl;
		cout << koncert << endl; //koncert.Ispisi(cout);
		// 1 boda
		int ukupno = koncert.UkupnaZarada();
		cout << "Ukupna zarada: " << ukupno << endl;
		// 2 boda
		Karta najKarta = koncert.NajskupljaKarta();
		cout << "Najskuplja karta: " << endl;
		cout << najKarta << endl;
		// 2 boda
		Karta zadato(0, 3000, 0.0f), manje, vece;
		koncert.NajblizeCene(zadato, manje, vece);
		cout << "Najblize dve cene: " << endl;
		cout << manje << endl << vece << endl;
		// 0 bod
		char fajl[] = "KoncertDrugi.txt";
		koncert.Sacuvaj(fajl);
		// 1 bod
		Koncert<Karta> koncertUcitan;
		koncertUcitan.Ucitaj(fajl);
		cout << "Ucitan iz datoteke: " << endl;
		cout << koncertUcitan << endl; //koncertUcitan.Ispisi(cout);
	}
	catch (exception* e) {
		cout << e->what() << endl;
		delete e;
	}
}