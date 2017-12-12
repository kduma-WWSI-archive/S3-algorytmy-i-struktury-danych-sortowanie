#include <iostream>
#include "main.h"
#include "src/s_wybieranie.h"
#include "src/s_wstawianie.h"
#include "src/s_szybkie.h"
#include "src/s_scalanie.h"
#include "src/s_babelkowe.h"

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}


// definicje tablic i stałych globalnych :
int const N=1000001;
int uporz[N];
int los[N];
int odwr[N];
int a[N]; //tablica, na której działają algorytmy

// definicje funkcji sortujących:






//// użycie generatora liczb pseudolosowych
//
//funckja main():
//definicja i zainicjowanie generatora liczb pseudolosowych
//
//int n;  // aktualna liczba elementów ciągu
//cin>>n;
//
//przygotowanie tablic z danymi (los[], uporz[] i odwr[]):
//wygenerowanie ciągu losowych o długości n i zapisanie go w tablicy los[];
//skopiowanie los[] do a[];
//uporządkowanie tablicy a[] algorytmem sortowania;
//skopiowanie a[] do uporz[];
//skopiowanie w odwrotnym porządku uporz[] do odwr[];
//
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
