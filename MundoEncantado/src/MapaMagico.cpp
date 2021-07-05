/**
* @copyright 2021 ECCI, Universidad de Costa Rica. All rights reserved
* @author Hellen Fuentes Artavia <hellen.fuentesartavia@ucr.ac.cr>
* @author Jean Carlo Quesada Abarca <jean.quesadaabarca@ucr.ac.cr>
* @author Andrés Zamora Víquez <andres.zamoraviquez@ucr.ac.cr>
*/
#include "MapaMagico.hpp"
#include <iostream>
#include "Oraculo.hpp"

MapaMagico::MapaMagico() {
  this->numeroActual = 0;
}

MapaMagico::MapaMagico(int f, int c) {
  this->numeroActual = 0;
  setTamanioMapa(f, c);
}


void MapaMagico::setTamanioMapa(int f, int c) {
  this->mapa.resize(f);
  for (size_t i = 0; i < this->mapa.size(); i++) {
    mapa[i].resize(c);
  }
}
void MapaMagico::procesarMapaActual() {
  Oraculo oraculo;
  oraculo.ecribirSalida(this);
}


void MapaMagico::rellenarCaracter(char caracter) {
  for (size_t f = 0; f < mapa.size(); f++) {
    for (size_t c = 0; c < this->mapa[0].size(); c++) {
      this->mapa[f][c] = caracter;
    }
  }
}

MapaMagico& MapaMagico::operator = (const MapaMagico &otro) {
  this->mapa = otro.mapa;
  this->miNombre = otro.miNombre;
  this->numeroActual = otro.numeroActual;
  this->numeroIteraciones = otro.numeroIteraciones;
  return *this;
}

void MapaMagico::liberarMemoria() {
  this->mapa.clear();
}
