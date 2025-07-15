#pragma once

#include <iostream>
using namespace std;

class example
{
public:
	~example()
	{
		cout << "destructor de example" << endl;
	}
};

class example2
{
public:
	~example2()
	{
		cout << "destructor de example2" << endl;
	}
};

class ClaseEjemplo
{
	// por defecto, en un class todo es privado (funciones, variables, constructores, todo).
public:

	ClaseEjemplo()
	{
		posicionX = 0;
		posicionY = 0;
		alto = 0;
		ancho = 0;
		// punteroAFloat = new float(1.0);
	}

	~ClaseEjemplo() // no puede recibir parámetros.
	{
		// para limpiar valores que necesites, 
		// por ejemplo, hacer que sus punteros apunten a nullptr.
		// hacer delete a variables internas que ya no se vayan a usar.
		// imprimir mensajes.
		cout << "destruyendo objeto de claseEjemplo" << endl;

		// no la debe borrar (en esta ocasión al menos) porque él no la pidió, y puede ocasionar que se 
		// haga delete más de una vez a esta variable, lo que causa que el programa truene.
		// delete punteroACuentaBancaria; // ?

		// delete punteroAFloat;
		// en teoría no es necesario porque esta variable tipo claseEjemplo ya se va a morir, pero lo para que lo recuerden.
		// punteroAFloat = nullptr; 

		// cuando ya no hay más código se mandan a destruir todos los objetos internos de esta clase,
		// por ejemplo el example myExample que manda a llamar su destructor.
	}

	friend ostream& operator<<(ostream& os, const ClaseEjemplo& instance);

	void ImprimirPropiedades()
	{
		cout << "posX = " << posicionX << " posY = " << posicionY << " alto = " << alto << " ancho = " << ancho << endl;
	}


	// puede tener propiedades/miembros/atributos es decir, variables que guardan cosas.
	float posicionX;
	float posicionY;

	float alto;
	float ancho;

	float otracosa;

	// NOTA IMPORTANTE: Ahorita lo comenté porque estaba dando problemas al usarlo con el TArray.
	// float* punteroAFloat;

	int* punteroACuentaBancaria;

	// los destructores se llaman en el orden inverso del que se declararon en la clase.
	example2 myExample2;
	example myExample;


};

ostream& operator<<(ostream& os, const ClaseEjemplo& instance)
{
	os << "posX" << instance.posicionX << "pos Y" << instance.posicionY << endl;
	return os;
}