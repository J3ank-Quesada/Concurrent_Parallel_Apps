#include "VisorFuturo.hpp"
#include <iostream>
VisorFuturo::VisorFuturo(){

}
VisorFuturo::VisorFuturo(MapaMagico* mapa){
  this->original = mapa;
}
VisorFuturo::~VisorFuturo(){

}

void VisorFuturo::revisarMapa(){
  copia = *original; 
  for(size_t f = 0 ; f <copia.mapa.size();f++){
    for(size_t c=0; c <copia.mapa.size(); c++){
      evaluarReglas(f,c);
    }
  }
  ++copia.numeroActual;
  *original = copia;
}

void VisorFuturo::evaluarReglas(int f, int c){
  if(original->mapa[f][c] == ARBOL){
    evaluarInundacion(f,c);
    evaluarHacimiento(f,c);
  } else {
    if(original->mapa[f][c] == LAGO){
      evaluarSequia(f,c);
    } else {
      if(original->mapa[f][c] == PRADERA){
        evaluarReforestacion(f,c);
      }
    }
  }
}
////////////////////////////////  REGLAS ////////////////////////////////////////////
void VisorFuturo::evaluarInundacion(int f, int c){
  int cantidadLagos = examinarCelda(f,c,LAGO);
  if(cantidadLagos>= 4){
    this->copia.mapa[f][c]= LAGO;
  }
}

void VisorFuturo::evaluarSequia(int f, int c){
  int cantidadLagos = examinarCelda(f,c,LAGO);
  if(cantidadLagos < 3){
    this->copia.mapa[f][c]= PRADERA;
  }
}

void VisorFuturo::evaluarReforestacion(int f, int c){
  int cantidadArboles= examinarCelda(f,c,ARBOL);
  if(cantidadArboles>= 3){
    this->copia.mapa[f][c]= ARBOL;
  }
}

void VisorFuturo::evaluarHacimiento(int f, int c){
  int cantidadArboles = examinarCelda(f,c,ARBOL);
  if(cantidadArboles > 4){
    this->copia.mapa[f][c]= PRADERA;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////
int VisorFuturo::examinarCelda(int f, int c, char encontrar){
  int encontrados = 0;
  for(int fila = f-1 ; fila<= f+1 ; fila++ ){
    for(int columna = c-1; columna<= c+1; columna++){
      if(verificarPosicion(fila,columna)&&(f!=fila || c != columna)){
        if(this->original->mapa[fila][columna] == encontrar){
          ++encontrados;
        }
      }
    }
  }
  return encontrados;
}

bool VisorFuturo::verificarPosicion(int f, int c){
  bool valida = true;
  if(f <0 || c<0){
    valida = false;
  } else {
    size_t fila = f;
    size_t columna = c;
    if(fila>=this->copia.mapa.size()){
      valida = false;
    }
    else{
      if(columna>= this->copia.mapa[0].size()){
        valida = false;
      }
    }
  }
  
  return valida;
}