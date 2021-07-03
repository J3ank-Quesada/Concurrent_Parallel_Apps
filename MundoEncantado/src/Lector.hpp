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

  vector<Trabajo> trabajos;

  void lectorTrabajo();
  void lectorMapa();
  std::string separar(std::string);
  int separarNumero(std::string);
  int getFirstDim(std::string);
  int getSecondDim(std::string);
};

#endif  // LECTOR_H_