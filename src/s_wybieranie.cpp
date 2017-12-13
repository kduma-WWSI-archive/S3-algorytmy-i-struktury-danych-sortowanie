//
// Created by Krystian Duma on 12/12/2017.
//

#include "s_wybieranie.h"
#include <algorithm>

void wybieranie(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
  int a;
  wyjscie=wejscie;
  for (int i=0;i<liczba_elementow;i++){
  a=i;
    for(int j=(i+1);j<liczba_elementow;j++){
    
      if(wyjscie[j]<wyjscie[a]){
      a=j;
        std::swap(wyjscie[a],wyjscie[i]);
      }
    
    }
  
}
  
  

}
