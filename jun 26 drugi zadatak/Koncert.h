#pragma once
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

template <class T>
class Koncert
{
	T* niz;
	int max;
	int top;
public:
	Koncert();
	Koncert(int _max);
	~Koncert();
	void Dodaj(T t);
	void Umanjenje(int prag, int umanji);
	int UkupnaZarada();
	T NajskupljaKarta();
	void NajblizeCene(T& zadato, T& manja, T& veca);
	void Sacuvaj(const char* filename);
	void Ucitaj(const char* filename);

	friend ostream& operator<<(ostream& izlaz, const Koncert& k) {
		izlaz << k.max << endl
			<< k.top << endl;
		for (int i = 0; i < k.top; i++) {
			izlaz << k.niz[i] << endl; //operator<<
		}
		izlaz << endl;
		return izlaz;
	}

};

template<class T>
inline Koncert<T>::Koncert()
{
	max = top = 0;
	niz = nullptr;
}

template<class T>
inline Koncert<T>::Koncert(int _max)
{
	max = _max;
	top = 0;
	niz = new T[max];
}

template<class T>
inline Koncert<T>::~Koncert()
{
	delete[] niz;
}

template<class T>
inline void Koncert<T>::Dodaj(T t)
{
	if (top == max)
		throw new exception("Nema vise dostupnih karata!");

	niz[top++] = t;
}

template<class T>
inline void Koncert<T>::Umanjenje(int prag, int umanji)
{
	for (int i = 0; i < top; i++) {
		if (niz[i] > prag) {//operator>
			niz[i] = niz[i] - umanji;//operator-
		}
	}
}

template<class T>
inline int Koncert<T>::UkupnaZarada()
{
	int zarada = 0;
	for (int i = 0; i < top; i++) {
		zarada = niz[i]+zarada;//operator+
	}
	return zarada;
}

template<class T>
inline T Koncert<T>::NajskupljaKarta()
{
	if (top == 0)
		throw new exception("Nema prodatih karata!");

	T najskuplja = niz[0];
	for (int i = 1; i < top; i++) {
		if (niz[i] > najskuplja) {//operator> mislim da je to isti
			najskuplja = niz[i];//operator= treba da se overriduje ako Karta ima atribute u dinamickoj
		}
	}
	return najskuplja; // posto se vraca po vrednosti treba copy konstruktor iz istog razloga
}

template<class T>
inline void Koncert<T>::NajblizeCene(T& zadato, T& manja, T& veca)
{
	bool postojiManja = false;
	bool postojiVeca = false;

	int razlikaZamanje = 0;
	int razlikaZavece = 0;
	for (int i = 0; i < top; i++) {
		if (niz[i] < zadato) {
			int razlika = zadato - niz[i];

			if (!postojiManja || razlika < razlikaZamanje) {
				razlikaZamanje = razlika;
				manja = niz[i];
				postojiManja = true;
			}
		}
		else if (niz[i] > zadato) {
			int razlika = niz[i] - zadato;

			if (!postojiVeca || razlika < razlikaZavece) {
				razlikaZavece = razlika;
				veca = niz[i];
				postojiVeca = true;
			}
		}
		
	}
	if (!postojiManja)
		throw new exception("nema manje od zadate");
	if (!postojiVeca)
		throw new exception("nema vece od zadate");
}

template<class T>
inline void Koncert<T>::Sacuvaj(const char* filename)
{
	ofstream izlaz(filename);
	if (!izlaz.good())
		throw new exception("neuspesno otvaranje fajla!");

	izlaz << *this << endl;
	izlaz.close();
}

template<class T>
inline void Koncert<T>::Ucitaj(const char* filename)
{
	ifstream ulaz(filename);
	if (!ulaz.good())
		throw new exception("neuspesno upisivanje u fajl!");

	delete[] niz;
	ulaz >> max >> top;
	niz = new T[max];
	for (int i = 0; i < top; i++) {
		ulaz >> niz[i];
	}
	ulaz.close();
}
