#include <iostream>
#include "Circulo.h"
#include "Cuadrado.h"
#include "Cubo.h"
#include "FiguraNLados.h"
#include "Linea.h"

int main() {
    Figura* f1 = new Circulo("Circulo", 5);
    Figura* f2 = new Cuadrado("Cuadrado", 4);
    Figura* f3 = new FiguraNLados("Pentagono", 5, 3);

    float segmentos[] = {2.0f, 3.5f, 1.0f, 4.5f};
    Figura* f4 = new Linea("Linea", segmentos, 4);

    cout << f1->ObtenerNombreDeFigura() << ": Area = " << f1->CalcularArea() << ", Perimetro = " << f1->CalcularPerimetro() << endl;
    cout << f2->ObtenerNombreDeFigura() << ": Area = " << f2->CalcularArea() << ", Perimetro = " << f2->CalcularPerimetro() << endl;
    cout << f3->ObtenerNombreDeFigura() << ": Area = " << f3->CalcularArea() << ", Perimetro = " << f3->CalcularPerimetro() << endl;
    cout << f4->ObtenerNombreDeFigura() << ": Area = " << f4->CalcularArea() << ", Perimetro = " << f4->CalcularPerimetro() << endl;

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    Cubo cubo("Cubo", 3);
    cout << "Cubo - Volumen: " << cubo.Volumen() << ", Superficie: " << cubo.Surface() << endl;

    return 0;
}
