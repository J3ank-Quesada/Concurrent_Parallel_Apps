#include "GeneradorMagico.hpp"

GeneradorMagico::GeneradorMagico() {
  this->lector = Lector();
}

std::vector<MapaMagico>* GeneradorMagico::obtenerIslas(std::string nombreArchivo) {
  lector.lectorTrabajo(nombreArchivo, &trabajos);
  for (size_t indice = 0; indice < trabajos.size(); indice++) {
    Trabajo trabajo = trabajos[indice];
    MapaMagico mapaMagico = MapaMagico();
    lector.lectorMapa(trabajo.getNombreMapa(), &mapaMagico);
    mapaMagico.numeroIteraciones = trabajo.getNumMidnights();
    mapasMagicos.push_back(mapaMagico);
  }
  return &mapasMagicos;
}