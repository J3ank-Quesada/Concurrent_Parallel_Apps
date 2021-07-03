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

int Lector::getFirstDim(std::string linea){
  std::string numero;

  int pos = linea.find_first_of(" ");
  for (int i = 0; i < pos; i++)
  {
    numero += linea[i];
  }
  int num = stoi(numero);
  return num;
}

int Lector::getSecondDim(std::string linea){
  std::string numero;

  int pos = linea.find_first_of(" ") +1;
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

void Lector::lectorMapa(){
  string myText;
  string fileName;
  int contador = 0;
  int ini = 0;

  //TODO pasarle los files de job

  cout << "Ruta del mapa\n";
  cin >> fileName;

  ifstream MyReadFile(fileName);  // "../input/map001.txt"

  if (MyReadFile.is_open())
  {
    while (getline(MyReadFile, myText))
    {
      if (ini  == contador){
        cout << "Dimensiones" << endl;
        cout << getFirstDim(myText) << endl;
        cout << getSecondDim(myText) << endl;
      } else {
        if (int index = 1 == contador){
        cout << "Cantidad columnas" << endl;
        cout << myText.size() << "\n";
        }
      }
      contador++;
    }
      cout << "Cantidad filas" << endl;
      cout << contador-1 << endl; //columnas
      MyReadFile.close();
  } else {
    cout << "No se pudo abrir" << endl; 
    }
}