//
// Created by Krystian Duma on 12/12/2017.
//

#ifndef SORTOWANIE_GENERATOR_DANYCH_TESTOWYCH_H
#define SORTOWANIE_GENERATOR_DANYCH_TESTOWYCH_H

	#include "../main.h"

	void generuj_dane_testowe(int liczba_elementow, w_int &losowe, w_int &uporzadkowane, w_int &odwrotne);

	w_int generuj_losowe_dane_testowe(int liczba_elementow);

	w_int uporzadkuj_dane_testowe(const w_int &wejscie);

	w_int odwroc_uporzadkowane_dane_testowe(const w_int &wejscie);

#endif //SORTOWANIE_GENERATOR_DANYCH_TESTOWYCH_H
