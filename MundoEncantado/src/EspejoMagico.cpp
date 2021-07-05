/**
* @copyright 2021 ECCI, Universidad de Costa Rica. All rights reserved
* @author Hellen Fuentes Artavia <hellen.fuentesartavia@ucr.ac.cr>
* @author Jean Carlo Quesada Abarca <jean.quesadaabarca@ucr.ac.cr>
* @author Andrés Zamora Víquez <andres.zamoraviquez@ucr.ac.cr>
*/
#include "EspejoMagico.hpp"
EspejoMagico::EspejoMagico(MapaMagico* isla) {
  this->isla = isla;
}

void EspejoMagico::verDestino() {
  evaluarIsla(isla);
}

void EspejoMagico::evaluarIsla(MapaMagico* isla) {
  isla->procesarMapaActual();
  VisorFuturo visor;
  // Si en la isla solo se quiere ver el resultado final
  if (isla->numeroIteraciones < 0) {
    isla->numeroIteraciones = isla->numeroIteraciones*(-1);
    for (int futuro =0 ; futuro < isla->numeroIteraciones; futuro++) {
      visor.revisarMapa(isla);
      if (futuro == isla->numeroIteraciones-1) {
        isla->procesarMapaActual();
      }
    }
  } else {
    // Si se quiere observar todo los procedimientos paso a paso
    for (int futuro = 0; futuro < isla->numeroIteraciones; futuro++) {
      visor.revisarMapa(isla);
      isla->procesarMapaActual();
    }
  }
  isla->liberarMemoria();
}
