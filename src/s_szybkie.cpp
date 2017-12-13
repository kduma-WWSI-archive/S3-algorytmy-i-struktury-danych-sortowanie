//
// Created by Krystian Duma on 12/12/2017.
//

#include "s_szybkie.h"
#include "funkcje_wspolne.h"

void QuickSort(w_int &tablica, int poczatek, int koniec);
void QuickSort(w_int &tablica, int poczatek, int koniec, int ogranicznik);

void QuickSort(w_int &tablica, int poczatek, int koniec, int ogranicznik) {
	int i = poczatek;
	int j = koniec;
	do
	{
		while( tablica[ i ] < ogranicznik )
			i++;

		while( tablica[ j ] > ogranicznik )
			j--;

		if( i <= j )
		{
			zamien_wartosci_zmiennych( tablica[ i ], tablica[ j ] );

			i++;
			j--;
		}
	} while( i <= j );

	if( poczatek < j )
		QuickSort(tablica, poczatek, j);

	if( koniec > i )
		QuickSort(tablica, i, koniec);

}

void QuickSort(w_int &tablica, int poczatek, int koniec) {
	int ogranicznik = tablica[( poczatek + koniec ) / 2 ];
	QuickSort(tablica, poczatek, koniec, ogranicznik);
}

void szybkie(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	QuickSort(wyjscie, 0, liczba_elementow-1);
}

void szybkie_l(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	int ogranicznik = wyjscie[0];
	QuickSort(wyjscie, 0, liczba_elementow-1, ogranicznik);
}

void szybkie_s(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	int ogranicznik = wyjscie[ (liczba_elementow-1)/2 ];
	QuickSort(wyjscie, 0, liczba_elementow-1, ogranicznik);
}
