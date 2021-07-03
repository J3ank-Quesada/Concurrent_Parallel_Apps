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
    if(crearDirectorio()){
        oraculo.ecribirSalida(islas);
    }
    liberarMemoria();
}



void Controlador::liberarMemoria(){
    for(size_t i = 0 ; i < islas->size(); i++){
        delete islas->at(i);
    }
}

bool Controlador::crearDirectorio(){
    bool creado = false;
    int exito = mkdir(DIRECTORIO_SALIDA,0777);
    if (!exito){
    creado = true;
    std::cout<<"Directorio Creado" <<std::endl;
    }
    else {
    std::cout << "Unable to create directory"<<std::endl;
    exit(1);
    }
    return creado;

}