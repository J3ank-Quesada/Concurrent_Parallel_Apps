#include "MapaMagico.hpp"
#include <iostream>
#include "omp.h"

MapaMagico::MapaMagico(){
  this->numeroActual = 0;
}

MapaMagico::MapaMagico(int f, int c){
  this->numeroActual = 0;
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
  return ostream;
}

void MapaMagico::procesarMapaActual(){
  std::string fila = "";
  this->resultados.push_back(std::to_string(this->numeroActual));
  fila += ":\n";
  for(size_t f=0; f< this->mapa.size();f++){
    for(size_t c=0; c< this->mapa[0].size(); c++){
      fila += this->mapa[f][c];
    }
    fila += "\n";
    this->resultados.push_back(fila);
    fila = "";
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

MapaMagico& MapaMagico::operator = (const MapaMagico &otro){
  this->mapa = otro.mapa;
  this->miNombre = otro.miNombre;
  this->numeroActual = otro.numeroActual;
  this->numeroIteraciones = otro.numeroIteraciones;
  this->resultados = otro.resultados;
  return *this;
}

void MapaMagico::liberarMemoria(){
  this->resultados.clear();
  this->mapa.clear();
}