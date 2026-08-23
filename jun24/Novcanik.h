#pragma once
#include <fstream>
#include <exception>
#include <iostream>
using namespace std;
template<class T>
class Novcanik
{
	T* niz;
	int top;
	int max;
	
public:
	Novcanik();
	Novcanik(int _max);
	~Novcanik();
	void Dodaj(T nov);
	void Izbaci(T nov);
	float Ukupno();
	int UkupniBrojVrednost(T& nov, float& vrednost);
	int NajmanjeNovcanica(int broj);
	void Sacuvaj(const char* filename);
	void Ucitaj(const char* filename);

	friend ostream& operator<<(ostream& izlaz, const Novcanik& n) {
		izlaz << endl;
		izlaz << n.max << endl;
		izlaz << n.top << endl;
		
		for (int i = 0; i < n.top; i++) {
			izlaz << n.niz[i] << endl;// operator <<
		}
		izlaz << endl;
		return izlaz;
	}
};


template<class T>
inline Novcanik<T>::Novcanik()
{
	top = 0;
	max = 0;
	niz = nullptr;
}

template<class T>
inline Novcanik<T>::Novcanik(int _max)
{
	max = _max;
	top = 0;
	niz = new T[max];
}

template<class T>
inline Novcanik<T>::~Novcanik()
{
	delete[] niz;
}

template<class T>
inline void Novcanik<T>::Dodaj(T nov)
{
	if (top == max)
		throw new exception("Kolekcija je puna");

	int mesto = 0;
	while (mesto < top && nov <= niz[mesto]) { //operator <=
		mesto++;
	}
	for (int j = top; j > mesto; j--) {
		niz[j] = niz[j - 1];
	}
	niz[mesto] = nov;
	top++;
	return;
}

template<class T>
inline void Novcanik<T>::Izbaci(T nov)
{
	if (top == 0)
		throw new exception("Lista je prazna");

	for (int i = 0; i < top; i++) {
		if (nov == niz[i]) {//operator==
			for (int j = i; j < top - 1; j++) {
				niz[j] = niz[j + 1];
			}
			--top;
			return;
		}
	}
	throw new exception("Novcanica nije pronadjena");
}

template<class T>
inline float Novcanik<T>::Ukupno()
{
	float suma = 0.0f;
	for (int i = 0; i < top; i++) {
		suma = niz[i]+suma;//operator+
	}
	return suma;
}

template<class T>
inline int Novcanik<T>::UkupniBrojVrednost(T& nov, float& vrednost)
{
	int broj = 0;
	for (int i = 0; i < top; i++) {
		if (niz[i] == nov) {
			++broj;
			vrednost = niz[i] + vrednost;
		}
	}
	return broj;
}

template<class T>
inline int Novcanik<T>::NajmanjeNovcanica(int broj)
{
	float trenutnaSuma = 0.0f;
	int brojNovcanica = 0;
	for (int i = 0; i < top; i++) {
		trenutnaSuma = niz[i] + trenutnaSuma;
		++brojNovcanica;
		if (trenutnaSuma >= broj) {
			return brojNovcanica;
		}
	}
	return 0;
}

template<class T>
inline void Novcanik<T>::Sacuvaj(const char* filename)
{
	std::ofstream izlaz(filename);
	if (izlaz.good()) {
		izlaz << *this;
		izlaz.close();
	}
	else
		throw new exception("Greska pri otvaranju fajla");

}

template<class T>
inline void Novcanik<T>::Ucitaj(const char* filename)
{
	std::ifstream ulaz(filename);
	if (ulaz.good()) {
		ulaz >> max;
		ulaz >> top;
		for (int i = 0; i < top; i++) {
			ulaz >> niz[i];
		}
		ulaz.close();
	}
	else
		throw new exception("Greska pri ucitavanju iz fajla");
}


