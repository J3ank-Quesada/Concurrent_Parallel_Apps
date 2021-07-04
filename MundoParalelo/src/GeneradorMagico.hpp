#ifndef GENERADORMAGICO_H_
#define GENERADORMAGICO_H_
#include "Trabajo.hpp"
#include "MapaMagico.hpp"
#include "Lector.hpp"
#include <vector>
#include <string>

class GeneradorMagico {
 private:
  MapaMagico *procesar;
  Lector lector;
 public:
  GeneradorMagico();
  ~GeneradorMagico(){};
  void obtenerIslas(std::string nombreArchivo, std::string ruta, std::vector<Trabajo>* escribir);
  MapaMagico* obtenerMapa(std::string nombreMapa,int midnights ,std::string ruta);
};

#endif // GENERADORMAGICO_H_
