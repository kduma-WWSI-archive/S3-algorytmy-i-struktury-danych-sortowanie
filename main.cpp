#include <iostream>
#include <fstream>
#include <locale>
#include "main.h"
#include "src/funkcje_we_wy.h"
#include "test/testy.h"
#include "src/badania.h"
#include "libs/StopWatch.h"


int main() {
	StopWatch czas_pracy_programu;
	std::cout.imbue(std::locale("pl_PL"));

	std::cout << std::fixed;
	std::cout.precision(10);

	uruchom_testy();

	w_int dane_wejsciowe = {10, 100, 1000, 10000, 100000};

	std::vector<jednostka_badan> wyniki;

	int work = 1;
	wyniki.reserve(dane_wejsciowe.size());
	for(const auto& n : dane_wejsciowe){
		std::cout << "Trwa Liczenie " << work++ << "/" << dane_wejsciowe.size()*2 << " [n=" << n << "; mała zmienność]" << std::endl;
		wyniki.push_back(
				badaj_algorytmy(n, false)
		);
	}
	for(const auto& n : dane_wejsciowe){
		std::cout << "Trwa Liczenie " << work++ << "/" << dane_wejsciowe.size()*2 << " [n=" << n << "; duża zmienność]" << std::endl;
		wyniki.push_back(
				badaj_algorytmy(n, true)
		);
	}

	for(const auto& badanie : wyniki){
		wypisz_jednostke_badan(badanie);
	}

	std::ofstream plik_wyjsciowy("wynik.txt");
	plik_wyjsciowy << std::fixed;
	plik_wyjsciowy.precision(10);
	plik_wyjsciowy.imbue(std::locale("pl_PL"));

	for(const auto& badanie : wyniki){
		eksportuj_jednostke_badan(badanie, plik_wyjsciowy);
	}

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << "\n\n\n\n\nProgram wykonał swoje zadanie w ciągu " << czas_pracy_programu.stop() << " sekund!\n\n\n\n\n";

	return 0;
}

