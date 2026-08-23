#pragma once
#include <iostream>
#include <exception>
using namespace std;
template <class T, int N=0>
class GenerickiNiz
{
	T* niz;
	int broj;
	
public:
	GenerickiNiz();
	GenerickiNiz(int _broj);
	GenerickiNiz(const GenerickiNiz& g);
	~GenerickiNiz();

	T Max()const;
	void Sort();
	void SnimiUFajl(const char* filename);

	GenerickiNiz<T> operator+(const GenerickiNiz& g) const;

	template<class T, int M>
	friend class GenerickiNiz;
	GenerickiNiz<T> operator+(const GenerickiNiz& g);

	friend istream& operator>>(istream& ulaz, GenerickiNiz& g) {
		for (int i = 0; i < g.broj; i++)
			ulaz >> g.niz[i]; //operator>>
		return ulaz;
	}
	friend ostream& operator<<(ostream& izlaz, const GenerickiNiz& g) {
		for (int i = 0; i < g.broj; i++)
			izlaz << g.niz[i]<<endl;//operator<<
		return izlaz;
	}
	
};

template<class T, int N>
inline GenerickiNiz<T, N>::GenerickiNiz()
{
	broj = N;
	niz = broj > 0 ? new T[broj] : nullptr;
}

template<class T, int N>
inline GenerickiNiz<T, N>::GenerickiNiz(int _broj)
{
	broj = _broj;
	niz = broj > 0 ? new T[broj] : nullptr;
}

template<class T, int N>
inline GenerickiNiz<T, N>::GenerickiNiz(const GenerickiNiz& g)
{
	broj = g.broj;
	if (broj > 0) {
		niz = new T[broj];
		for (int i = 0; i < broj; ++i) {
			niz[i] = g.niz[i];
		}
	}
	else
		niz = nullptr;
}

template<class T, int N>
inline GenerickiNiz<T, N>::~GenerickiNiz()
{
	delete[] niz;
}

template<class T, int N>
inline T GenerickiNiz<T, N>::Max() const
{
	if (broj == 0)
		throw new exception("Niz je prazan! ");

	T max = niz[0];
	for (int i = 1; i < broj; i++) {
		if (niz[i] > max) //operator>
			max = niz[i];
	}
	return max;
}

template<class T, int N>
inline void GenerickiNiz<T, N>::Sort()
{
	for (int i = 0; i < broj - 1; ++i) {
		for (int j = 1; j < broj; ++j) {
			if (niz[i] > niz[j]) {
				T pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
	return;
}

template<class T, int N>
inline void GenerickiNiz<T, N>::SnimiUFajl(const char* filename)
{
	ofstream izlaz(filename);
	if (!izlaz.good())
		throw new exception("Fajl nije uspesno otvoren! ");

	izlaz << broj << endl;
	for (int i = 0; i < broj; ++i) {
		izlaz << niz[i] << endl;
	}
	izlaz << endl;
	izlaz.close();

}

template<class T, int N>
inline GenerickiNiz<T> GenerickiNiz<T, N>::operator+(const GenerickiNiz& g) const
{
	if (broj != g.broj) {
		throw new exception("Nizovi nisu iste duzine:");
	}
	GenerickiNiz<T> pomocni(broj);
	for (int i = 0; i < broj; ++i) {
		pomocni.niz[i] = niz[i] + g.niz[i];//operator+
	}
	return pomocni;
}

template<class T, int N>
inline GenerickiNiz<T> GenerickiNiz<T, N>::operator+(const GenerickiNiz& g)
{
	GenerickiNiz<T> rezultat(broj);
	for (int i = 0; i < broj; ++i) {
		rezultat.niz[i] = niz[i] + g.niz[i];
	}

	return rezultat;
}
