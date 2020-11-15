#include "dfa.h"

Dfa::Dfa(){}

void Dfa::InsertarEstado(Estado* state){
  q_.insert(state);
}
void Dfa::InertarCadenaAlfabeto(string cadena){
  alfabeto_.insert(cadena);
}
void Dfa::SetInicial(string id_inicial){
  bool encontrado=false;
  for(auto i: q_){
    if(i->GetId()==id_inicial){
      inicial_=i;
      encontrado=true;
      break;
    }
  }
  if(encontrado == false){
    cout<<"Error el estado indicado no ha sido especificado anteriormente"<<endl;
    exit(0);
  }
}
Estado* Dfa::BuscarEstado(string id){
  Estado* tmp ;
  for(auto i:q_){
    if(i->GetId()==id){
      tmp=i;
    }
  }
  return tmp;
}

void Dfa::CrearTransicion(string origen,string cadena,string destino){
  Transicion* tmp;
  tmp = new Transicion(BuscarEstado(origen),cadena,BuscarEstado(destino));
  transiciones_.insert(tmp);
}
bool Dfa::BuscarTransicion(Estado* origen,string cadena){
  bool terminado=false;
  for(auto i : transiciones_){
    if(i->GetOrigen()->GetId()==origen->GetId() && i->GetCadena() == cadena ){
      terminado =true;
    }
  }
  return terminado;

}
void Dfa::CrearEstadoMuerte(){
  muerte_= new Estado("M");
  int numero_cadenas_alfabeto = alfabeto_.size();
  Transicion* transicion;
  for(auto i : alfabeto_){
    transicion = new Transicion (muerte_,i,muerte_);
    transiciones_.insert(transicion);
  }
  Transicion* aux;
  bool existe=false;
  for(auto i :q_){
    for(auto j : alfabeto_){

      if(BuscarTransicion(i,j) == false){
        aux = new Transicion(i,j,muerte_);
        transiciones_.insert(aux);
      }

    }
  }
}
void Dfa::AnalizarCadenas(string in,string out){

  fstream input = fstream(in,fstream::in);
  fstream output= fstream(out,fstream::out);
  bool reconocido = false;
  string linea ;
  while(!input.eof()){
    input>>linea;
    output<<linea<<" -- ";
    reconocido = Transitar(linea,inicial_);
    if(reconocido==true){
      output<<"Si"<<endl;
    }
    else
    {
      output<<"No"<<endl;
    }  
  }
}
Estado* Dfa::BuscarSiguienteEstado(Estado* origen,string cadena){
  Estado* destino;
  for(auto i : transiciones_){
    if(i->GetOrigen()->GetId()==origen->GetId() && i->GetCadena() == cadena ){
      destino =i->GetDestino();
      break;
    }
  }
  return destino;

}
bool Dfa::Transitar(string& cadena,Estado* actual){
  bool resultado = false;
  if(cadena.empty()==false){
    string cad (1,cadena.front());
    Estado* siguiente = BuscarSiguienteEstado(actual,cad);
    cadena.erase(0,1);
    resultado = Transitar(cadena,siguiente);
  }
  else{
    resultado = actual->GetAceptado();
  }
  return resultado;
}


void Dfa::SetEstadoAceptado(string id_estado){
    bool encontrado=false;
  for(auto i: q_){
    if(i->GetId()==id_estado){
      i->SetAceptado(true);
      encontrado=true;
      break;
    }
  }
  if(encontrado == false){
    cout<<"Error el estado indicado no ha sido especificado anteriormente"<<endl;
    exit(0);
  }
}