#include <iostream>
#include "main.h"
#include "src/s_wybieranie.h"
#include "src/s_wstawianie.h"
#include "src/s_szybkie.h"
#include "src/s_scalanie.h"
#include "src/s_babelkowe.h"
#include "src/generator_danych_testowych.h"
#include "src/funkcje_we_wy.h"
#include "test/testy.h"


int main() {
	uruchom_testy();

//	int n = 10;
//
//	w_int losowe, uporzadkowane, odwrotne, wynik;
//	generuj_dane_testowe(n, losowe, uporzadkowane, odwrotne);
//
//	wypisz_wyniki("losowe", losowe);
//	wypisz_wyniki("uporzadkowane", uporzadkowane);
//	wypisz_wyniki("odwrotne", odwrotne);

	return 0;
}



//obliczenia:
//		skopiowanie uporz[] do a[];
//sortowanie za pomocą badanego algorytmu;
//
//skopiowanie los[] do a[];
//sortowanie za pomocą badanego algorytmu;
//
//skopiowanie odwr[] do a[];
//sortowanie za pomocą badanego algorytmu;
//
//itd. dla pozostałych algorytmów sortowania
