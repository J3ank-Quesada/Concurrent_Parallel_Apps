#ifndef LECTOR_H_
#define LECTOR_H_
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include "Trabajo.hpp"
class MapaMagico;

class Lector{
 public:
  void lectorTrabajo(std::string nombreArchivo,
    std::vector<Trabajo>* trabajos, std::string ruta);
  void lectorMapa(std::string nombreArchivo,
    MapaMagico* mapaMagico, std::string ruta);
};

#endif  // LECTOR_H_