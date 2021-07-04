#include "GeneradorMagico.hpp"
#include "omp.h"

GeneradorMagico::GeneradorMagico() {
  this->lector = Lector();
}

std::vector<MapaMagico>* GeneradorMagico::obtenerIslas(std::string nombreArchivo, std::string ruta) {
  lector.lectorTrabajo(nombreArchivo, &trabajos,ruta);
  for (size_t indice = 0; indice < trabajos.size(); indice++) {
    Trabajo trabajo = trabajos[indice];
    MapaMagico mapaMagico;
    mapaMagico.miNombre = trabajos[indice].getNombreMapa();
    lector.lectorMapa(trabajo.getNombreMapa(), &mapaMagico,ruta);
    mapaMagico.numeroIteraciones = trabajo.getNumMidnights();
    mapasMagicos.push_back(mapaMagico);
  }
  return &mapasMagicos;
}