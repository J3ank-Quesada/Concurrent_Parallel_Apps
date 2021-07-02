#include "MapaMagico.hpp"

MapaMagico::MapaMagico(){
    this->numeroC = -1;
    this->numeroF = -1;
}

MapaMagico::MapaMagico(int f, int c){
    this->numeroF = f;
    this->numeroC = c;
    setTamanioMapa(f,c);
}


void MapaMagico::setTamanioMapa(int f, int c){
    this->mapa.resize(f);
    for(size_t i=0; i<this->mapa.size(); i++){
        mapa[i].resize(c);
    }
}