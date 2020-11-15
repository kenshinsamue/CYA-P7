#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <string>
using namespace std;
class Estado{

  public:
    Estado();
    Estado(string);
    string GetId();
    void SetAceptado(bool);
    bool GetAceptado();
    friend bool operator < (const Estado&,const Estado&);
    friend bool operator == (const Estado&,const Estado&);
  private:
    string id_;
    bool aceptado_;
};
#endif