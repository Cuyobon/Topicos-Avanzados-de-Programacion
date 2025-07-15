#pragma once
#include "VirtualPura.h"



class DirectXWrapper :
    public VirtualPura
{

	bool InicializarAPIGrafica() override
	{
		// inicializas el sistema con las reglas de directX
		return true; // si todo salió bien, return true.
	}

	virtual bool ApagarAPIGrafica() override
	{
		// apagas el sistema con las reglas de directX
		return true; // si todo salió bien, return true.
	}

	virtual void RenderizarGeometria(/*aquí irían los parámetros de la geometría*/) override
	{
	}

};

