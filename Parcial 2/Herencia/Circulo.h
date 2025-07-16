#pragma once
#include "Figura.h"
#include <cmath>

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(const string& name, float r) : Figura(name), radio(r) {}
    virtual ~Circulo() {}

    float CalcularArea() const override {
        return 3.14159265f * radio * radio;
    }

    float CalcularPerimetro() const override {
        return 2 * 3.14159265f * radio;
    }
};
