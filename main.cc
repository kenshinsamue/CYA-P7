
#include <fstream>
#include "dfa.h"
#include <string>
using namespace std;

// funcion para leer una linea del fichero con formato.dfa ignorando comentarios
string LeerLinea(fstream& input) {
  string linea;
  do {
    getline(input, linea);
  } while ((linea[0] == '/' && linea[1] == '/'));
  return linea;
}

// funcion para leer los estados del fichero .dfa e insertarlos dentro del
// automata
void LeerEstados(Dfa& automata, fstream& input) {
  string linea = LeerLinea(input);
  int n_estados = stoi(linea);
  int id_estado = 0;
  Estado* temporal;
  for (int i = 0; i < n_estados; i++) {
    temporal = new Estado(LeerLinea(input));
    automata.InsertarEstado(temporal);
  }
}

// funcion para leer las cadenas pertenecientes al alfabeto del automata del
// fichero
void LeerAlfabeto(Dfa& automata, fstream& input) {
  string linea = LeerLinea(input);
  int n_simbolos = stoi(linea);
  for (int i = 0; i < n_simbolos; i++) {
    automata.InertarCadenaAlfabeto(LeerLinea(input));
  }
}
// funcion para establecer el estado inicial en el atributo del automata
void EstablecerInicial(Dfa& automata, fstream& input) {
  automata.SetInicial(LeerLinea(input));
}
// funcion que lee los identificadores de los estados para saber si son o no de
// aceptacion
void LeerEstadosAceptacion(Dfa& automata, fstream& input) {
  string linea = LeerLinea(input);
  int n_aceptados = stoi(linea);
  for (int i = 0; i < n_aceptados; i++) {
    automata.SetEstadoAceptado(LeerLinea(input));
  }
}
// funcion que lee la descripcion de las transiciones del fichero
void LeerTransiciones(Dfa& automata, fstream& input) {
  string linea = LeerLinea(input);
  int n_transiciones = stoi(linea);
  string origen, cadena, destino;
  for (int i = 0; i < n_transiciones; i++) {
    input >> origen;
    input >> cadena;
    input >> destino;
    automata.CrearTransicion(origen, cadena, destino);
  }
}
// funcion para crear el automata segun la especificacion del fichero de entrada
Dfa CrearDfa(string infile) {
  fstream input("input.dfa", fstream::in);
  Dfa automata;
  LeerAlfabeto(automata, input);
  LeerEstados(automata, input);
  EstablecerInicial(automata, input);
  LeerEstadosAceptacion(automata, input);
  LeerTransiciones(automata, input);
  automata.CrearEstadoMuerte();
  input.close();
  return automata;
}

int main(int arcg, char* argv[]) {
  if (arcg == 4) {
    Dfa automata = CrearDfa(argv[1]);
    automata.AnalizarCadenas(argv[2], argv[3]);
  } else {
    cout << "error" << endl;
  }
}
