//
// Created by Krystian Duma on 13/12/2017.
//

#ifndef SORTOWANIE_BADANIA_H
#define SORTOWANIE_BADANIA_H

	#include "../main.h"

	jednostka_badan badaj_algorytmy(int liczba_elementow, bool duza_zmiennosc);
	czasy_wynikowe
	czasy_dla_algorytmu(const std::string &algorytm, void (*funkcja_sortujaca)(const w_int &, w_int &, int),
							int liczba_elementow, const w_int &losowe, const w_int &uporzadkowane,
							const w_int &odwrotne, const w_int &do_porownania);

#endif //SORTOWANIE_BADANIA_H
