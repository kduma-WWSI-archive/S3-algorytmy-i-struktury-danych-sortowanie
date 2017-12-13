#include <iostream>
#include "main.h"
#include "src/s_wybieranie.h"
#include "src/s_wstawianie.h"
#include "src/s_szybkie.h"
#include "src/s_scalanie.h"
#include "src/s_babelkowe.h"
#include "src/generator_danych_testowych.h"
#include "src/funkcje_we_wy.h"
#include "test/testy.h"
#include "libs/StopWatch.h"


jednostka_badan badaj_algorytmy(int liczba_elementow, bool duza_zmiennosc);

czasy_wynikowe
czasy_dla_algorytmu(void (*funkcja_sortujaca)(const w_int &, w_int &, int), int liczba_elementow, const w_int &losowe, const w_int &uporzadkowane, const w_int &odwrotne);

int main() {
	std::cout << std::fixed;
	std::cout.precision(10);

	uruchom_testy();

	int n = 10000;

	auto badanie = badaj_algorytmy(n, false);
	wypisz_jednostke_badan(badanie);

	return 0;
}

jednostka_badan badaj_algorytmy(int liczba_elementow, bool duza_zmiennosc) {
	w_int losowe, uporzadkowane, odwrotne;
	const auto zakres_gorny = duza_zmiennosc ? 10 * liczba_elementow : 10;
	generuj_dane_testowe(liczba_elementow, zakres_gorny, losowe, uporzadkowane, odwrotne);

	jednostka_badan badanie{};
	badanie.liczba_elementow = liczba_elementow;
	badanie.duza_zmiennosc = duza_zmiennosc;

	badanie.wstawianie = czasy_dla_algorytmu(wstawianie, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.wybieranie = czasy_dla_algorytmu(wybieranie, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.babelkowe = czasy_dla_algorytmu(babelkowe, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.scalanie = czasy_dla_algorytmu(sps, liczba_elementow, losowe, uporzadkowane, odwrotne);

	badanie.szybkie_lewy = {};
	badanie.szybkie_srodek = {};

	return badanie;
}

czasy_wynikowe czasy_dla_algorytmu(void (*funkcja_sortujaca)(const w_int &, w_int &, int), int liczba_elementow, const w_int &losowe, const w_int &uporzadkowane,const w_int &odwrotne) {
	czasy_wynikowe czasy{};
	StopWatch timer;
	w_int wynik;

	wynik.resize(0);
	timer.start();
	funkcja_sortujaca(losowe, wynik, liczba_elementow);
	czasy.losowe = timer.stop();

	wynik.resize(0);
	timer.start();
	funkcja_sortujaca(uporzadkowane, wynik, liczba_elementow);
	czasy.uporzadkowane = timer.stop();

	wynik.resize(0);
	timer.start();
	funkcja_sortujaca(odwrotne, wynik, liczba_elementow);
	czasy.odwrotne = timer.stop();
	return czasy;
}