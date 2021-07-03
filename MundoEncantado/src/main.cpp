#include "Lector.hpp"

int main() {
  Trabajo trabajo;
  Lector lector;
  std::vector<Trabajo> trabajos;
  lector.lectorTrabajo("job001.txt", &trabajos);
  for (size_t f = 0; f < trabajos.size(); f++) {
    std::cout << trabajos[f].getNombreMapa() << " "
      << trabajos[f].getNumMidnights() << std::endl;
  }
  return 0;
}

