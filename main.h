//
// Created by Krystian Duma on 12/12/2017.
//

#ifndef SORTOWANIE_MAIN_H
#define SORTOWANIE_MAIN_H

#include <vector>

typedef std::vector<int> w_int;

struct czasy_wynikowe {
	double losowe;
	double uporzadkowane;
	double odwrotne;
};

struct jednostka_badan {
	bool duza_zmiennosc;
	int liczba_elementow;
	czasy_wynikowe wstawianie;
	czasy_wynikowe wybieranie;
	czasy_wynikowe babelkowe;
	czasy_wynikowe scalanie;
	czasy_wynikowe szybkie_lewy;
	czasy_wynikowe szybkie_srodek;
};

#endif //SORTOWANIE_MAIN_H
