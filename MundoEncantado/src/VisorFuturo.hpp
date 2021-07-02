#ifndef VISOR_FUTURO_H_
#define VISOR_FUTURO_H_
#define LAGO 'l'
#define PRADERA '-'
#define ARBOL 'a'
#include <vector>

class VisorFuturo
{
  private:
  std::vector<std::vector<char>>* accesoMapa;
  public:
  VisorFuturo(std::vector<std::vector<char>>* mapa);
  ~VisorFuturo();
  void evaluarReglas(int f, int c);
  void evaluarInundacion(int f, int c);
  void evaluarSequia(int f, int c);
  void evaluarReforestacion(int f, int c);
  void evaluarHacimiento(int f, int c);
  int examinarCelda(int f, int c, char encontrar);
  bool verificarPosicion(int f, int c);
};

#endif  // VISOR_FUTURO_H_