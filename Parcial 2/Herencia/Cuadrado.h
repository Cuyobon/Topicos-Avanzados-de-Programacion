#pragma once
#include "Figura.h"

class Cuadrado : public Figura {
protected:
    float lado;

public:
    Cuadrado(const string& name, float l) : Figura(name), lado(l) {}
    virtual ~Cuadrado() {}

    float CalcularArea() const override {
        return lado * lado;
    }

    float CalcularPerimetro() const override {
        return 4 * lado;
    }

    float GetLado() const {
        return lado;
    }
};
