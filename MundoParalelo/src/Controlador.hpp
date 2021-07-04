#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "MapaMagico.hpp"
#include "Trabajo.hpp"
#include <vector>
#include <string>

class Controlador
{
private:
std::vector<Trabajo> trabajos;
    
public:
  Controlador();
  ~Controlador();
  void iniciar(std::string nombreArchivo, std::string ruta);
  void liberarMemoria(MapaMagico *eliminar);
  void crearDirectorio();
};
#endif  // CONTROLADOR_H_