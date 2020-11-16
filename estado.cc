#include "estado.h"

Estado::Estado() {  // constructor por defecto
  aceptado_ = false;
}
Estado::Estado(
    string identificacion) {  // Constructor parametrizado con el id del estado
  id_ = identificacion;
}
string Estado::GetId() { return id_; }  // Metodo que retorna el id del estado
void Estado::SetAceptado(bool a) {
  aceptado_ = a;
}  // Metodo que establece si el estado se vuelve de aceptacion o no
// Metodo para obtener si el estado es o no de aceptacion
bool Estado::GetAceptado() { return aceptado_; }
