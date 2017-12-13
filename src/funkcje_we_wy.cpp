//
// Created by Krystian Duma on 13/12/2017.
//

#include <iostream>
#include "funkcje_we_wy.h"

void wypisz_wyniki(const w_int &wejscie) {
	wypisz_wyniki("int", wejscie);
}

void wypisz_wyniki(const std::string &nazwa_tablicy, const w_int &wejscie) {
	std::cout << "Wypisanie zawartości tablicy '" << nazwa_tablicy << "':\n";

	for (int i = 0; i < wejscie.size(); ++i) {
		std::cout << "\t" << nazwa_tablicy << "[" << i << "] = " << wejscie[i] << "\n";
	}
}

void wypisz_wyniki_w_lini(const w_int &wejscie) {
	for (auto element : wejscie) {
		std::cout << element << "\t";
	}
}
