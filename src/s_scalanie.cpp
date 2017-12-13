//
// Created by Krystian Duma on 12/12/2017.
//

#include "s_scalanie.h"

//scalenie posortowanych podtablic
void scal(w_int &tab, int lewy, int srodek, int prawy)
{
	w_int pom(tab.size());

	int i = lewy, j = srodek + 1;

	//kopiujemy lewą i prawą część tablicy do tablicy pomocniczej
	for(int i = lewy;i<=prawy; i++)
		pom[i] = tab[i];

	//scalenie dwóch podtablic pomocniczych i zapisanie ich
	//we własciwej tablicy
	for(int k=lewy;k<=prawy;k++)
		if(i<=srodek)
			if(j <= prawy)
				if(pom[j]<pom[i])
					tab[k] = pom[j++];
				else
					tab[k] = pom[i++];
			else
				tab[k] = pom[i++];
		else
			tab[k] = pom[j++];
}

void sortowanie_przez_scalanie(w_int &tab, int lewy, int prawy)
{
	//gdy mamy jeden element, to jest on już posortowany
	if(prawy<=lewy) return;

	//znajdujemy srodek podtablicy
	int srodek = (prawy+lewy)/2;

	//dzielimy tablice na częsć lewą i prawa
	sortowanie_przez_scalanie(tab, lewy, srodek);
	sortowanie_przez_scalanie(tab, srodek+1, prawy);

	//scalamy dwie już posortowane tablice
	scal(tab, lewy, srodek, prawy);
}

void sps(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	sortowanie_przez_scalanie(wyjscie, 0, liczba_elementow-1);
}
