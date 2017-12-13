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

void wypisz_jednostke_badan(jednostka_badan badanie) {
	std::cout << "Wyniki dla n = " << badanie.liczba_elementow << " o " << (badanie.duza_zmiennosc ? "DUŻEJ" : "MAŁEJ") << " zmienności wyników." << std::endl;
	std::cout << std::endl;

	std::cout << "\tSortowanie przez proste wstawianie" << std::endl;
	std::cout << std::endl;
	wypisz_czasy_wynikowe(badanie.wstawianie);
	std::cout << std::endl;

	std::cout << "\tSortowanie przez proste wybieranie" << std::endl;
	std::cout << std::endl;
	wypisz_czasy_wynikowe(badanie.wybieranie);
	std::cout << std::endl;

	std::cout << "\tSortowanie bąbelkowe" << std::endl;
	std::cout << std::endl;
	wypisz_czasy_wynikowe(badanie.babelkowe);
	std::cout << std::endl;

	std::cout << "\tSortowanie przez scalanie" << std::endl;
	std::cout << std::endl;
	wypisz_czasy_wynikowe(badanie.scalanie);
	std::cout << std::endl;

	std::cout << "\tSortowanie szybkie (x = a[l])" << std::endl;
	std::cout << std::endl;
	wypisz_czasy_wynikowe(badanie.szybkie_lewy);
	std::cout << std::endl;

	std::cout << "\tSortowanie szybkie (x = a[(l+p) div 2])" << std::endl;
	std::cout << std::endl;
	wypisz_czasy_wynikowe(badanie.szybkie_srodek);
	std::cout << std::endl;

}

void wypisz_czasy_wynikowe(czasy_wynikowe czasy) {
	if(czasy.uporzadkowane != -1)
		std::cout << "\t\tDane Uporządkowane:           " << czasy.uporzadkowane << std::endl;
	else
		std::cout << "\t\tDane Uporządkowane:           " << "Przepełnienie Stosu" << std::endl;

	if(czasy.uporzadkowane != -1)
		std::cout << "\t\tDane Losowe:                  " << czasy.losowe << std::endl;
	else
		std::cout << "\t\tDane Losowe:                  " << "Przepełnienie Stosu" << std::endl;

	if(czasy.uporzadkowane != -1)
		std::cout << "\t\tDane Odwrotnie Uporządkowane: " << czasy.odwrotne << std::endl;
	else
		std::cout << "\t\tDane Odwrotnie Uporządkowane: " << "Przepełnienie Stosu" << std::endl;
}
