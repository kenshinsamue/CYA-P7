#include "dfa.h"
// constructor por defecto
Dfa::Dfa() {}

// Metodo para insertar un estado nuevo dentro del automata
void Dfa::InsertarEstado(Estado* state) { q_.insert(state); }
// Metodo para insertar un nuevo caracter dentro del alfabeto del automata
void Dfa::InertarCadenaAlfabeto(string cadena) { alfabeto_.insert(cadena); }
// Metodo para establecer el estado inicial del automata
void Dfa::SetInicial(string id_inicial) {
  bool encontrado = false;
  for (auto i : q_) {
    if (i->GetId() == id_inicial) {
      inicial_ = i;
      encontrado = true;
      break;
    }
  }
  if (encontrado == false) {
    cout << "Error el estado indicado no ha sido especificado anteriormente"
         << endl;
    exit(0);
  }
}
// Metodo para modificar los estados para que sean de aceptacion
void Dfa::SetEstadoAceptado(string id_estado) {
  bool encontrado = false;
  for (auto i : q_) {
    if (i->GetId() == id_estado) {
      i->SetAceptado(true);
      encontrado = true;
      break;
    }
  }
  if (encontrado == false) {
    cout << "Error el estado indicado no ha sido especificado anteriormente"
         << endl;
    exit(0);
  }
}
// Metodo para crear una transicion en base a los nombres de los estados y la
// cadena de transicion
void Dfa::CrearTransicion(string origen, string cadena, string destino) {
  Transicion* tmp;
  tmp = new Transicion(BuscarEstado(origen), cadena, BuscarEstado(destino));
  transiciones_.insert(tmp);
}
// Metodo para detectar estados sin transiciones, y conducirlos a un estado de
// muerte
void Dfa::CrearEstadoMuerte() {
  muerte_ = new Estado("M");
  int numero_cadenas_alfabeto = alfabeto_.size();
  Transicion* transicion;
  for (auto i : alfabeto_) {
    transicion = new Transicion(muerte_, i, muerte_);
    transiciones_.insert(transicion);
  }
  Transicion* aux;
  bool existe = false;
  for (auto i : q_) {
    for (auto j : alfabeto_) {
      if (BuscarTransicion(i, j) == false) {
        aux = new Transicion(i, j, muerte_);
        transiciones_.insert(aux);
      }
    }
  }
}
// metodo que dado el estado de origen y la cadena de transicion nos devuelve si
// existe o no una transicion
bool Dfa::BuscarTransicion(Estado* origen, string cadena) {
  bool terminado = false;
  for (auto i : transiciones_) {
    if (i->GetOrigen()->GetId() == origen->GetId() &&
        i->GetCadena() == cadena) {
      terminado = true;
    }
  }
  return terminado;
}

// Metodo que iniciara el proceso de analisis de reconocimiento de aceptacion de
// una cadena por parte del leguaje que representa el automata
void Dfa::AnalizarCadenas(string in, string out) {
  fstream input = fstream(in, fstream::in);
  fstream output = fstream(out, fstream::out);
  bool reconocido = false;
  string linea;
  while (!input.eof()) {
    input >> linea;
    output << linea << " -- ";
    reconocido = Transitar(linea, inicial_);
    if (reconocido == true) {
      output << "Si" << endl;
    } else {
      output << "No" << endl;
    }
  }
}
// Metodo recursivo que se encarga de transitar
bool Dfa::Transitar(string& cadena, Estado* actual) {
  bool resultado = false;
  if (cadena.empty() == false) {
    string cad(1, cadena.front());
    Estado* siguiente = BuscarSiguienteEstado(actual, cad);
    cadena.erase(0, 1);
    resultado = Transitar(cadena, siguiente);
  } else {
    resultado = actual->GetAceptado();
  }
  return resultado;
}
// Metodo que se encarga de devolver el puntero a un estado dado el id del mismo
Estado* Dfa::BuscarEstado(string id) {
  Estado* tmp;
  for (auto i : q_) {
    if (i->GetId() == id) {
      tmp = i;
    }
  }
  return tmp;
}
// Metdo que dado el nombre del estado de origen y una caracter de transicion y
// nos devuelve el estado destino
Estado* Dfa::BuscarSiguienteEstado(Estado* origen, string cadena) {
  Estado* destino;
  for (auto i : transiciones_) {
    if (i->GetOrigen()->GetId() == origen->GetId() &&
        i->GetCadena() == cadena) {
      destino = i->GetDestino();
      break;
    }
  }
  return destino;
}
