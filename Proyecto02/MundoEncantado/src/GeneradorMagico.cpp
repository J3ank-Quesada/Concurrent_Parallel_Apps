/**
* @copyright 2021 ECCI, Universidad de Costa Rica. All rights reserved
* @author Hellen Fuentes Artavia <hellen.fuentesartavia@ucr.ac.cr>
* @author Jean Carlo Quesada Abarca <jean.quesadaabarca@ucr.ac.cr>
* @author Andrés Zamora Víquez <andres.zamoraviquez@ucr.ac.cr>
*/
#include "GeneradorMagico.hpp"

GeneradorMagico::GeneradorMagico() {
  this->lector = Lector();
}

void GeneradorMagico::obtenerIslas(std::string nombreArchivo, std::string ruta,
std::vector<Trabajo>* escribir) {
  lector.lectorTrabajo(nombreArchivo, escribir, ruta);
}

MapaMagico* GeneradorMagico::obtenerMapa(std::string nombreMapa,
  int midnights, std::string ruta) {
  MapaMagico *mapaMagico = new MapaMagico;
  mapaMagico->miNombre = nombreMapa;
  lector.lectorMapa(nombreMapa, mapaMagico, ruta);
  mapaMagico->numeroIteraciones = midnights;
  return mapaMagico;
}
