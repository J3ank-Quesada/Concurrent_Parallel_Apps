#ifndef LECTOR_H_
#define LECTOR_H_
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include "Trabajo.hpp"

class Lector{
 public:
  void lectorTrabajo(std::string nombreArchivo,
    std::vector<Trabajo>* trabajos);
  void lectorMapa(std::string nombreArchivo,
    std::vector<std::vector<char>>*);
};

#endif  // LECTOR_H_