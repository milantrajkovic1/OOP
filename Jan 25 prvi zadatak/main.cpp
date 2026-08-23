#include"KaficSaPlazom.h"
#include <iostream>

int main() {
	// 2 poena
	int pL[] = { 12, 1, 40, 20 };
	ParLezaljki* p1 = new ParLezaljki(pL[0], pL[1], pL[2], pL[3]);
	//p1->Prikazi();
	cout << *p1 << endl;
	// 2 poena
	int pLD[] = { 21, 2, 30, 10, 1 };
	ParLezaljkiSaDodatkom* p2 = new ParLezaljkiSaDodatkom(pLD[0], pLD[1], pLD[2], pLD[3],
		pLD[4]);
	//p2->Prikazi();
	cout << *p2 << endl;
	int rbr[] = { 12, 15, 18, 23, 27, 31, 34, 37 };
	int red[] = { 1, 1, 1, 2, 2, 3, 3, 3 };
	int cena[] = { 40, 40, 40, 30, 30, 20, 20, 20 };
	int napici[] = { 20, 40, 30, 30, 70, 20, 30, 10 };
	int dodatno[] = { 1, 2 };
	KaficSaPlazom* pKSP = new KaficSaPlazom(10);
	// 2 poena
	
	for (int i = 0; i < 4; i++)
	{
		
		pKSP->Dodaj(new ParLezaljki(rbr[i], red[i], cena[i], napici[i]));
		pKSP->Dodaj(new ParLezaljkiSaDodatkom(rbr[i], red[i], cena[i], napici[i],

			dodatno[i % 2]));
	}
	// 2 poena
	//pe.print();
	cout << *pKSP << endl;
	// 2 poena
	int oznaka = 34;
	pKSP->Oslobodi(oznaka);
	//pe->print();
	cout << *pKSP << endl;
	// 2 poena
	cout << pKSP->UkupnoLezaljki() << endl;
	// 2 poena
	cout << pKSP->UkupnaSvotaNovca() << endl;
	// 2 poena
	int svota = 5000;
	if (pKSP->PostojiGdeTrebaPlatiti(svota))
		cout << "Postoje lezaljke gde treba platiti vise od " << svota << endl;
	else
		cout << "ne postoje lezaljke gde treba platiti vise od " << svota << endl;
	// 3 poena
	ParLezaljki* pLezMaxCena = nullptr, * pLezMaxNapitak = nullptr;
	pKSP->VratiNajskuplje(&pLezMaxCena, &pLezMaxNapitak);
	pLezMaxCena->Prikazi();
	pLezMaxNapitak->Prikazi();
	// 1 poena
	delete pKSP;
}