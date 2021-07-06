/**
* @copyright 2021 ECCI, Universidad de Costa Rica. All rights reserved
* @author Hellen Fuentes Artavia <hellen.fuentesartavia@ucr.ac.cr>
* @author Jean Carlo Quesada Abarca <jean.quesadaabarca@ucr.ac.cr>
* @author Andrés Zamora Víquez <andres.zamoraviquez@ucr.ac.cr>
*/
#include <iostream>
#include "VisorFuturo.hpp"

VisorFuturo::VisorFuturo() { }

VisorFuturo::~VisorFuturo() { }

void VisorFuturo::revisarMapa(MapaMagico* mapa) {
  alistarCopia(mapa->mapa);
  for (size_t f = 0; f < mapa->mapa.size(); f++) {
    for (size_t c = 0; c < mapa->mapa[0].size(); c++) {
      evaluarReglas(f, c, mapa);
    }
  }
  ++mapa->numeroActual;
}

void VisorFuturo::evaluarReglas(int f, int c, MapaMagico* mapa) {
  if (copia[f][c] == ARBOL) {
    evaluarInundacion(f, c, mapa);
    evaluarHacimiento(f, c, mapa);
  } else {
    if (copia[f][c] == LAGO) {
      evaluarSequia(f, c, mapa);
    } else {
      if (copia[f][c] == PRADERA) {
        evaluarReforestacion(f, c, mapa);
      }
    }
  }
}

// -----------------------------------------------------------REGLAS----------------------------------------------------------------

void VisorFuturo::evaluarInundacion(int f, int c, MapaMagico* mapa) {
  if (examinarCelda(f, c, LAGO, 4)) {
    mapa->mapa[f][c]= LAGO;
  }
}

void VisorFuturo::evaluarSequia(int f, int c, MapaMagico* mapa) {
  if (!examinarCelda(f, c, LAGO, 3)) {
    mapa->mapa[f][c]= PRADERA;
  }
}

void VisorFuturo::evaluarReforestacion(int f, int c, MapaMagico* mapa) {
  if (examinarCelda(f, c, ARBOL, 3)) {
    mapa->mapa[f][c]= ARBOL;
  }
}

void VisorFuturo::evaluarHacimiento(int f, int c, MapaMagico* mapa) {
  if (examinarCelda(f, c, ARBOL, 5)) {
    mapa->mapa[f][c]= PRADERA;
  }
}

// ----------------------------------------------------------------------------------------------------------------------------------

bool VisorFuturo::examinarCelda(int f, int c, char encontrar, int cuantos) {
  int encontrados = 0;
  bool parar = false;
  for (int fila = f-1; fila<= f+1 && (!parar); fila++) {
    if (verificarPosicion(fila, 0)) {
      for (int columna = c-1; columna<= c+1 && (!parar) ; columna++) {
        if (verificarPosicion(0, columna)&&(f != fila || c != columna)) {
          if (this->copia[fila][columna] == encontrar) {
            ++encontrados;
            if (encontrados == cuantos) {
              parar = true;
            }
          }
        }
      }
    }
  }
  return parar;
}

bool VisorFuturo::verificarPosicion(int f, int c) {
  bool valida = true;
  if ((f < 0) || (c < 0) || (c >= static_cast<int>(this->copia[0].size())) ||
    (f >= static_cast<int>(this->copia.size()))) {
    valida = false;
  }
  return valida;
}

void VisorFuturo::alistarCopia(std::vector<std::vector<char>> original) {
  this->copia.resize(original.size());
  for (size_t i= 0 ; i < copia.size(); i++) {
    copia[i].resize(original[0].size());
  }
  for (size_t i = 0 ; i < copia.size(); i++) {
    for (size_t j = 0 ; j < copia[0].size(); j++) {
      copia[i][j] = original[i][j];
    }
  }
}

void VisorFuturo::imprimirMatrizMensaje(std::string mensaje,
  std::vector<std::vector<char>> matriz) {
  std::cout << mensaje<< std::endl;
  for (size_t i= 0 ; i < matriz.size(); i++) {
    for (size_t j = 0 ; j < matriz[0].size(); j++) {
      std::cout << matriz[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}
