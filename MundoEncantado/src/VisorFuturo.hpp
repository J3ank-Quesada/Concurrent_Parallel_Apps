#ifndef VISOR_FUTURO_H_
#define VISOR_FUTURO_H_
#define LAGO 'l'
#define PRADERA '-'
#define ARBOL 'a'
#include <vector>
#include "MapaMagico.hpp"

class VisorFuturo
{
  private:
  MapaMagico copia;
  void evaluarInundacion(int f, int c);
  void evaluarSequia(int f, int c);
  void evaluarReforestacion(int f, int c);
  void evaluarHacimiento(int f, int c);
  int examinarCelda(int f, int c, char encontrar);
  bool verificarPosicion(int f, int c);
  MapaMagico* original;
  void evaluarReglas(int f, int c);
  public:
  VisorFuturo(MapaMagico* mapa);
  ~VisorFuturo();
  void revisarMapa();
};

#endif  // VISOR_FUTURO_H_