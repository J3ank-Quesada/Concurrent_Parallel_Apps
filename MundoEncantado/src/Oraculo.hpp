#ifndef ORACULO_H_
#define ORACULO_H_
#include "MapaMagico.hpp"
#include <vector>
#include <string>

class Oraculo {
 public:
  void ecribirSalida(std::vector<MapaMagico>* mapasMagicos);
};

#endif  // ORACULO_H_