/**
* @copyright 2021 ECCI, Universidad de Costa Rica. All rights reserved
* @author Hellen Fuentes Artavia <hellen.fuentesartavia@ucr.ac.cr>
* @author Jean Carlo Quesada Abarca <jean.quesadaabarca@ucr.ac.cr>
* @author Andrés Zamora Víquez <andres.zamoraviquez@ucr.ac.cr>
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Oraculo.hpp"
#define DIRECTORIO_SALIDA "../Salidas"

void Oraculo::ecribirSalida(MapaMagico *mapa) {
  std::ofstream archivo;
  std::string nombreArchivo;
  size_t posicionPunto = mapa->miNombre.find_first_of(".");
  nombreArchivo += mapa->miNombre.substr(0, posicionPunto);
  nombreArchivo+= "-";
  int numeroActual = mapa->numeroIteraciones;
  if (mapa->numeroIteraciones < 0) {
    numeroActual = mapa->numeroIteraciones*(-1);
  }
  nombreArchivo += std::to_string(numeroActual);
  nombreArchivo+= ".txt";
  std::string rutaSalida = DIRECTORIO_SALIDA;
  rutaSalida += "/";
  rutaSalida+= nombreArchivo;
  archivo.open(rutaSalida, std::ios::app);
  if (archivo.is_open()) {
    archivo << mapa->numeroActual;
    archivo << ":\n";
    for (size_t f = 0; f< mapa->mapa.size(); f++) {
      for (size_t c = 0; c< mapa->mapa[0].size(); c++) {
        archivo<< mapa->mapa[f][c];
      }
      archivo<< "\n";
    }
    archivo<< "\n";
    archivo.close();
  } else {
    // throw std::runtime_error("No se pudo abrir el archivo");
  }
}
