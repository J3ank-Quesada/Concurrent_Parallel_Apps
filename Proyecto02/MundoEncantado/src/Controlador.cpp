/**
* @copyright 2021 ECCI, Universidad de Costa Rica. All rights reserved
* @author Hellen Fuentes Artavia <hellen.fuentesartavia@ucr.ac.cr>
* @author Jean Carlo Quesada Abarca <jean.quesadaabarca@ucr.ac.cr>
* @author Andrés Zamora Víquez <andres.zamoraviquez@ucr.ac.cr>
*/
#include <sys/stat.h>
#include "Controlador.hpp"
#include "GeneradorMagico.hpp"
#include "EspejoMagico.hpp"
#define DIRECTORIO_SALIDA "../Salidas"

Controlador::Controlador() { }

Controlador::~Controlador() { }

void Controlador::iniciar(std::string nombreArchivo, std::string ruta) {
  GeneradorMagico generador;
  generador.obtenerIslas(nombreArchivo, ruta, &this->trabajos);
  crearDirectorio();
  for (size_t iterador = 0 ; iterador < trabajos.size(); iterador++) {
    MapaMagico *islaActual = generador.obtenerMapa(
      trabajos[iterador].getNombreMapa(),
      trabajos[iterador].getNumMidnights(), ruta);
      EspejoMagico clarividente(islaActual);
      clarividente.verDestino();
      liberarMemoria(islaActual);
  }
}

void Controlador::liberarMemoria(MapaMagico *eliminar) {
  delete eliminar;
}

void Controlador::crearDirectorio() {
    mkdir(DIRECTORIO_SALIDA, 0777);
}
