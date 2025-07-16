#pragma once
#include "Figura.h"
#include <cmath>

class FiguraNLados : public Figura {
protected:
    int nLados;
    float longitudLado;

public:
    FiguraNLados(const string& name, int n, float l) : Figura(name), nLados(n), longitudLado(l) {}
    virtual ~FiguraNLados() {}

    float CalcularPerimetro() const override {
        return nLados * longitudLado;
    }

    float CalcularArea() const override {
        float apotema = longitudLado / (2 * tan(3.14159265f / nLados));
        return (CalcularPerimetro() * apotema) / 2;
    }
};
