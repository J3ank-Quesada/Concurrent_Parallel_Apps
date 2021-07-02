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
public:
  Trabajo(){}
  ~Trabajo(){}
  std::string separar(std::string);
  std::string separarNumero(std::string);

  int64_t midnigths;
  std::string fileNameMap;
};

#endif  // TRABAJO_H_
