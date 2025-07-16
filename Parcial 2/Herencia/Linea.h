#pragma once
#include "Figura.h"
#include <numeric> // std::accumulate

class Linea : public Figura {
private:
    float* segmentos;
    int cantidad;

public:
    Linea(const string& name, const float* arregloSegmentos, int n) : Figura(name), cantidad(n) {
        segmentos = new float[cantidad];
        for (int i = 0; i < cantidad; ++i)
            segmentos[i] = arregloSegmentos[i];
    }

    virtual ~Linea() {
        delete[] segmentos;
    }

    float CalcularArea() const override {
        return 0.0f;
    }

    float CalcularPerimetro() const override {
        float suma = 0.0f;
        for (int i = 0; i < cantidad; ++i)
            suma += segmentos[i];
        return suma;
    }
};
