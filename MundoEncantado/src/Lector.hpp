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

  std::vector<Trabajo> trabajos;

  void lectorTrabajo();
  std::vector<std::vector<char>> lectorMapa(std::string nombreArchivo);
  std::string separar(std::string);
  int separarNumero(std::string);
};

#endif  // LECTOR_H_