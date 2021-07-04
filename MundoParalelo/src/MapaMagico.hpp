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
    std::vector<std::string> resultados;
    MapaMagico();
    MapaMagico(int f, int c);
    void setTamanioMapa(int f, int c);
    void rellenarCaracter(char caracter);
    void procesarMapaActual();
    MapaMagico& operator = (const MapaMagico &otro);
    friend std::ostream& operator << (std::ostream& ostream,
                                    const MapaMagico& mapaMagico);

};
#endif  // MAPAMAGICO_H_