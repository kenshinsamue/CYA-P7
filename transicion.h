/**
 * Enrique Manuel Pedroza Castillo
 * Alu: alu0100886351
 *
 * Clase Transicion
 *
 * Clase que representa la transicion que hay entre dos estados y la cadena de
 * transicion de la misma
 *
*/

#ifndef TRANSICION_H
#define TRANSICION_H
#include "estado.h"
using namespace std;
class Transicion {
 public:
  Transicion();                          // constructor por defecto
  Transicion(Estado*, string, Estado*);  // constructor parametrizado dando los
                                         // estados y la cadena de transicion
  Estado* GetOrigen();   // Metodo para obtener el estado de origen
  string GetCadena();    // Metodo para obtener el la cadena de la transicion
  Estado* GetDestino();  // metodo para obtener el estado de destino
 private:
  Estado* origen_;
  string cadena_;
  Estado* destino_;
};
#endif
