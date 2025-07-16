#pragma once
#include <string>
using namespace std;

class Figura {
protected:
    string nombre;

public:
    Figura(const string& name) : nombre(name) {}
    virtual ~Figura() {}

    virtual float CalcularArea() const = 0;
    virtual float CalcularPerimetro() const = 0;
    
    const string& ObtenerNombreDeFigura() const {
        return nombre;
    }
};
