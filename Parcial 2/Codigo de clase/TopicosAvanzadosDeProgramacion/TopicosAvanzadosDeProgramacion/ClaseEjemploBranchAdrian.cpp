

class Alumno
{
public:
	int Progra, Dibujo, Legal;
};

// adrian: función que calcule, asigne e imprima la calificación de progra


// Juanito: función que calcule, asigne e imprima la calificación de Dibujo

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


