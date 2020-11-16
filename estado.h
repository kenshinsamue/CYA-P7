/**
 * Enrique Manuel Pedroza Castillo
 * Alu: alu0100886351
 *
 * Clase Estado
 *
 * Clase que representa un estado del automata
 *
*/
#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <string>
using namespace std;
class Estado {
 public:
  Estado();        // constructor por defecto
  Estado(string);  // Constructor parametrizado con el id del estado
  string GetId();  // Metodo que retorna el id del estado
  void SetAceptado(
      bool);  // Metodo que establece si el estado se vuelve de aceptacion o no
  bool GetAceptado();  // Metodo para obtener si el estado es o no de aceptacion
 private:
  string id_;
  bool aceptado_;
};
#endif
