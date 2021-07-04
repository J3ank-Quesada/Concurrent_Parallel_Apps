#include "GeneradorMagico.hpp"
#include "omp.h"

GeneradorMagico::GeneradorMagico() {
  this->lector = Lector();
}

void GeneradorMagico::obtenerIslas(std::string nombreArchivo, std::string ruta,
std::vector<Trabajo>* escribir) {
  lector.lectorTrabajo(nombreArchivo, escribir,ruta);
}

MapaMagico* GeneradorMagico::obtenerMapa(std::string nombreMapa,int midnights ,std::string ruta){
  MapaMagico *mapaMagico = new MapaMagico;
  mapaMagico->miNombre = nombreMapa;
  lector.lectorMapa(nombreMapa, mapaMagico,ruta);
  mapaMagico->numeroIteraciones = midnights;
  return mapaMagico;
}