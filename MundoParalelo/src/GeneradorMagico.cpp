#include "GeneradorMagico.hpp"
#include "omp.h"

GeneradorMagico::GeneradorMagico() {
  this->lector = Lector();
}

std::vector<MapaMagico>* GeneradorMagico::obtenerIslas(std::string nombreArchivo, std::string ruta) {
  lector.lectorTrabajo(nombreArchivo, &trabajos,ruta);
  #pragma omp parallel for num_threads(8) default(none) shared(trabajos,ruta) schedule(dynamic)
  for (size_t indice = 0; indice < trabajos.size(); indice++) {
    Trabajo trabajo = trabajos[indice];
    MapaMagico mapaMagico;
    mapaMagico.miNombre = trabajos[indice].getNombreMapa();
    lector.lectorMapa(trabajo.getNombreMapa(), &mapaMagico,ruta);
    mapaMagico.numeroIteraciones = trabajo.getNumMidnights();
    #pragma omp critical
    mapasMagicos.push_back(mapaMagico);
  }
  return &mapasMagicos;
}