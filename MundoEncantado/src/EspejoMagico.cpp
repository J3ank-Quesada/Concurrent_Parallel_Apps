#include "EspejoMagico.hpp"
EspejoMagico::EspejoMagico(std::vector<MapaMagico>* islas){
  this->islas = islas;
}
void EspejoMagico::verDestino(){
  for(size_t viajero = 0; viajero < islas->size(); viajero++){
    evaluarIsla(&islas->at(viajero));
  }   
}
void EspejoMagico::evaluarIsla(MapaMagico* isla){
  isla->procesarMapaActual();
  VisorFuturo visor(isla);
  // Si en la isla solo se quiere ver el resultado final
  if(isla->numeroIteraciones < 0){
    int iteraciones = isla->numeroIteraciones*(-1);
    for(int futuro =0 ; futuro < iteraciones; futuro++){
      visor.revisarMapa();
      if(futuro == isla->numeroIteraciones-1){
        isla->procesarMapaActual();
      }
    }
  } else {
    // Si se quiere observar todo los procedimientos paso a paso
    for(int futuro =0 ; futuro < isla->numeroIteraciones; futuro++){
      visor.revisarMapa();
      isla->procesarMapaActual();
    }
  }
}