//
// Created by Krystian Duma on 13/12/2017.
//

#include <iostream>
#include "testy.h"
#include "../src/s_wybieranie.h"
#include "../src/s_wstawianie.h"
#include "../src/s_szybkie.h"
#include "../src/s_scalanie.h"
#include "../src/s_babelkowe.h"
#include "../src/funkcje_we_wy.h"


void uruchom_testy() {
	w_int dane_wejsciowe{1,6,4,7,2,5,9,0,3,8};
	w_int oczekiwane_dane_wyjsciowe{0,1,2,3,4,5,6,7,8,9};

	testuj_babelkowe(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_scalanie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_szybkie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_wstawianie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_wybieranie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
}

void testuj_babelkowe(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	babelkowe(dane_wejsciowe, dane_wyjsciowe, static_cast<int>(dane_wejsciowe.size()));

	porownaj_wyniki("Sortowanie Bąbelkowe", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_scalanie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	const auto liczba_elementow = static_cast<int>(dane_wejsciowe.size());
	sps(dane_wejsciowe, dane_wyjsciowe, liczba_elementow, 0, liczba_elementow-1);

	porownaj_wyniki("Sortowanie przez Scalanie", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_szybkie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	const auto liczba_elementow = static_cast<int>(dane_wejsciowe.size());
	szybkie(dane_wejsciowe, dane_wyjsciowe, liczba_elementow, 0, liczba_elementow-1);

	porownaj_wyniki("Sortowanie Szybkie", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_wstawianie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	wstawianie(dane_wejsciowe, dane_wyjsciowe, static_cast<int>(dane_wejsciowe.size()));

	porownaj_wyniki("Sortowanie przez Wstawianie", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_wybieranie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	wybieranie(dane_wejsciowe, dane_wyjsciowe, static_cast<int>(dane_wejsciowe.size()));

	porownaj_wyniki("Sortowanie przez Wybieranie", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void porownaj_wyniki(const std::string &algorytm, const w_int &oczekiwane_dane_wyjsciowe, const w_int &dane_wyjsciowe) {
	auto wynik = czy_wyniki_sa_takie_same(oczekiwane_dane_wyjsciowe, dane_wyjsciowe);

	if(wynik){
		std::cout << "\tOK!   - " << algorytm << "\n";
	}else{
		std::cout << "\tBŁĄD! - " << algorytm << "\n";

		std::cout << "\t\tAlgorytm zwrócił:" << "\n";

		std::cout << "\t\t\t";
		wypisz_wyniki_w_lini(dane_wyjsciowe);
		std::cout << "\n";

//		std::cout << "\t\ta powinien zwrócić:" << "\n";
//
//		std::cout << "\t\t\t";
//		wypisz_wyniki_w_lini(oczekiwane_dane_wyjsciowe);
//		std::cout << "\n";
//
//		std::cout << "\n";
//
//		std::cout << "\n";
	}
}

bool czy_wyniki_sa_takie_same(const w_int &oczekiwane_dane_wyjsciowe, const w_int &dane_wyjsciowe) {
	if (dane_wyjsciowe.size() != oczekiwane_dane_wyjsciowe.size())
		return false;

	for (int i = 0; i < oczekiwane_dane_wyjsciowe.size(); ++i)
		if (dane_wyjsciowe[i] != oczekiwane_dane_wyjsciowe[i])
			return false;

	return true;
}