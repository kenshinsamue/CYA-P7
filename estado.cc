#include "estado.h"
#include <iostream>
Estado::Estado(){
  aceptado_ = false;
}
Estado::Estado(string identificacion){
  id_ = identificacion;
}
string Estado::GetId(){return id_;}
void Estado::SetAceptado(bool a){ aceptado_=a;}
bool operator < (const Estado& first,const Estado& second){
  return true;
}
bool operator == (const Estado& first, const Estado& second){
  return true;
}
bool Estado::GetAceptado(){
  return aceptado_;
}