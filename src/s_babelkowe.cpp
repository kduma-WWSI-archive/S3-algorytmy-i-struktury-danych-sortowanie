//
// Created by Krystian Duma AND ... on 12/12/2017.
//

#include "s_babelkowe.h"
#include <algorithm>

void babelkowe(const w_int &wejscie, w_int &wyjscie, int liczba_elementow) {
  wyjscie=wejscie;
  for (int i=0;i<liczba_elementow;i++){
  
    for(int j=0;j<liczba_elementow;j++){
    
      if(wyjscie[j]>wyjscie[j+1]){
      
        std::swap(wyjscie[j],wyjscie[j+1]);
      }
    
    }
  
  }

}
