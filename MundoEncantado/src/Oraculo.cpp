#include "Oraculo.hpp"
#include <iostream>
#include <fstream>
#include <string>

void Oraculo::ecribirSalida(std::string nombre,
  std::vector<MapaMagico>* mapasMagicos) {
    for (size_t i = 0; i < mapasMagicos->size(); i++) {
      MapaMagico mapaMagico = mapasMagicos->at(i);
      std::ofstream archivo;
      std::string nombreArchivo = mapaMagico.miNombre.append("-");
      nombreArchivo += std::to_string(mapaMagico.numeroIteraciones);
      archivo.open(nombreArchivo);
      if (archivo.is_open()) {
        archivo << mapasMagicos->at(i);
        archivo.close();
      } else {
        throw std::runtime_error("No se pudo abrir el archivo");
      }
  }
}

