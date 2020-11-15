
#ifndef DFA_H
#define DFA
#include "estado.h"
#include "transicion.h"
#include <set>
#include <fstream>
using namespace std;
class Dfa{

  public:
    Dfa();
    void InsertarEstado(Estado*);
    void InertarCadenaAlfabeto(string);
    void SetInicial(string);
    void SetEstadoAceptado(string);
    void CrearTransicion(string,string,string);
    Estado* BuscarEstado(string);
    void AnalizarCadenas(string, string);
    void CrearEstadoMuerte();
    bool BuscarTransicion(Estado*,string);
    bool Transitar(string&,Estado*);
    Estado* BuscarSiguienteEstado(Estado*,string);
    ~Dfa(){}

  private:
    set<Estado*> q_;
    set<string> alfabeto_;
    set<Transicion*> transiciones_;
    Estado* inicial_;
    Estado* muerte_;
};

#endif