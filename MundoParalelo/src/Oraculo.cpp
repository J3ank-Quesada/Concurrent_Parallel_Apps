#include "Oraculo.hpp"
#include <iostream>
#include <fstream>
#include <string>
#define DIRECTORIO_SALIDA "../Salidas"

void Oraculo::ecribirSalida(MapaMagico *mapa) {
    for (size_t i = 0; i < mapa->mapa.size(); i++) {
      std::ofstream archivo;
      std::string nombreArchivo;
      size_t posicionPunto = mapa->miNombre.find_first_of(".");
      nombreArchivo += mapa->miNombre.substr(0,posicionPunto);
      nombreArchivo+= "-";
      if(mapa->numeroIteraciones < 0){
        mapa->numeroIteraciones = mapa->numeroIteraciones*(-1);
      }
      nombreArchivo += std::to_string(mapa->numeroIteraciones);
      nombreArchivo+= ".txt";
      std::string rutaSalida = DIRECTORIO_SALIDA;
      rutaSalida += "/";
      rutaSalida+= nombreArchivo;
      archivo.open(rutaSalida);
      if (archivo.is_open()) {
        archivo << *mapa;
        archivo.close();
      } else {
        //throw std::runtime_error("No se pudo abrir el archivo");
      }
  }
}

