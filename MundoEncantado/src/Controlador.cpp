#include "Controlador.hpp"
#include "GeneradorMagico.hpp"
#include "EspejoMagico.hpp"
#include "Oraculo.hpp"

Controlador::Controlador(){

}
Controlador::~Controlador(){

}
void Controlador::iniciar(std::string nombreArchivo){
    GeneradorMagico generador;
    this->islas = generador.obtenerIslas(nombreArchivo);
    EspejoMagico clarividente(islas);
    clarividente.verDestino();
    Oraculo oraculo;
    oraculo.ecribirSalida(islas);
}