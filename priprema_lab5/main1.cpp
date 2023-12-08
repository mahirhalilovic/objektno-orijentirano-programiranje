#include "array.h"
#include <iostream>

template <typename T>
void print(const Array<T>& niz) {
  for (auto i = 0; i < niz.size(); i++) {
    std::cout << niz[i] << ", ";
  }
  std::cout << std::endl;
}

int main() {
  // Prvi dio - implementirati default konstruktor
  Array<int> moj_niz;
  // Array<std::string> mn1;

  // implementirati konstruktor koji prima vrijednost kapaciteta
  Array<int> niz{200};
  
  // Greška
  // Array niz1(-1);
  // Array niz1 = -1;
  // Array niz2{-1};

  // Drugi dio - implementirati jednostavni push_back
  for (int i = 1; i < 11; i++) {
   moj_niz.push_back(i);
  }
  
  try {
    while (1) {
     moj_niz.push_back(42);
    }
  } catch(std::out_of_range& exc) {
    std::cout << "Imamo problem: " << exc.what() << std::endl;
  }


  // Treći dio - size i operator[]
  // Implementirati operator[]
  moj_niz[0] *= 100;
  moj_niz[1] *= 100;
  std::cout << "<" << moj_niz[0] << ", " << moj_niz[1] << ">" << std::endl;
  //
  // size() 
  for (auto i = 0; i < moj_niz.size(); i++) {
   std::cout << moj_niz[i] << ", ";
  }
  std::cout << std::endl;

  // Cetvrti dio - da li rješenje radi kod const Array& tipa
  print(moj_niz);
  std::cout << "Idemo dalje" << std::endl;

  // Peti dio - implementirati metod at te uhvatiti iznimku
  try {
   moj_niz.at(5);
   moj_niz.at(6);
   moj_niz.at(10);
   moj_niz.at(-1);
  } catch(const std::exception& err) {
    std::cout << err.what() << std::endl;
  }
}
