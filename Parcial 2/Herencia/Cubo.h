#pragma once
#include "Cuadrado.h"

class Cubo : public Cuadrado {
public:
    Cubo(const string& name, float l) : Cuadrado(name, l) {}
    virtual ~Cubo() {}

    float Volumen() const {
        return lado * lado * lado;
    }

    float Surface() const {
        return 6 * lado * lado;
    }
};
