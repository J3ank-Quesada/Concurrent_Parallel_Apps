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
  int midnigths;
  std::string fileNameMap;
  Trabajo();
  Trabajo(int midnigths, std::string fileNameMap);
  ~Trabajo();
  
};

#endif  // TRABAJO_H_
