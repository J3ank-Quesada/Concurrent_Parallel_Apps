#include "Controlador.hpp"
#include "GeneradorMagico.hpp"
#include "EspejoMagico.hpp"
#include <sys/stat.h>
#define DIRECTORIO_SALIDA "../Salidas"

Controlador::Controlador(){

}
Controlador::~Controlador(){
}
void Controlador::iniciar(std::string nombreArchivo, std::string ruta){
    GeneradorMagico generador;
    this->islas = generador.obtenerIslas(nombreArchivo,ruta);
    crearDirectorio();
    EspejoMagico clarividente(islas);
    clarividente.verDestino();
    liberarMemoria();
}

void Controlador::liberarMemoria(){
}

void Controlador::crearDirectorio(){
    mkdir(DIRECTORIO_SALIDA,0777);
}