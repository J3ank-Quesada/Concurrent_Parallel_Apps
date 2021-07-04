#ifndef ESPEJO_MAGICO_H_
#define ESPEJO_MAGICO_H_
#include <vector>
#include "MapaMagico.hpp"
#include "VisorFuturo.hpp"

class EspejoMagico{
  private:
  std::vector<MapaMagico>* islas;

  public:
  EspejoMagico(std::vector<MapaMagico>* islas);
  void verDestino();
  void evaluarIsla(MapaMagico *isla);

};
#endif  // ESPEJO_MAGICO_H_