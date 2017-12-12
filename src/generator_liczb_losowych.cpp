//
// Created by Krystian Duma on 12/12/2017.
//

#include <random>
#include "generator_liczb_losowych.h"

void generuj_dane_losowe(int *wyjscie, int liczba_elementow) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> rand(1, 10000);


	for (int i = 0; i < liczba_elementow; i++){
		wyjscie[i] = rand(gen);
	}
}
