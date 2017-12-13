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
	w_int dane_wejsciowe{5584, 7464, 4394, 9611, 702, 8627, 9961, 259, 1533, 1171, 2056, 8370, 8191, 407, 1825};
	w_int oczekiwane_dane_wyjsciowe{259, 407, 702, 1171, 1533, 1825, 2056, 4394, 5584, 7464, 8191, 8370, 8627, 9611, 9961};

	testuj_wstawianie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_wybieranie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_babelkowe(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_scalanie(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_szybkie_l(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
	testuj_szybkie_s(dane_wejsciowe, oczekiwane_dane_wyjsciowe);
}

void testuj_babelkowe(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	babelkowe(dane_wejsciowe, dane_wyjsciowe, static_cast<int>(dane_wejsciowe.size()));

	porownaj_wyniki("Sortowanie Bąbelkowe", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_scalanie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	const auto liczba_elementow = static_cast<int>(dane_wejsciowe.size());
	sps(dane_wejsciowe, dane_wyjsciowe, liczba_elementow);

	porownaj_wyniki("Sortowanie przez Scalanie", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_szybkie_l(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	const auto liczba_elementow = static_cast<int>(dane_wejsciowe.size());
	szybkie_l(dane_wejsciowe, dane_wyjsciowe, liczba_elementow);

	porownaj_wyniki("Sortowanie Szybkie (x = a[l])", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
}

void testuj_szybkie_s(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe) {
	w_int dane_wyjsciowe;

	const auto liczba_elementow = static_cast<int>(dane_wejsciowe.size());
	szybkie_s(dane_wejsciowe, dane_wyjsciowe, liczba_elementow);

	porownaj_wyniki("Sortowanie Szybkie (x = a[(l+p) div 2])", oczekiwane_dane_wyjsciowe, dane_wyjsciowe);
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
	bool wynik = naglowek_porownania(algorytm, oczekiwane_dane_wyjsciowe, dane_wyjsciowe);

	if(!wynik){
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

bool naglowek_porownania(const std::string &algorytm, const w_int &oczekiwane_dane_wyjsciowe, const w_int &dane_wyjsciowe) {
	auto wynik = czy_wyniki_sa_takie_same(oczekiwane_dane_wyjsciowe, dane_wyjsciowe);

	if(wynik){
		std::cout << "\t\033[1;42;30mOK!\033[0m   - " << algorytm << "\n";
	}else {
		std::cout << "\t\033[1;41;37mBŁĄD!\033[0m - " << algorytm << "\n";
	}
	return wynik;
}

bool czy_wyniki_sa_takie_same(const w_int &oczekiwane_dane_wyjsciowe, const w_int &dane_wyjsciowe) {
	if (dane_wyjsciowe.size() != oczekiwane_dane_wyjsciowe.size())
		return false;

	for (int i = 0; i < oczekiwane_dane_wyjsciowe.size(); ++i)
		if (dane_wyjsciowe[i] != oczekiwane_dane_wyjsciowe[i])
			return false;

	return true;
}