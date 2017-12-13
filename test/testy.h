//
// Created by Krystian Duma on 13/12/2017.
//

#ifndef SORTOWANIE_TESTY_H
#define SORTOWANIE_TESTY_H

#include "../main.h"

void uruchom_testy();

bool czy_wyniki_sa_takie_same(const w_int &oczekiwane_dane_wyjsciowe, const w_int &dane_wyjsciowe);
void porownaj_wyniki(const std::string &algorytm, const w_int &oczekiwane_dane_wyjsciowe, const w_int &dane_wyjsciowe);

void testuj_babelkowe(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);
void testuj_scalanie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);
void testuj_szybkie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);
void testuj_szybkie_l(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);
void testuj_szybkie_s(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);
void testuj_wstawianie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);
void testuj_wybieranie(const w_int &dane_wejsciowe, const w_int &oczekiwane_dane_wyjsciowe);

#endif //SORTOWANIE_TESTY_H
