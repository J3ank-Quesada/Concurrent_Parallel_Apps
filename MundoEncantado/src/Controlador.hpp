#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "MapaMagico.hpp"
#include <vector>
#include <string>

class Controlador
{
private:
std::vector<MapaMagico*> *islas;
    
public:
    Controlador();
    ~Controlador();
    void iniciar(std::string nombreArchivo);
    void liberarMemoria();
    bool crearDirectorio();
};
#endif  // CONTROLADOR_H_