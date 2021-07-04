#include "EspejoMagico.hpp"
EspejoMagico::EspejoMagico(std::vector<MapaMagico*>* islas){
  this->islas = islas;
}
void EspejoMagico::verDestino(){
  for(size_t posicion = 0; posicion < islas->size(); posicion++){
    evaluarIsla(islas->at(posicion));
  }   
}
void EspejoMagico::evaluarIsla(MapaMagico* isla){
  isla->procesarMapaActual();
  VisorFuturo visor;
  // Si en la isla solo se quiere ver el resultado final
  if(isla->numeroIteraciones < 0){
    isla->numeroIteraciones = isla->numeroIteraciones*(-1);
    for(int futuro =0 ; futuro < isla->numeroIteraciones; futuro++){
      visor.revisarMapa(isla);
      if(futuro == isla->numeroIteraciones-1){
        isla->procesarMapaActual();
      }
    }
  } else {
    // Si se quiere observar todo los procedimientos paso a paso
    for(int futuro =0 ; futuro < isla->numeroIteraciones; futuro++){
      visor.revisarMapa(isla);
      isla->procesarMapaActual();
    }
  }
}