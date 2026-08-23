#pragma once
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

template<class T>
class Fabrika
{
	T* niz;
	int top;
	int max;

	void oslobodiMem();
	void zauzmiMem(int _max);

public:
	Fabrika();
	Fabrika(int _max);
	~Fabrika();

	void Dodaj(T t);
	void Izbaci(T t);
	float Ukupno();
	int UkupniBrojVrednost(T zapreminaAmbalaze, float* zapreminaUAmbalazi);
	int NajmanjeAmbalaza(double);
	void Sacuvaj(const char* filename);
	void Ucitaj(const char* filename);
	friend ostream& operator<<(ostream& izlaz, const Fabrika& f) {
		izlaz << f.max << " " << f.top << endl;
		for (int i = 0; i < f.top; i++) {
			izlaz << f.niz[i]<< endl;//operator<<
		}
		return izlaz;
	}
};

template<class T>
inline void Fabrika<T>::oslobodiMem()
{
	delete[] niz;
	niz = nullptr;
	max = top = 0;

}

template<class T>
inline void Fabrika<T>::zauzmiMem(int _max)
{
	max = _max;
	top = 0;
	niz = new T[max];
}

template<class T>
inline Fabrika<T>::Fabrika()
{
	max = top = 0;
	niz = nullptr;
}

template<class T>
inline Fabrika<T>::Fabrika(int _max)
{
	zauzmiMem(_max);
}

template<class T>
inline Fabrika<T>::~Fabrika()
{
	delete[] niz;
}

template<class T>
inline void Fabrika<T>::Dodaj(T t)
{
	if (top == max) {
		throw new exception("kolekcija je puna!");
	}
	int i = 0;
	while (i<top && t>niz[i]) { //operator>
		++i;
	}
	if (i < top) {
		for (int j = top; j > i; --j) {
			niz[j] = niz[j - 1];
		}
		niz[i] = t;
		++top;
	}
	else {
		niz[top++] = t;
	}
}

template<class T>
inline void Fabrika<T>::Izbaci(T t)
{
	for (int i = 0; i < top; ++i) {
		if (niz[i] == t) {//operator ==
			for (int j = i; j < top - 1; ++j) {
				niz[j] = niz[j + 1];
			}
			--top;
			return;
		}
	}
	throw new exception("Ne postoji u kolekciji");
}

template<class T>
inline float Fabrika<T>::Ukupno()
{
	float ukupno = 0.0f;
	for (int i = 0; i < top; i++) {
		ukupno = niz[i]+ukupno;  //operator+=
	}
	return ukupno;
}

template<class T>
inline int Fabrika<T>::UkupniBrojVrednost(T zapreminaAmbalaze, float* zapreminaUAmbalazi)
{
	int brojAmbalaza = 0;
	for (int i = 0; i < top; i++) {
		if (zapreminaAmbalaze == niz[i])//operator==
		{
			++brojAmbalaza;
			*zapreminaUAmbalazi = niz[i] + *zapreminaUAmbalazi;//operator+
		}
	}
	return brojAmbalaza;
}

template<class T>
inline int Fabrika<T>::NajmanjeAmbalaza(double zadataKolicina)
{
	float sumaZap = 0;
	for (int i = top-1; i >=0; i--) {
		sumaZap = niz[i] + sumaZap;
		if (sumaZap >= zadataKolicina) {
			return top-i;
		}
	}
	return 0;
}

template<class T>
inline void Fabrika<T>::Sacuvaj(const char* filename)
{
	ofstream izlaz(filename);
	if (!izlaz.good())
		throw new exception("Fajl nije uspesno ucitan");

	izlaz << *this;
	izlaz.close();
}

template<class T>
inline void Fabrika<T>::Ucitaj(const char* filename)
{
	ifstream ulaz(filename);

	if (!ulaz.good())
		throw new exception("Fajl nije uspesno ucitan");

	oslobodiMem();
	ulaz >> max;
	zauzmiMem(max);

	ulaz >> top;
	for (int i = 0; i < top; i++) {
		ulaz >> niz[i];//operator>>
	}
	ulaz.close();
}
