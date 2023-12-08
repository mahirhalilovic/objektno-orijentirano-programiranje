#include <iostream>
#include <vector>

int main() {

  std::vector<int> moja_lista{1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Problem - obrisati sve neparne brojeve iz niza
  // asimptotska slozenost??
  
  // for (auto it = moja_lista.begin(); it < moja_lista.end();) {
  //   if (*it % 2 == 1) {
  //     // ??
  //   }
  // }

  for (auto it = moja_lista.begin(); it < moja_lista.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
