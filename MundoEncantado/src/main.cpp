#include "Controlador.hpp"
#include <string>

int main(int argc, char* argv[]) {
  int estado = EXIT_SUCCESS;
  std::string nombreArchivo = "";
  std::string ruta="";
  Controlador controlador;
  if(argc == 3){
    nombreArchivo = argv[1];
    ruta = argv[2];
  }
  if(ruta == "" || nombreArchivo == ""){
    estado = EXIT_FAILURE;
  }else{
    controlador.iniciar(nombreArchivo,ruta);
  }
  return estado;
}

