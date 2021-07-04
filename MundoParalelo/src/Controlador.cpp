#include "Controlador.hpp"
#include "GeneradorMagico.hpp"
#include "EspejoMagico.hpp"
#include "Oraculo.hpp"
#include <sys/stat.h>
#define DIRECTORIO_SALIDA "../Salidas"

Controlador::Controlador(){

}
Controlador::~Controlador(){

}
void Controlador::iniciar(std::string nombreArchivo, std::string ruta){
    GeneradorMagico generador;
    this->islas = generador.obtenerIslas(nombreArchivo,ruta);
    EspejoMagico clarividente(islas);
    clarividente.verDestino();
    Oraculo oraculo;
    oraculo.ecribirSalida(islas);
    liberarMemoria();
}



void Controlador::liberarMemoria(){
    for(size_t i = 0 ; i < islas->size(); i++){
        delete islas->at(i);
    }
}

void Controlador::crearDirectorio(){
    mkdir(DIRECTORIO_SALIDA,0777);
}