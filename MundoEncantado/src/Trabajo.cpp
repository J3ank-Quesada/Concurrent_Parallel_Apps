#include "Trabajo.hpp"

Trabajo::Trabajo() {
}
Trabajo::Trabajo(std::string nombreMapa, int numMidnights) {
  this->nombreMapa = nombreMapa;
  this->numMidnights = numMidnights;
}

Trabajo::~Trabajo() {
}

std::string Trabajo::getNombreMapa() {
  return this->nombreMapa;
}

int Trabajo::getNumMidnights() {
  return this->numMidnights;
}
