//
// Created by Krystian Duma on 12/12/2017.
//

#include <random>
#include "generator_danych_testowych.h"

w_int generuj_losowe_dane_testowe(int liczba_elementow, int zakres_gorny) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> rand(1, zakres_gorny);

	w_int wyjscie(static_cast<unsigned long>(liczba_elementow));

	for (int i = 0; i < liczba_elementow; i++){
		wyjscie[i] = rand(gen);
	}

	return wyjscie;
}

w_int uporzadkuj_dane_testowe(const w_int &wejscie) {
	w_int wyjscie = wejscie;

	std::sort (wyjscie.begin(), wyjscie.end());

	return wyjscie;
}

w_int odwroc_uporzadkowane_dane_testowe(const w_int &wejscie) {
	w_int wyjscie = wejscie;

	std::reverse (wyjscie.begin(),wyjscie.end());

	return wyjscie;
}

void
generuj_dane_testowe(int liczba_elementow, int zakres_gorny, w_int &losowe, w_int &uporzadkowane, w_int &odwrotne) {
	losowe = generuj_losowe_dane_testowe(liczba_elementow, zakres_gorny);
	uporzadkowane = uporzadkuj_dane_testowe(losowe);
	odwrotne = odwroc_uporzadkowane_dane_testowe(uporzadkowane);
}
