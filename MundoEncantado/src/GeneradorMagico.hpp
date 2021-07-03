#ifndef GENERADORMAGICO_H_
#define GENERADORMAGICO_H_
#include "Trabajo.hpp"
#include "MapaMagico.hpp"
#include "Lector.hpp"
#include <vector>
#include <string>

class GeneradorMagico {
 private:
  std::vector<Trabajo> trabajos;
  std::vector<MapaMagico*> mapasMagicos;
  Lector lector;
 public:
  GeneradorMagico();
  ~GeneradorMagico(){};
  std::vector<MapaMagico*>* obtenerIslas(std::string nombreArchivo);
};

#endif // GENERADORMAGICO_H_
