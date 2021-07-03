#include "VisorFuturo.hpp"
#include <iostream>
VisorFuturo::VisorFuturo(){

}
VisorFuturo::~VisorFuturo(){

}

void VisorFuturo::revisarMapa(MapaMagico* mapa){
  alistarCopia(mapa->mapa);
  for(size_t f = 0 ; f <mapa->mapa.size();f++){
    for(size_t c=0; c <mapa->mapa[0].size(); c++){
      evaluarReglas(f,c,mapa);
    }
  }
  ++mapa->numeroActual;
}

void VisorFuturo::evaluarReglas(int f, int c, MapaMagico* mapa){
  if(copia[f][c] == ARBOL){
    evaluarInundacion(f,c,mapa);
    evaluarHacimiento(f,c,mapa);
  } else {
    if(copia[f][c] == LAGO){
      evaluarSequia(f,c,mapa);
    } else {
      if(copia[f][c] == PRADERA){
        evaluarReforestacion(f,c,mapa);
      }
    }
  }
}
////////////////////////////////  REGLAS ////////////////////////////////////////////
void VisorFuturo::evaluarInundacion(int f, int c,MapaMagico* mapa){
  int cantidadLagos = examinarCelda(f,c,LAGO);
  if(cantidadLagos>= 4){
    mapa->mapa[f][c]= LAGO;
  }
}

void VisorFuturo::evaluarSequia(int f, int c,MapaMagico* mapa){
  int cantidadLagos = examinarCelda(f,c,LAGO);
  if(cantidadLagos < 3){
    mapa->mapa[f][c]= PRADERA;
  }
}

void VisorFuturo::evaluarReforestacion(int f, int c,MapaMagico* mapa){
  int cantidadArboles= examinarCelda(f,c,ARBOL);
  if(cantidadArboles>= 3){
    mapa->mapa[f][c]= ARBOL;
  }
}

void VisorFuturo::evaluarHacimiento(int f, int c,MapaMagico* mapa){
  int cantidadArboles = examinarCelda(f,c,ARBOL);
  if(cantidadArboles > 4){
    mapa->mapa[f][c]= PRADERA;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////
int VisorFuturo::examinarCelda(int f, int c, char encontrar){
  int encontrados = 0;
  for(int fila = f-1 ; fila<= f+1 ; fila++ ){
    for(int columna = c-1; columna<= c+1; columna++){
      if(verificarPosicion(fila,columna)&&(f!=fila || c != columna)){
        if(this->copia[fila][columna] == encontrar){
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
    if(fila>=this->copia.size()){
      valida = false;
    }
    else{
      if(columna>= this->copia[0].size()){
        valida = false;
      }
    }
  }
  
  return valida;
}

void VisorFuturo::alistarCopia(std::vector<std::vector<char>> original){
  this->copia.resize(original.size());
  for(size_t i= 0 ; i < copia.size(); i++){
    copia[i].resize(original[0].size());
  }
  for(size_t i= 0 ; i < copia.size(); i++){
    for(size_t j = 0 ; j < copia[0].size() ; j++){
      copia[i][j] = original[i][j];
    }
  }
}

void VisorFuturo::imprimirMatrizMensaje(std::string mensaje,std::vector<std::vector<char>> matriz){
  std::cout << mensaje<< std::endl;
  for(size_t i= 0 ; i < matriz.size(); i++){
    for(size_t j = 0 ; j < matriz[0].size() ; j++){
      std::cout<<matriz[i][j] ;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}