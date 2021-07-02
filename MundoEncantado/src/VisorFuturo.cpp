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
////////////////////////////////  REGLAS ////////////////////////////////////////////
void VisorFuturo::evaluarInundacion(int f, int c){
  int cantidadLagos = examinarCelda(f,c,LAGO);
  if(cantidadLagos>= 4){
    this->accesoMapa->at(f).at(c)= LAGO;
  }
}

void VisorFuturo::evaluarSequia(int f, int c){
  int cantidadLagos = examinarCelda(f,c,LAGO);
  if(cantidadLagos < 3){
    this->accesoMapa->at(f).at(c)= PRADERA;
  }
}

void VisorFuturo::evaluarReforestacion(int f, int c){
  int cantidadArboles= examinarCelda(f,c,ARBOL);
  if(cantidadArboles>= 3){
    this->accesoMapa->at(f).at(c)= ARBOL;
  }
}

void VisorFuturo::evaluarHacimiento(int f, int c){
  int cantidadArboles = examinarCelda(f,c,ARBOL);
  if(cantidadArboles > 4){
    this->accesoMapa->at(f).at(c)= PRADERA;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////
int VisorFuturo::examinarCelda(int f, int c, char encontrar){
  int encontrados = 0;
  for(int fila = f-1 ; fila<= f+1 ; fila++ ){
    for(int columna = c-1; columna<= c+1; columna++){
      if(verificarPosicion(fila,columna)){
        if(this->accesoMapa->at(fila).at(columna) == encontrar){
          ++encontrados;
        }
      }
    }
  }
  return encontrados;
}

bool VisorFuturo::verificarPosicion(int f, int c){
  size_t fila = f;
  size_t columna = c;
  bool valida = true;
  if(fila>=this->accesoMapa->size() || fila<0){
    valida = false;
  }
  else{
    if(columna>= this->accesoMapa[0].size() || columna < 0){
      valida = false;
    }
  }
  return valida;
}