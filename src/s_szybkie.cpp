//
// Created by Krystian Duma on 12/12/2017.
//

#include "s_szybkie.h"
#include "funkcje_wspolne.h"

void QuickSort_s(w_int &tablica, int poczatek, int koniec) {
	int i = poczatek;
	int j = koniec;
	int ogranicznik = tablica[( poczatek + koniec ) / 2 ];
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
		QuickSort_s(tablica, poczatek, j);

	if( koniec > i )
		QuickSort_s(tablica, i, koniec);

}

void QuickSort_l(w_int &tablica, int poczatek, int koniec) {
	int i = poczatek;
	int j = koniec;
	int ogranicznik = tablica[poczatek];
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
		QuickSort_l(tablica, poczatek, j);

	if( koniec > i )
		QuickSort_l(tablica, i, koniec);

}

void szybkie_l(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	QuickSort_l(wyjscie, 0, liczba_elementow - 1);
}

void szybkie_s(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	QuickSort_s(wyjscie, 0, liczba_elementow - 1);
}
