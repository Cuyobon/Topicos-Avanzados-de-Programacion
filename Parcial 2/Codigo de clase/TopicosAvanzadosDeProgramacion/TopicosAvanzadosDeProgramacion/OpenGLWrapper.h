#pragma once
#include "VirtualPura.h"
class OpenGLWrapper :
    public VirtualPura
{
	bool InicializarAPIGrafica() override
	{
		// inicializas el sistema con las reglas de OpenGL
		return true; // si todo salió bien, return true.
	}

	virtual bool ApagarAPIGrafica() override
	{
		// apagas el sistema con las reglas de OpenGL
		return true; // si todo salió bien, return true.
	}

	virtual void RenderizarGeometria(/*aquí irían los parámetros de la geometría*/) override
	{
	}

};

