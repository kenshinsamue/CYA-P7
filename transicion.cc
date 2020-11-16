#include "transicion.h"

Transicion::Transicion() {}  // constructor por defecto

Transicion::Transicion(Estado* origen, string cadena,
                       Estado* destino) {  // constructor parametrizado dando
                                           // los estados y la cadena de
                                           // transicion
  origen_ = origen;
  cadena_ = cadena;
  destino_ = destino;
}

Estado* Transicion::GetOrigen() {
  return origen_;
}  // Metodo para obtener el estado de origen
string Transicion::GetCadena() {
  return cadena_;
}  // Metodo para obtener el la cadena de la transicion
Estado* Transicion::GetDestino() {
  return destino_;
}  // metodo para obtener el estado de destino
