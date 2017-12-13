//
// Created by Krystian Duma on 13/12/2017.
//

#include "funkcje_wspolne.h"

void zamien_wartosci_zmiennych(int &wartosc_a, int &wartosc_b) {
	int tymczasowa = wartosc_a;
	wartosc_a = wartosc_b;
	wartosc_b = tymczasowa;
}

std::string pad_right(const std::string &str, size_t s) {
	if ( str.size() < s )
		return str + std::string(s-str.size(), ' ');
	else
		return str;
}
