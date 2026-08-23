#include <iostream>

#include "OsnovnaKarta.h"
#include "JednodnevnaKarta.h"
#include "KompletKarata.h"
#include "Manifestacija.h"

using namespace std;

void Zadatak1()
{
    // Provera jednodnevne karte
    char o1[] = "JK00";
    char s1 = 'A';
    int v1[] = { 2000, 1 };

    JednodnevnaKarta* p1 =
        new JednodnevnaKarta(
            o1,
            s1,
            v1[0],
            v1[1]
        );

    cout << "Jednodnevna karta:" << endl;
    cout << *p1 << endl;

    // Provera komplet karte
    char o2[] = "KK00";
    char s2 = 'A';
    int cenaKompleta = 4000;
    float popustKompleta = 10.0f;

    KompletKarata* p2 =
        new KompletKarata(
            o2,
            s2,
            cenaKompleta,
            popustKompleta
        );

    cout << "Komplet karta:" << endl;
    cout << *p2 << endl;

    // Pojedinacne karte koje se dodaju u manifestaciju
    char oz[][10] =
    {
        "JK1", "KK2", "JK3", "KK4", "JK5",
        "KK6", "JK7", "KK8", "JK9", "KK10"
    };

    char sek[] =
    {
        'A', 'B', 'C', 'C', 'B',
        'A', 'C', 'B', 'B', 'A'
    };

    int cene[] =
    {
        1000, 4000, 2000, 5000, 1500,
        3000, 1500, 7000, 1000, 6000
    };

    // Redni brojevi dana za jednodnevne karte
    int rd[] =
    {
        1, 2, 3, 2, 1
    };

    // Popusti za komplet karte
    float pop[] =
    {
        10.0f, 4.0f, 8.0f, 8.0f, 10.0f
    };

    int brElem = 10;

    // Podaci o manifestaciji
    char sektoriManifestacije[] =
    {
        'A', 'B', 'C'
    };

    int brojSektora = 3;

    float procentiDana[] =
    {
        30.0f, 40.0f, 30.0f
    };

    int brojDana = 3;

    Manifestacija* pMan =
        new Manifestacija(
            brElem + 2,
            brojSektora,
            sektoriManifestacije,
            brojDana,
            procentiDana
        );

    // Dodavanje karata
    for (int i = 0; i < brElem / 2; i++)
    {
        pMan->Dodaj(
            new JednodnevnaKarta(
                oz[2 * i],
                sek[2 * i],
                cene[2 * i],
                rd[i]
            )
        );

        pMan->Dodaj(
            new KompletKarata(
                oz[2 * i + 1],
                sek[2 * i + 1],
                cene[2 * i + 1],
                pop[i]
            )
        );
    }

    cout << "Dodate karte:" << endl;
    cout << *pMan << endl;

    // Vracanje dve karte pocevsi od pozicije 7
    int ind = 7;
    int br = 2;

    pMan->VratiKarte(ind, br);

    cout << "Karte nakon vracanja:" << endl;
    cout << *pMan << endl;

    // Ukupna zarada
    cout << "Ukupna zarada: "
        << pMan->UkupnaZarada()
        << endl;

    // Sektor sa najvise prodatih karata
    char sektor =
        pMan->SektorSaNajviseKarata();

    cout << "Sektor sa najvise karata: "
        << sektor
        << endl;

    // Dan sa najvecom zaradom
    int zaradaDan = 0;

    int rbrDan =
        pMan->DanSaNajvecomZaradom(
            zaradaDan
        );

    cout << "Najveca zarada je "
        << rbrDan
        << ". dana i iznosi "
        << zaradaDan
        << endl;

    // Dve najskuplje karte
    OsnovnaKarta* pMax = nullptr;
    OsnovnaKarta* pAfterMax = nullptr;

    pMan->NajskupljeKarte(
        &pMax,
        &pAfterMax
    );

    cout << "Dve najskuplje karte su:"
        << endl;

    if (pMax != nullptr)
    {
        cout << *pMax << endl;
    }

    if (pAfterMax != nullptr)
    {
        cout << *pAfterMax << endl;
    }

    delete pMan;

    /*
        p1 i p2 nisu deo manifestacije,
        pa se moraju posebno obrisati.
    */
    delete p1;
    delete p2;
}





int main() {
    Zadatak1();
}

