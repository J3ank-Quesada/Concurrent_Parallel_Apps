#include "Controlador.hpp"
#include <string>

int main(int argc, char* argv[]) {
  std::string nombreArchivo;
  Controlador controlador;
  if(argc == 2){
    nombreArchivo = argv[1];
  }
  controlador.iniciar(nombreArchivo);
  return 0;
}

