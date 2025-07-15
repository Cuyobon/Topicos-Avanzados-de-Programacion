#pragma once


#include <iostream>
using namespace std;

//bool InicializarAPIGrafica(string APIName)
//{
//	if (APIName == "DirectX")
//	{
//		// inicializas el sistema con las reglas de directX
//	}
//	else if (APIName == "OpenGL")
//	{
//		// inicializas el sistema con las reglas de OpenGL
//	}
//}


// Una clase virtual pura solamente tiene funciones virtuales puras.
// Para definir formas de interactuar con sistemas subyacentes que son muy distintos entre sí.
class VirtualPura
{
public:
	virtual bool InicializarAPIGrafica() = 0;

	virtual bool ApagarAPIGrafica() = 0;

	virtual void RenderizarGeometria(/*aquí irían los parámetros de la geometría*/) = 0;
};

