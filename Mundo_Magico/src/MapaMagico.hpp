#ifndef MAPAMAGICO_H_
#define MAPAMAGICO_H_
#include <vector>


class MapaMagico{
    private:

    public:
    int numeroF;
    int numeroC;
    std::vector<std::vector<char>> mapa;
    MapaMagico();
    MapaMagico(int f, int c);
    void setTamanioMapa(int f, int c);
};
#endif  // MAPAMAGICO_H_