//
// Created by Krystian Duma on 13/12/2017.
//

#include <iostream>
#include "funkcje_we_wy.h"

void wypisz_wyniki(const w_int &test) {
	std::cout << "Wypisanie zawartości tablicy:\n";

	for (int i = 0; i < test.size(); ++i) {
		std::cout << "\tint[" << i << "] = " << test[i] << "\n";
	}
}