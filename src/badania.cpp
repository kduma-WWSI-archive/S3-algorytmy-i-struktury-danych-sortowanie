//
// Created by Krystian Duma on 13/12/2017.
//

#include "badania.h"
#include "s_wybieranie.h"
#include "s_wstawianie.h"
#include "s_szybkie.h"
#include "s_scalanie.h"
#include "s_babelkowe.h"
#include "generator_danych_testowych.h"
#include "../libs/StopWatch.h"

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
	badanie.szybkie_lewy = czasy_dla_algorytmu(szybkie_l, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.szybkie_srodek = czasy_dla_algorytmu(szybkie_s, liczba_elementow, losowe, uporzadkowane, odwrotne);

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