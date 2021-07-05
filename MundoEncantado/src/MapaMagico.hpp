#ifndef MAPAMAGICO_H_
#define MAPAMAGICO_H_
#define SALTO_LINEA 'n'
#include <vector>
#include <string>


class MapaMagico{
    private:
    public:
    int numeroIteraciones;
    int numeroActual;
    std::string miNombre; 
    std::vector<std::vector<char>> mapa;
    MapaMagico();
    MapaMagico(int f, int c);
    void setTamanioMapa(int f, int c);
    void rellenarCaracter(char caracter);
    void procesarMapaActual();
    MapaMagico& operator = (const MapaMagico &otro);
    void liberarMemoria();

};
#endif  // MAPAMAGICO_H_