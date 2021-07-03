#include "GeneradorMagico.hpp"
#include <iostream>

int main() {
  GeneradorMagico generador;
  
  std::vector<MapaMagico>* mapas = generador.obtenerIslas("job001.txt");
  for(size_t i=0; i<mapas->size(); i++) {
    mapas->at(i).procesarMapaActual();
    std::cout<<mapas->at(i);
  }
}

