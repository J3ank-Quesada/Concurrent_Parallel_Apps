#include "Oraculo.hpp"
#include <iostream>
#include <fstream>
#include <string>

void Oraculo::ecribirSalida(
  std::vector<MapaMagico>* mapasMagicos) {
    for (size_t i = 0; i < mapasMagicos->size(); i++) {
      MapaMagico *mapaMagico = &mapasMagicos->at(i);
      std::ofstream archivo;
      std::string nombreArchivo = "";
      size_t posicionPunto = mapaMagico->miNombre.find_first_of(".");
      nombreArchivo += mapaMagico->miNombre.substr(0,posicionPunto);
      nombreArchivo+= "-";
      if(mapaMagico->numeroIteraciones < 0){
        mapaMagico->numeroIteraciones = mapaMagico->numeroIteraciones*(-1);
      }
      nombreArchivo += std::to_string(mapaMagico->numeroIteraciones);
      nombreArchivo+= ".txt";
      archivo.open(nombreArchivo);
      if (archivo.is_open()) {
        archivo << mapasMagicos->at(i);
        archivo.close();
      } else {
        throw std::runtime_error("No se pudo abrir el archivo");
      }
  }
}

