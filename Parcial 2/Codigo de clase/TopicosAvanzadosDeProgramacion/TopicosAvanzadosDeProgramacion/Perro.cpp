#include "Perro.h"


// Como esta es la definición de una función que está DENTRO del scope de la clase Perro, 
// entonces también cuenta como que está dentro del scope de la clase Perro.
string Perro::Sonido()
{
	// Sí se puede mandar a llamar porque Perro es una clase que hereda de Animal, y la función 
	// es protected.
	ItsAnimalProtected();

	// Esta de aquí, es privada de Animal, por lo tanto no la puedo usar mas que dentro del scope de Animal.
	// ItsAnimalPrivate(); 

	return "Guauf";
}

