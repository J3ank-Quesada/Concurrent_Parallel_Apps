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
  std::vector<std::vector<char>> copia;
  void evaluarInundacion(int f, int c,MapaMagico* mapa);
  void evaluarSequia(int f, int c,MapaMagico* mapa);
  void evaluarReforestacion(int f, int c,MapaMagico* mapa);
  void evaluarHacimiento(int f, int c,MapaMagico* mapa);
  bool examinarCelda(int f, int c, char encontrar,int cuantos);
  bool verificarPosicion(int f, int c);
  void evaluarReglas(int f, int c,MapaMagico* mapa);
  public:
  VisorFuturo();
  ~VisorFuturo();
  void revisarMapa(MapaMagico* mapa);
  void alistarCopia(std::vector<std::vector<char>> original);
  void imprimirMatrizMensaje(std::string mensaje,std::vector<std::vector<char>> matriz);
};

#endif  // VISOR_FUTURO_H_