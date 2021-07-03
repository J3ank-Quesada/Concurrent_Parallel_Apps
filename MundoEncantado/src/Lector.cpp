#include "Lector.hpp"

void Lector::lectorTrabajo(std::string nombreArchivo,
  std::vector<Trabajo>* trabajos) {
  std::ifstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    std::string linea;
    while (getline(archivo, linea)) {
      int posEspacio = linea.find(' ');
      // Obtiene nombreMapa y numMidnights
      std::string nombreMapa = linea.substr(0, posEspacio);
      int numMidnights = stoi(linea.substr(posEspacio + 1));
      Trabajo nuevoTrabajo(nombreMapa, numMidnights);
      trabajos->push_back(nuevoTrabajo);
    }
    archivo.close();
  } else {
    throw std::runtime_error("Archivo no encontrado");
  }
}

void Lector::lectorMapa(std::string nombreArchivo,
      std::vector<std::vector<char>>* mapa) {
  std::ifstream archivo;
  archivo.open(nombreArchivo);
  int numFilas;
  int numColumnas;
  if (archivo.is_open()) {
    std::string linea;
    // Se lee la primera linea
    std::getline(archivo, linea);
    int posEspacio = linea.find(' ');
    // Obtiene numero de filas y columnas
    numFilas = stoi(linea.substr(0, posEspacio));
    numColumnas = stoi(linea.substr(posEspacio + 1));
    int contLineas = 0;
    while (std::getline(archivo, linea) && contLineas < numFilas) {
      if (linea.length() >= numColumnas) {
        // Agrega el string a la matriz mapa
        std::vector<char> vector(linea.begin(), linea.end());
        mapa->push_back(vector);
        // Siguiente linea
        ++contLineas;
      }
    }
  } else {
    throw std::runtime_error("Archivo no encontrado");
  }
}
