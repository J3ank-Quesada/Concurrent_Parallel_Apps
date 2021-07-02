#include "VisorFuturo.hpp"

VisorFuturo::VisorFuturo(std::vector<std::vector<char>>* mapa){
  this->accesoMapa = mapa;
}
VisorFuturo::~VisorFuturo(){

}
void VisorFuturo::evaluarReglas(int f, int c){
  if(accesoMapa->at(f).at(c) == ARBOL){
    evaluarHacimiento(f,c);
    evaluarInundacion(f,c);
  } else {
    if(accesoMapa->at(f).at(c) == LAGO){
      evaluarSequia(f,c);
    } else {
      evaluarReforestacion(f,c);
    }
  }
    
}
void VisorFuturo::evaluarInundacion(int f, int c){
  
}
void VisorFuturo::evaluarSequia(int f, int c){

}
void VisorFuturo::evaluarReforestacion(int f, int c){

}
void VisorFuturo::evaluarHacimiento(int f, int c){

}
void VisorFuturo::examinarCelda(int f, int c, char encontrar, int cuantosEncontrar){
  

}

bool VisorFuturo::verificarPosicion(int f, int c){

}