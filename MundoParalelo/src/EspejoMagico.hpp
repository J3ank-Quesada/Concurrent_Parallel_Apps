#ifndef ESPEJO_MAGICO_H_
#define ESPEJO_MAGICO_H_
#include <vector>
#include "MapaMagico.hpp"
#include "VisorFuturo.hpp"

class EspejoMagico{
  private:
  MapaMagico* isla;

  public:
  EspejoMagico(MapaMagico* isla);
  void verDestino();
  void evaluarIsla(MapaMagico *isla);

};
#endif  // ESPEJO_MAGICO_H_