#include <iostream>
using namespace std;

// ---------- Estructura Rect ----------
struct Rect {
    int x, y;       // Coordenadas de inicio
    int alto, ancho; // Dimensiones

    // 2.1) Constructor por defecto
    Rect() : x(0), y(0), alto(0), ancho(0) {}

    // 2.2) Constructor con todos los parámetros
    Rect(int xVal, int yVal, int altoVal, int anchoVal)
        : x(xVal), y(yVal), alto(altoVal), ancho(anchoVal) {}

    // 2.3) Constructor con solo alto y ancho, x y y en 0
    Rect(int altoVal, int anchoVal)
        : x(0), y(0), alto(altoVal), ancho(anchoVal) {}
};

// 2.4) Función para imprimir y validar un Rect
bool imprimirRectInfo(const Rect& r, int& x_final, int& y_final) {
    if (r.x < 0 || r.y < 0 || r.alto < 0 || r.ancho < 0) {
        cout << "Uno o más valores son negativos. Rect inválido." << endl;
        return false;
    }

    x_final = r.x + r.ancho;
    y_final = r.y + r.alto;

    cout << "Rectángulo desde (" << r.x << ", " << r.y << ")";
    cout << " hasta (" << x_final << ", " << y_final << ")" << endl;
    return true;
}

// 2.5) Función para verificar traslape de dos rectángulos
bool CheckOverlap(const Rect& r1, const Rect& r2) {
    // Si uno está completamente a la derecha, izquierda, arriba o abajo del otro, no hay traslape
    if (r1.x + r1.ancho <= r2.x || r2.x + r2.ancho <= r1.x ||
        r1.y + r1.alto <= r2.y || r2.y + r2.alto <= r1.y) {
        return false;
    }
    return true;
}

// --------- Función principal para pruebas ---------
int main() {
    // Pruebas con constructores
    Rect rect1; // todos 0
    Rect rect2(0, 0, 5, 5);
    Rect rect3(2, 2); // X=0, Y=0, Alto=2, Ancho=2

    int x_fin, y_fin;
    cout << "\nInfo rect2:\n";
    imprimirRectInfo(rect2, x_fin, y_fin);

    cout << "\nInfo rect3:\n";
    imprimirRectInfo(rect3, x_fin, y_fin);

    // Pruebas de traslape
    Rect rA(0, 0, 5, 5);
    Rect rB(6, 6, 5, 5);
    Rect rC(2, 2, 2, 2);
    Rect rD(1, 1, 7, 2);

    cout << "\nCheckOverlap entre rA y rB (esperado: false): " << boolalpha << CheckOverlap(rA, rB) << endl;
    cout << "CheckOverlap entre rA y rC (esperado: true): " << boolalpha << CheckOverlap(rA, rC) << endl;
    cout << "CheckOverlap entre rA y rD (esperado: true): " << boolalpha << CheckOverlap(rA, rD) << endl;

    return 0;
}
