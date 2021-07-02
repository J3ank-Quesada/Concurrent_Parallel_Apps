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
std::ostream& operator << (std::ostream& ostream,
    const MapaMagico& mapaMagico){
  for(size_t i =0 ; i < mapaMagico.resultados.size();i++){
    ostream << mapaMagico.resultados[i];
  }
}

void MapaMagico::procesarMapaActual(){
  std::string fila = "";
  this->resultados.push_back(std::to_string(this->numeroActual));
  this->resultados.push_back(":\n");
  for(size_t f=0; f<mapa.size();f++){
    for(size_t c=0; c< this->mapa[0].size(); c++){
      fila += this->mapa[f][c];
    }
    this->resultados.push_back(fila);
    this->resultados.push_back("\n");
  }
  this->resultados.push_back("\n");
}


void MapaMagico::rellenarCaracter(char caracter){
  for(size_t f=0; f<mapa.size();f++){
    for(size_t c=0; c< this->mapa[0].size(); c++){
      this->mapa[f][c] = caracter;
    }
  }
}
