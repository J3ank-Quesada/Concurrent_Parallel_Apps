#include "MapaMagico.hpp"
#include <iostream>

MapaMagico::MapaMagico(){
}

MapaMagico::MapaMagico(int f, int c){
  setTamanioMapa(f,c);
}


void MapaMagico::setTamanioMapa(int f, int c){
  this->mapa.resize(f);
  for(size_t i=0; i<this->mapa.size(); i++){
    mapa[i].resize(c);
  }
}
void MapaMagico::printMe(){
  for(size_t f=0; f<this->mapa.size();f++){
    for(size_t c=0; c<this->mapa[0].size(); c++){
      std::cout<<this->mapa[f][c];
    }
    std::cout<<std::endl;
  }
}
void MapaMagico::rellenarCaracter(char caracter){
  for(size_t f=0; f<mapa.size();f++){
    for(size_t c=0; c< this->mapa[0].size(); c++){
      this->mapa[f][c] = caracter;
    }
  }
}
