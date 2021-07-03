#include "Lector.hpp"

using namespace std;

std::string Lector::separar(std::string linea)
{
  std::string nombre;
  int numero = linea.find_first_of(" ");
  for (int i = 0; i <= numero; i++)
  {
    nombre += linea[i];
  }
  return nombre;
}

int Lector::separarNumero(std::string linea)
{
  std::string numero;
  int pos = linea.find_first_of(" ")+1;
  for (int i = pos; i <= linea.length(); i++)
  {
    numero += linea[i];
  }
  int num = stoi(numero);
  return num;
}

void Lector::lectorTrabajo()
{
  string myText;
  string fileName;

  cout << "Ruta del trabajo\n";
  cin >> fileName;

  ifstream MyReadFile(fileName);

  if (MyReadFile.is_open())
  {
    while (getline(MyReadFile, myText))
    {
      Trabajo nuevoTrabajo(separarNumero(myText),separar(myText));
      trabajos.push_back(nuevoTrabajo);
    }
      MyReadFile.close();
  } else {
    cout << "No se pudo abrir" << endl; 
    }
}

std::vector<std::vector<char>> Lector::lectorMapa(std::string nombreArchivo) {
  std::vector<std::vector<char>> matriz;
  std::ifstream archivo;
  archivo.open(nombreArchivo);
  int numFilas;
  int numColumnas;
  if (archivo.is_open()) {
    std::string linea;
    // Se lee la primera linea
    std::getline(archivo, linea);
    int posEspacio = linea.find(' ');
    // Obtiene numero de filas y columnas
    numFilas = stoi(linea.substr(0, posEspacio));
    numColumnas = stoi(linea.substr(posEspacio + 1));
    int contLineas = 0;
    while (std::getline(archivo, linea) && contLineas < numFilas) {
      if (linea.length() >= numColumnas) {
        // Agrega el string a la matriz mapa
        std::vector<char> vector(linea.begin(), linea.end());
        matriz.push_back(vector);
        // Siguiente linea
        ++contLineas;
      }
    }
  } else {
    throw std::runtime_error("Archivo no encontrado");
  }
  return matriz;
}
