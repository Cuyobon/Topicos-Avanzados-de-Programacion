

class Alumno
{
public:
	int Progra, Dibujo, Legal;
};

// adrian: función que calcule, asigne e imprima la calificación de progra

void CalcularAsignarEImprimirCaliDeProgra(Alumno& alumno)
{
	// cálculos y demás
	alumno.Progra = 100;

}

// Juanito: función que calcule, asigne e imprima la calificación de Dibujo

void CalcularAsignarEImprimirCaliDeDibujo(Alumno& alumno)
{
	// cálculos y demás
}

int MainEjemplo()
{

	Alumno Pepito;


	CalcularAsignarEImprimirCaliDeProgra(Pepito);


	// Hola, soy adrian


	CalcularAsignarEImprimirCaliDeDibujo(Pepito);

	return 0;

}




