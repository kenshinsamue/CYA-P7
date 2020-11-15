#ifndef TRANSICION_H
#define TRANSICION_H
#include "estado.h"
using namespace std;
class Transicion{

  public:
    Transicion();
    Transicion(Estado*,string,Estado*);
    Estado* GetOrigen();
    string GetCadena();
    Estado* GetDestino();
  private:
  Estado* origen_;
  string cadena_;
  Estado* destino_;
};
#endif