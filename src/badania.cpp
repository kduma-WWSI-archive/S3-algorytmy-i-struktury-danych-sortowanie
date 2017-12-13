//
// Created by Krystian Duma on 13/12/2017.
//

#include <string>
#include "badania.h"
#include "s_wybieranie.h"
#include "s_wstawianie.h"
#include "s_szybkie.h"
#include "s_scalanie.h"
#include "s_babelkowe.h"
#include "generator_danych_testowych.h"
#include "../libs/StopWatch.h"
#include "../test/testy.h"
#include "funkcje_wspolne.h"

jednostka_badan badaj_algorytmy(int liczba_elementow, bool duza_zmiennosc) {
	w_int losowe, uporzadkowane, odwrotne;
	const auto zakres_gorny = duza_zmiennosc ? 10 * liczba_elementow : 10;
	generuj_dane_testowe(liczba_elementow, zakres_gorny, losowe, uporzadkowane, odwrotne);

	jednostka_badan badanie{};
	badanie.liczba_elementow = liczba_elementow;
	badanie.duza_zmiennosc = duza_zmiennosc;

	badanie.wstawianie = czasy_dla_algorytmu("wstawianie", wstawianie, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.wybieranie = czasy_dla_algorytmu("wybieranie", wybieranie, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.babelkowe = czasy_dla_algorytmu("babelkowe", babelkowe, liczba_elementow, losowe, uporzadkowane, odwrotne);
	badanie.scalanie = czasy_dla_algorytmu("scalanie", sps, liczba_elementow, losowe, uporzadkowane, odwrotne);

	if(liczba_elementow < 100000){
		badanie.szybkie_lewy = czasy_dla_algorytmu("szybkie_lewy", szybkie_l, liczba_elementow, losowe, uporzadkowane, odwrotne);
		badanie.szybkie_srodek = czasy_dla_algorytmu("szybkie_srodek", szybkie_s, liczba_elementow, losowe, uporzadkowane, odwrotne);
	} else {
		badanie.szybkie_lewy = {-1, -1, -1};
		badanie.szybkie_srodek = {-1, -1, -1};
	}

	return badanie;
}

czasy_wynikowe czasy_dla_algorytmu(const std::string &algorytm, void (*funkcja_sortujaca)(const w_int &, w_int &, int), int liczba_elementow,
								   const w_int &losowe, const w_int &uporzadkowane, const w_int &odwrotne) {
	czasy_wynikowe czasy{};
	StopWatch timer;
	w_int wynik;

	wynik.resize(0);
	timer.start();
	funkcja_sortujaca(losowe, wynik, liczba_elementow);
	czasy.losowe = timer.stop();
	naglowek_porownania(pad_right(algorytm+";", 15)+" dane losowe;        n = "+pad_right(std::to_string(liczba_elementow)+";", 10)+std::to_string(czasy.losowe)+" sekund", wynik, uporzadkowane);

	wynik.resize(0);
	timer.start();
	funkcja_sortujaca(uporzadkowane, wynik, liczba_elementow);
	czasy.uporzadkowane = timer.stop();
	naglowek_porownania(pad_right(algorytm+";", 15)+" dane uporzadkowane; n = "+pad_right(std::to_string(liczba_elementow)+";", 10)+std::to_string(czasy.uporzadkowane)+" sekund", wynik, uporzadkowane);

	wynik.resize(0);
	timer.start();
	funkcja_sortujaca(odwrotne, wynik, liczba_elementow);
	czasy.odwrotne = timer.stop();
	naglowek_porownania(pad_right(algorytm+";", 15)+" dane odwrotne;      n = "+pad_right(std::to_string(liczba_elementow)+";", 10)+std::to_string(czasy.odwrotne)+" sekund", wynik, uporzadkowane);

	return czasy;
}