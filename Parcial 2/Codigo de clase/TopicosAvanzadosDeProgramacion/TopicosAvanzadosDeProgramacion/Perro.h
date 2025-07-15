#pragma once


#include "Animal.h" // necesito incluir el archivo donde está la clase de la cual se va a heredar.
#include "Fungi.h"

#include <iostream>
using namespace std;


class Perro : public Animal // , public Fungi
{
public:
	Perro() 
	{
		cout << " estoy en el constructor de un perro " << endl;
	}

	// IMPORTANTE, PONER VIRTUAL SI EL DESTRUCTOR DE LA CLASE PADRE VA A SER DISTINTO EN ALGUNA DE LAS HIJAS
	// No estoy 100% seguro de si debe llevar override, pero nos ayuda a asegurarnos de que el destructor de la 
	// clase padre SÍ esté marcado como virtual. Para propósitos de esta clase, SÍ pondremos este override en los destructores.
	~Perro() override
	{
		cout << " estoy en el destructor de un Perro " << endl;
	}

	// Sobreescritura -> Override
	// Es el mecanismo (la forma pues) en que una clase hija le dice a la clase padre que no va
	// a hacer exactamente lo mismo que ella en una función.

	// Sobre override:
	// 1) Permite que la función llamada a través de un puntero de la clase base sea la función de la clase específica, 
	// y no la de la clase base. (incluso en tiempo de ejecución al parecer)
	// 
	// 2) Si no pones virtual, ni override, la función de la clase hija OCULTA la función de la clase padre, lo que puede
	// causar comportamiento inesperado cuando se usan punteros o referencias de la clase base.
	// 
	// 3) Si la función tiene override, pero la de la clase padre no es virtual, el compilador marca error.
	// Eso es bueno para asegurar que no se haga override de funciones que no se deben modificar en clases hijas.
	// 
	// 4) Sin ese override, un typo o un cambio de parámetros en la función podría causar que sean dos funciones distintas:
	// por ejemplo Animal.Sonido() y Perro.Soniido() son dos funciones distintas. Usar override te aseguraría de que estás
	// invalidando la Sonido de Animal y no creando otra función llamada Soniido.



	virtual string Sonido() override; //  { ItsAnimal();  return "Guauf"; };

	int NumeroDePatas() override { return 4; };


};
