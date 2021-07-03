#include "Lector.hpp"
#include "MapaMagico.hpp"

void Lector::lectorTrabajo(std::string nombreArchivo,
  std::vector<Trabajo>* trabajos,std::string ruta) {
    std::string nombre ="";
    nombre+= ruta;
    nombre+=nombreArchivo;
  std::ifstream archivo(nombre);
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
    //throw std::runtime_error("Archivo no encontrado");
  }
}

void Lector::lectorMapa(std::string nombreArchivo,
      MapaMagico* mapaMagico,std::string ruta) {
  std::string nombre ="";
  nombre+= ruta;
  nombre+=nombreArchivo;
  std::ifstream archivo;
  archivo.open(nombre);
  size_t numFilas;
  size_t numColumnas;
  if (archivo.is_open()) {
    std::string linea;
    // Se lee la primera linea
    std::getline(archivo, linea);
    int posEspacio = linea.find(' ');
    // Obtiene numero de filas y columnas
    numFilas = stoi(linea.substr(0, posEspacio));
    numColumnas = stoi(linea.substr(posEspacio + 1));
    mapaMagico->setTamanioMapa(numFilas, numColumnas);
    size_t contLineas = 0;
    while (std::getline(archivo, linea) && contLineas < numFilas) {
      if (linea.length() >= numColumnas) {
        // Agrega el string a la matriz mapa
        for (size_t j = 0; j < mapaMagico->mapa[0].size(); j++) {
          mapaMagico->mapa[contLineas][j] = linea[j];
        }
        // Siguiente linea
        ++contLineas;
      }
    }
  } else {
    //throw std::runtime_error("Archivo no encontrado");
  }
}
