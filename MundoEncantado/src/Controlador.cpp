#include "Controlador.hpp"
#include "GeneradorMagico.hpp"
#include "EspejoMagico.hpp"

Controlador::Controlador(){

}
Controlador::~Controlador(){

}
void Controlador::iniciar(std::string nombreArchivo){
    GeneradorMagico generador;
    this->islas = generador.obtenerIslas(nombreArchivo);
    EspejoMagico clarividente(islas);
    clarividente.verDestino();
    //Llamar al escritor
}