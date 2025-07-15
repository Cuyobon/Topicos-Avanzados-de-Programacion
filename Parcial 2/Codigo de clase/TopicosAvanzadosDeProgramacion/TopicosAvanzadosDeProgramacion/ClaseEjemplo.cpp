

class Alumno
{
public:
	int Progra, Dibujo, Legal;
};


void CalcularAsignarEImprimirCaliDeProgra(Alumno& alumno)
{
	// cálculos y demás
	alumno.Progra = 100;

}

int MainEjemplo()
{

	Alumno Pepito;


	CalcularAsignarEImprimirCaliDeProgra(Pepito);


	// Hola, soy adrian


	return 0;

}


