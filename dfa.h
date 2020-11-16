/**
 * Enrique Manuel Pedroza Castillo
 * Alu: alu0100886351
 *
 * Clase Dfa
 *
 * Esta clase describe el funcionamiento de un automata DFA, y se usara para
 * poder reconocer las cadenas
 * si son aceptadas por el lenguaje descrito por el automata
*/
#ifndef DFA_H
#define DFA
#include "estado.h"
#include "transicion.h"
#include <set>
#include <fstream>
using namespace std;
class Dfa {
 public:
  Dfa();
  ~Dfa() {}

  void InsertarEstado(
      Estado*);  // Metodo para insertar un estado nuevo dentro del automata
  void InertarCadenaAlfabeto(string);  // Metodo para insertar un nuevo caracter
                                       // dentro del alfabeto del automata
  void SetInicial(
      string);  // Metodo para establecer el estado inicial del automata
  void SetEstadoAceptado(
      string);  // Metodo para modificar los estados para que sean de aceptacion
  void CrearTransicion(string, string, string);  // Metodo para crear una
                                                 // transicion en base a los
                                                 // nombres de los estados y la
                                                 // cadena de transicion
  void CrearEstadoMuerte();  // Metodo para detectar estados sin transiciones, y
                             // conducirlos a un estado de muerte
  bool BuscarTransicion(Estado*, string);  // metodo que dado el estado de
                                           // origen y la cadena de transicion
                                           // nos devuelve si existe o no una
                                           // transicion
  void AnalizarCadenas(string, string);    // Metodo que iniciara el proceso de
                                           // analisis de reconocimiento de
                                           // aceptacion de una cadena por parte
                                           // del leguaje que representa el
                                           // automata
  bool Transitar(string&,
                 Estado*);       // Metodo recursivo que se encarga de transitar
  Estado* BuscarEstado(string);  // Metodo que se encarga de devolver el puntero
                                 // a un estado dado el id del mismo
  Estado* BuscarSiguienteEstado(Estado*, string);  // Metodo que dado el nombre
                                                   // del estado de origen y una
                                                   // caracter de transicion y
                                                   // nos devuelve el estado
                                                   // destino

 private:
  set<Estado*> q_;
  set<string> alfabeto_;
  set<Transicion*> transiciones_;
  Estado* inicial_;
  Estado* muerte_;
};

#endif
