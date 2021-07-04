#ifndef TRABAJO_H_
#define TRABAJO_H_
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>

class Trabajo
{
private:
  std::string nombreMapa;
  int numMidnights;
public:
  Trabajo();
  Trabajo(std::string nombreMapa, int numMidnights);
  ~Trabajo();
  std::string getNombreMapa();
  int getNumMidnights();
};
#endif  // TRABAJO_H_
