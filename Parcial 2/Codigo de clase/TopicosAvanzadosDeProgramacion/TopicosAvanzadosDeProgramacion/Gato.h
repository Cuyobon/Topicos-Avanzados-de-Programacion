#pragma once
#include "Animal.h"



class Gato : public Animal
{
public:
	// SI no haces override a la función virtual pura de Animal, entonces te va a decir que toda 
	// clase que herede de Animal que no le haya hecho override es Abstracta.
	int NumeroDePatas() override { return 4; };

	// virtual int NumeroDePatas() = 0;



};

