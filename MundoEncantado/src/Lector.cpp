#include "Lector.hpp"

using namespace std;


void Lector::lector()
{
  Trabajo trabajo;
  vector<Trabajo> trabajos;

  string myText;
  string fileName;

  cout << "Ruta del archivo\n";
  cin >> fileName;

  ifstream MyReadFile(fileName);

  while (getline(MyReadFile, myText))
  {
    cout << trabajo.separar(myText) << endl;
    cout << trabajo.separarNumero(myText) << endl;
  }

  MyReadFile.close();
}