#include "transicion.h"

Transicion::Transicion(){}

Transicion::Transicion(Estado* origen,string cadena,Estado* destino){
  origen_=origen;
  cadena_ = cadena;
  destino_= destino;
}

Estado* Transicion::GetOrigen(){return origen_;}
string Transicion::GetCadena(){return cadena_;}
Estado* Transicion::GetDestino(){return destino_;}