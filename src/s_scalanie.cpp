//
// Created by Krystian Duma on 12/12/2017.
//

#include "s_scalanie.h"

void mergesort (w_int &a, int num)
{
	w_int b(a.size());
	int rght, wid, rend;
	int i,j,m,t;

	for (int k=1; k < num; k *= 2 ) {
		for (int left=0; left+k < num; left += k*2 ) {
			rght = left + k;
			rend = rght + k;
			if (rend > num) rend = num;
			m = left; i = left; j = rght;
			while (i < rght && j < rend) {
				if (a[i] <= a[j]) {
					b[m] = a[i]; i++;
				} else {
					b[m] = a[j]; j++;
				}
				m++;
			}
			while (i < rght) {
				b[m]=a[i];
				i++; m++;
			}
			while (j < rend) {
				b[m]=a[j];
				j++; m++;
			}
			for (m=left; m < rend; m++) {
				a[m] = b[m];
			}
		}
	}
}

void sps(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
	wyjscie = wejscie;

//	sortowanie_przez_scalanie(wyjscie, 0, liczba_elementow-1);
	mergesort(wyjscie, liczba_elementow);
}
