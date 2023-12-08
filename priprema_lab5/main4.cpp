#include "array.h"
#include <iostream>

int main() {
  Array<int> moj_niz;

  // Drugi dio - implementirati jednostavni push_back
  for (int i = 1; i < 5000; i++) {
   moj_niz.push_back(i);
  }

  std::cout << "Size: " << moj_niz.size() << std::endl;
}
