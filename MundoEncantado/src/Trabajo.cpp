#include "Trabajo.hpp"

std::string Trabajo::separar(std::string linea)
{
  std::string nombre;
  int numero = linea.find_first_of(" ");
  for (int i = 0; i <= numero; i++)
  {
    nombre += linea[i];
  }
  return nombre;
}

std::string Trabajo::separarNumero(std::string linea)
{
  std::string numero;
  int pos = linea.find_first_of(" ");
  for (int i = pos; i <= linea.length(); i++)
  {
    numero += linea[i];
  }
  return numero;
}
