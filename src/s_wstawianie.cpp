//
// Created by Krystian Duma on 12/12/2017.
//

#include "s_wstawianie.h"

void wstawianie(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

	int pom, j;
	for(int i=1; i<liczba_elementow; i++)
	{
		//wstawienie elementu w odpowiednie miejsce
		pom = wyjscie[i]; //ten element będzie wstawiony w odpowiednie miejsce
		j = i-1;

		//przesuwanie elementów większych od pom
		while(j>=0 && wyjscie[j]>pom)
		{
			wyjscie[j+1] = wyjscie[j]; //przesuwanie elementów
			--j;
		}
		wyjscie[j+1] = pom; //wstawienie pom w odpowiednie miejsce
	}
}
