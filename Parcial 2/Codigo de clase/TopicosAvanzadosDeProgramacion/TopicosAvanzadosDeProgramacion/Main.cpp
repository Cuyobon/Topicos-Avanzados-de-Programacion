// Tarea de: Juanito Pérez y Pepe Toño 

#include <iostream>

/*
es como si copiara y pegara el contenido del archivo/proyecto iostream en esta parte del código.

*/

using namespace std;

#include "ClaseEjemplo.h"
#include "Array.h"
#include "DynamicArray.h"
#include "Ejercicio1.h"
#include "LinkedList.h"
#include "SentinelLinkedList.h"
#include "Stack.h"
#include "BinarySearchTree.h"

#include "Perro.h"
#include "Gato.h"
#include "Chihuahua.h"

#include "DirectXWrapper.h"
#include "OpenGLWrapper.h"

#include "SQLDatabaseConnector.h"
#include "SQLLiteDatabaseConnector.h"

#define MY_ARRAY2_SIZE 20

#define MY_INT int myDefineInt = 2;

#define MY_MACRO int myMacro = 2; \
					int myOtherMacro;



// Declarar una variable es:
// tipo de dato + nombre de la variable + (; / = + valor de la variable;)

// tipo de dato + nombre de la variable + ;
// NOTA: en las variables de memoria estática se les asigna el valor por defecto del tipo de dato.
int myInt; // aquí no le hemos asignado un valor, entonces trae lo que se conoce como basura.


// tipo de dato + nombre de la variable + = valor de la variable;
int cinco = 5;
int cuatro = 4;

// Estructura de una función:
// tipo de dato (de retorno) + nombre de la función + () 
// tipo de dato (de retorno) + nombre de la función + (parámetro o parámetros) 








// estructura de una estructura:
// palabra reservada 'struct' + NombreDeLaEstructura + { + al menos una variable +  };
struct Cuadrilatero
{
	// por defecto todo es público (constructores y variables).

	// constructor de una struct
	Cuadrilatero()
	{
		// Constructor predeterminado o por defecto, que es el que no recibe ningún parámetro.
		cout << "se creo un cuadrilatero con el constructo por defecto." << endl;
		alto = -1;
		ancho = -1;
		color = -1;
		peso = -1;
	}

	Cuadrilatero(int in_alto, int in_ancho, int in_color, int in_peso)
	{
		// constructor con parámetros.
		alto = in_alto;
		ancho = in_ancho;
		color = in_color;
		peso = in_peso;
		cout << "se creo un cuadrilatero con el constructor de parámetros y sus valores son: " <<
			 " alto: " << alto << " ancho: " << ancho << " etc. " << endl;
	}

	~Cuadrilatero()
	{
		cout << "destruyendo cuadrilatero. " << endl;
	}

	// composición de estructuras

	int alto;
	int ancho;
	int color;
	int peso;
};

Cuadrilatero InicializarCuadrilatero(int alto, int ancho, int color, int peso)
{
	// 	Cuadrilatero newCuadrilatero es exactamente igual que Cuadrilatero newCuadrilatero = Cuadrilatero();
	Cuadrilatero newCuadrilatero = Cuadrilatero();
	newCuadrilatero.alto = alto;
	newCuadrilatero.ancho = ancho;
	newCuadrilatero.color = color;
	newCuadrilatero.peso = peso;
	return newCuadrilatero;
}


Cuadrilatero arrayDeCuadrilateros[4];

// Sobrecarga de funciones:
// Un nombre de función y tipo de retorno pero que puede recibir distintos parámetros
float Area(float lado)
{
	return lado * lado;
}

int Area(int lado)
{
	return lado * lado;
}

short Area(short lado)
{
	return lado * lado;
}

/* No puedes tener dos funciones que tengan mismo nombre y mismos parámetros pero distinto tipo de retorno
bool Area(float lado)
{
	return lado * lado;
}*/

float Area(float alto, float ancho)
{
	return alto * ancho;
}

float AreaConParametroPorDefecto(float alto, float ancho, bool esTriangulo = true)
{
	if (esTriangulo == true)
	{
		return alto * ancho / 2;
	}

	// si no, no es un triángulo y regresa simplemente alto * ancho
	return alto * ancho;
}

float Area(float param1, float param2, float param3)
{
	return param1 * param2 * param3;
}

// Parámetros que NO son por defecto deben ir antes que los que SÍ tienen valor por defecto,
// Por qué? porque si no causan confusiones terribles. Anteriormente NO era posible.
void NombreDePersona(int nombre, int apellidoPaterno, int apellidoMaterno, int segundoNombre = -1, int tercerNombre = -1)
{
	cout << "hola" << endl;
}


struct Triangulo
{
	int base;
	int altura;
};


struct Circulo
{
	int radio;
};

struct Coordenada
{
	int xPos;
	int yPos;
	int zPos;
	int myArray[10];
};



int Resta()
{
	// una variable DECLARADA dentro de unas llaves {}, únicamente existe dentro de dichas llaves.
	int dejarDeExistir = 5;
	cout << "hola";
	cout << " soy ";
	cout << " la funcion Resta";
	return cinco - cuatro;
}

// no puedes usar algo (variable, función, clase, estructura, etc.) antes de que esté declarado.
// OJO, no definido, pero sí debe estar declarado.
int Suma(); // aquí la DECLARAMOS pero la podemos DEFINIR en otra parte del código.

// La declaramos arriba del main pero la definimos debajo del main.
void ImprimirValor(int valorAImprimir);

int SumaConParametros(int a, int b); // a la pura declaración de función también se le conoce como prototipo de función.

// Función que recibe un arreglo de enteros e imprime el cuadrado de cada valor en él.
void ImprimirCuadradosDeValoresDeArreglo(int arrayAImprimir[], int size)
{
	for (int i = 0; i < size; i++)
	{
		// calculamos el valor cuadrado de cada valor del array
		int cuadrado = arrayAImprimir[i] * arrayAImprimir[i];
		// imprimimos el valor cuadrado:
		cout << "el cuadrado de: " << arrayAImprimir[i] << " es: " << cuadrado << endl;
	}
}

// función que imprima los cuadrados de los valores de un arreglo, pero también me los guarde o me los dé.
void ImprimirYGuardarCuadradosDeValoresDeArreglo(int arrayAImprimir[], int size)
{
	for (int i = 0; i < size; i++)
	{
		// calculamos el valor cuadrado de cada valor del array
		int cuadrado = arrayAImprimir[i] * arrayAImprimir[i];
		// imprimimos el valor cuadrado:
		cout << "el cuadrado de: " << arrayAImprimir[i] << " es: " << cuadrado << endl;
		arrayAImprimir[i] = cuadrado;
	}
}

int CambiarVariable(int myInt) // paso de parámetro POR VALOR
{
	myInt = 5;
	return myInt;
}

void CambiarVariablePorReferencia(int& myInt) // paso de parámetro POR REFERENCIA
{
	myInt = 5;
	//return myInt;
}

void ObtenerTiempo(int& hora, int& minuto, int& segundo)
{
	hora = 5;
	minuto = 55;
	segundo = 42;
}

bool ObtenerPerimetroYArea(int alto, int ancho, int& perimetro, int& area)
{
	// digamos que esta función solo es válida si alto y ancho son mayores que 0
	if (alto > 0 && ancho > 0)
	{
		perimetro = 2 * alto + 2 * ancho;
		area = alto * ancho;
		return true;
	}

	return false;
}


void checarAlgoYLuegoImprimir(bool esTrue)
{
	if (esTrue == true)
	{
		cout << "estoy imprimiendo" << endl;
	}
}

void ImprimirSinChecar()
{
	cout << "estoy imprimiendo" << endl;
}



void JuevesYAntesDeMediodia(const int dia, const int hora, const int minuto)
{
	// Si es jueves Y es antes del mediodía
	if (dia == 3 /*3 es jueves*/ && (hora < 12 || hora == 11 && minuto <= 59))
	{

	}

	// if(hora < 12)

	// 12:01 es después del mediodía
	// 12:00 es después del mediodía porque inmediatamente pasan instantes y ya es después del mediodía
	// 11:59 es antes del mediodía

	//     if (hora < 12 || (hora == 11 && minuto <= 59)) {

}

// EJEMPLO DE FUNCIÓN RECURSIVA
// regresa true cuando number == 0
bool llegarACero(int number)
{
	if (number < 0) // condición de terminación para evitar un stack overflow al recibir un número negativo.
		return false;

	if (number == 0) // condición de terminación. Es necesaria para que la función no se mande a llamar infinitamente.
		return true;

	return llegarACero(number - 1);
}

#define MY_NUMBER 3*15+2
#define MULTIPLY(a, b) a*b; cout << "hola, estoy en una macro con: " << a << endl;

void FuncionParametrosConstantes(const int i, const int* iPtr)
{
	// Si un parámetro es constante, no puede cambiar dentro de la función.
	// i++;

	// Lo mismo aplica para punteros a constantes, no se puede modificar.
	// *iPtr = 5;
}

// pasar parámetros como const evita que dentro de las funciones sufran cualquier tipo de cambio,
// ya sea la variable completa, o miembros de la variable.
// si tú NO vas a cambiar nada de un objeto en una llamada a función, ponlo const.
void ModificarInternamenteAnimal(const Animal &animal)
{
	// no te permite tampoco modificar ningúna variable miembro de los objetos que sean const.
	// animal.name = "Chamuco";
	 
	// una variable recibida como const SOLAMENTE puede mandar a llamar funciones const.
	cout << "mi perrita se llama: " << animal.NombreMasApellido("Gonzalez") << endl;
}


// Breakpoint -> break = romper ; point = punto; punto de quiebre
// Tarea de: Juanito Pérez y Pepe Toño 
int main()
{
	BinarySearchTree<float> myTree;
	myTree.AddWithAddRecursive(5);
	myTree.AddWithAddRecursive(3);
	myTree.AddWithAddRecursive(8);
	myTree.AddWithAddRecursive(2);
	myTree.AddWithAddRecursive(4);
	myTree.AddWithAddRecursive(7);
	myTree.AddWithAddRecursive(9);

	myTree.InOrderWithRecursive();

	myTree.AddWithAddRecursive(2.5f);

	myTree.InOrderWithRecursive();


	//map<key, value> o dictionary
	//map<int, string>
	// map[0] = Juan;
	// map[1] = Pepe;
	// map[2] = Maria;


	DynamicArray<int>* arrayToBeDeleted = new DynamicArray<int>();
	delete arrayToBeDeleted; // cuando se le hace delete a una variable de memoria dinámica, 
	// se manda a llamar el destructor de dicha variable, en este caso, el destructor de DynamicArray.

	{
		DynamicArray<int> staticArrayToBeDeleted = DynamicArray<int>();
	} // cuando se sale del scope de donde fue declarada una variable, también se manda a llamar
	// el destructor de dicha variable. 


	DynamicArray<int> dynamicThrowArray;
	dynamicThrowArray.Append(123);
	dynamicThrowArray.get(0); // este sí lo tiene, no debe dar excepción
	dynamicThrowArray.get(1); // este no lo tiene, es mayor que su count.
	dynamicThrowArray.get(-1); // este no es válido porque es menor que 0 y no hay índices negativos en c++.


	int diaEjemplo = 1;
	// a pesar de que diaEjemplo NO es const, dentro de la función JuevesYAntesDeMediodia no se le 
	// va a modificar, se le va a tratar como si fuera const.
	JuevesYAntesDeMediodia(diaEjemplo, 4, 12);


	const int ejemploDeMacro = MULTIPLY(3, 5);

	// const nos dice que el valor de esa variable NO puede cambiar JAMÁS.
	const int constante = 6;

	// constante = 1;

	// para apuntar a esa variable constante, se necesita que el puntero sea de tipo constante también.
	// un const pointer no te deja modificar los valores de la variable a la que apuntas.
	const int* ptrAConstante = &constante;

	int myIntNoConstante = 5;
	ptrAConstante = &myIntNoConstante;
	// (*ptrAConstante) = 6; // // un const pointer no te deja modificar los valores de la variable a la que apuntas.
	myIntNoConstante = 12; // esta variable sí se puede modificar, pero el puntero, como es constante, no la puede modificar.

	// Diferencias importantes entre #define y const es que #define va ANTES/DURANTE de compilar,
	// y const es cuando se le asigne valor por primera vez a esa variable, lo cual puede ser incluso en tiempo de ejecución.
	// const no se puede usar para #if #iddef #ifndef, etc. mientras que el #define sí.


	VirtualPura* APIGrafica = new DirectXWrapper();
	APIGrafica->InicializarAPIGrafica();

	APIGrafica->RenderizarGeometria();
	APIGrafica->ApagarAPIGrafica();

	// Patrón de Diseño Fachada (Facade), la parte con que interactúa el usuario siempre es la misma, 
	// independientemente de qué sistema se esté usando dentro de las funciones de la interfaz.
	DatabaseInterface* InterfazDeDatabase = new SQLDatabaseConnector();
	InterfazDeDatabase->ConectarConBaseDeDatos("Alumnos");
	InterfazDeDatabase->RealizarQuery("SELECT * from ALUMNOS WHERE ALGO");
	InterfazDeDatabase->DesconectarConBaseDeDatos("Alumnos");


	//Animal myAnimal = Animal();
	//cout << myAnimal.ObtenerNombre() << " su sonido es: " << myAnimal.Sonido() << endl;

	//Animal* myAnimalPtr = new Animal();
	//cout << myAnimal.ObtenerNombre() << " su sonido es: " << myAnimal.Sonido() << endl;


	Animal* myPerroPtr = new Perro();
	cout << myPerroPtr->ObtenerNombre() << " su sonido es: " << myPerroPtr->Sonido() << endl;
	delete myPerroPtr;

	Perro myPerro = Perro();
	cout << myPerro.ObtenerNombre() << " su sonido es: " << myPerro.Sonido() << endl;

	Gato myGato = Gato();
	cout << myGato.ObtenerNombre() << " su sonido es: " << myGato.Sonido() << endl;

	Chihuahua myChihuahua = Chihuahua();
	cout << myChihuahua.ObtenerNombre() << " su sonido es: " << myChihuahua.Sonido() << endl;

	// Como es pública, se puede mandar a llamar dentro de cualquier scope.
	myPerro.ItsAnimalPublic();


	Stack<string> stackExample;
	stackExample.Push("Paper Mario");
	stackExample.Push("Mario Odyssey");
	stackExample.Push("Mario Maker");
	stackExample.Push("Mario y Luigi");
	cout << stackExample.Pop() << endl;
	stackExample.Push("Pokemon");


	int stackCount = stackExample.Count();
	for (int i = 0; i < stackExample.Count(); i++)
	{
		cout << stackExample.Pop() << endl;
	}

	
	// llegarACero(-1); // EJEMPLO DE FUNCIÓN RECURSIVA.

	LinkedList<string> linkedList;
	linkedList.PushBack("Juan");
	linkedList.PushBack("Pedro");
	linkedList.PushBack("Luis");
	linkedList.PushBack("Maria");

	for (int i = 0; i < 100; i++)
	{
		linkedList.PushBack("vacio ");
	}

	linkedList.PopBack();
	linkedList.PopBack();
	linkedList.PopBack();
	linkedList.PopBack();
	linkedList.PopBack();


	SentinelLinkedList<string> sentinelList;
	sentinelList.PushBack("Pepe");
	sentinelList.PushBack("Nina");
	sentinelList.PushBack("Felipe");
	sentinelList.PushBack("Carlos");



	cerr << "hola, soy cerr " << endl;


#define PRUEBAS 0

#if PRUEBAS 1
	for (int i = 0; i < 10000000; i++)
	{

		cout << "estamos en modo pruebas" << endl;
	}
#endif



	//for (int i = 0; i < 10000000; i++)
	//{
	//	if (PRUEBAS == 1)
	//	{
	//		cout << "estamos en modo pruebas" << endl;
	//	}
	//}



	// if de una sola línea

	string dayString = "jueves";
	if (dayString == "jueves") //condición a checar
	{
		// fue verdadero
		cout << "es jueves" << endl;
	}
	else
	{
		// fue falso
		cout << "NO es jueves" << endl;
	}

	// condición a checar ? fue verdadero : fue falso ;
	dayString == "jueves" ? cout << "es jueves" << endl : cout << "NO es jueves" << endl;




	MainEjercicio1();


	DynamicArray<int> dynamicArray = DynamicArray<int>(64); // se inicia con DYNAMIC_ARRAY_DEFAULT_SIZE de capacidad, es decir 4
	for (int i = 0; i < 1000000; i++)
	{
		dynamicArray.Append(i);
	}

	// capacity-1 * cantidad de veces que hagas resize
	// n(n+1)/2
	// 9(9+1)/2
	// 9(10)/2
	// 90/2
	// 45

	// 100(101)/2
	// 10100/2
	// 5050

	//pair<int, int>
	//pair<float, char>
	//pair<string, int>
	//pair<ClaseEjemplo, Cuadrilatero>

	//Suma<int, float, float>(1, 2.6, 2.9);

	TArray<char> myTArray = TArray<char>(10);
	myTArray.InicializarACero();
	myTArray.data[6] = 'a';
	myTArray.ImprimirElementos();

	int arrayAImprimir[7];
	ImprimirArray<int>(arrayAImprimir, 7);

	char arrayAImprimirChar[7];
	ImprimirArray<char>(arrayAImprimirChar, 7);

	ClaseEjemplo arrayAImprimirClaseEjemplo[7];
	ImprimirArray<ClaseEjemplo>(arrayAImprimirClaseEjemplo, 7);


	TArray<ClaseEjemplo> myTArrayClaseEjemplo = TArray<ClaseEjemplo>(10);
	myTArrayClaseEjemplo.InicializarACero();
	// myTArrayClaseEjemplo.data[6] = ClaseEjemplo();
	myTArrayClaseEjemplo.ImprimirElementos();

	Array myArrayClass = Array(10);
	myArrayClass.InicializarACero();
	myArrayClass.data[5] = 5.5f;
	myArrayClass.ImprimirElementos();


	FloatArray myFloatArrayClass = FloatArray(10);
	myFloatArrayClass.InicializarACero();
	myFloatArrayClass.data[5] = 5.5f;
	myFloatArrayClass.ImprimirElementos();

	bool esTrue = false;
	if (esTrue)
	{
		ImprimirSinChecar();
	}

	checarAlgoYLuegoImprimir(esTrue);

	int ejemplo = 1; // [00000000 00000000 00000000 00000001]
	bool ejemploBool = true; // [00000001]


	// un puntero guarda en su valor una dirección de memoria
	int* punteroAEjemplo = &ejemplo;

	// el * atrás significa "accede a lo que hay dentro de este puntero"
	*punteroAEjemplo = *punteroAEjemplo + 1; // me da lo que hay dentro y después le asigna el valor de *punteroAEjemplo + 1
	cout << "valor de *punteroAEjemplo + 1: " << *punteroAEjemplo << endl;

	(*punteroAEjemplo)++; // me da lo que hay dentro Y luego le suma 1
	cout << "valor de (*punteroAEjemplo)++ : " << *punteroAEjemplo << endl;

	ejemplo;
	*(punteroAEjemplo++); // se mueve una dirección de memoria Y luego me da lo que hay dentro. // igual que *punteroAEjemplo++;
	cout << "valor de (*punteroAEjemplo)++ : " << *punteroAEjemplo << endl;


	punteroAEjemplo++; // se mueve una dirección de memoria
	cout << "valor de *punteroAEjemplo++ : " << *punteroAEjemplo << endl;


	int myArrayParaPuntero[4] = { 3, 6, 9, 12 };

	punteroAEjemplo = myArrayParaPuntero;
	for (int i = 0; i < 4; i++)
	{
		cout << punteroAEjemplo << " al cuadrado es: " << *punteroAEjemplo * *punteroAEjemplo << endl;
		punteroAEjemplo++;
	}

	int myZero = 0;
	int* punteroANada = nullptr;
	if (punteroANada == nullptr)
	{
		cout << "puntero a nada apuntar a nullptr" << endl;
	}



	int* punteroAMiDinero = new int(27);
	int* punteroAMiDineroDesdeCajero = punteroAMiDinero;
	int* punteroAMiDineroDesdeApp = punteroAMiDinero;
	int* punteroAMiDineroDesdeDebito = punteroAMiDinero;

	*punteroAMiDineroDesdeCajero = 12;



	delete punteroAMiDinero;
	// si van a borrar una variable en memoria dinámica, asegúrense de hacer que todos los punteros
	// que apuntaban a esa dirección de memoria ahora apunten a nullptr (o en su defecto a otra dirección válida).
	punteroAMiDinero = nullptr;
	// punteroAMiDineroDesdeApp = nullptr; // lo comento para que esta situación no-deseada siga sucediendo "*punteroAMiDineroDesdeApp == NULL"
	punteroAMiDineroDesdeCajero = nullptr;

	//if (*punteroAMiDinero == NULL) // NULL es cuando es 0 en el valor de la variable apuntada
	//{
	//	cout << "la dirección a la que apunta punteroAMiDinero tiene dentro un valor NULL" << endl;
	//}


	if (*punteroAMiDineroDesdeApp == NULL) // NULL es cuando es 0 en el valor de la variable apuntada
	{
		cout << "la dirección a la que apunta punteroAMiDineroDesdeApp tiene dentro un valor NULL" << endl;
	}
	// antes de usar un puntero tienes que tener cuidado de ver que sea válido
	*punteroAMiDineroDesdeApp = 100; // ESTO ESTÁ ESCRIBIENDO EN MEMORIA QUE YA LIBERAMOS, Y ESO ESTÁ MAL.

	// Si ya nadie más va a apuntar (o usar) esa variable de memoria dinámica a la que estás apuntando, ¡Bórrala!
	// si alguien todavía la va a usar, no le hagas delete.

	int* punteroAMemoriaDinamica = new int(5);
	// aquí causamos un memory leak porque dejamos de apuntar al 5 que pedimos arriba sin borrarlo primero
	punteroAMemoriaDinamica = new int(200);
	delete punteroAMemoriaDinamica;
	punteroAMemoriaDinamica = nullptr;
	if (punteroAMemoriaDinamica == nullptr)
	{
		cout << "puntero a memoria dinámica es igual a nullptr" << endl;
		if (punteroAMemoriaDinamica == NULL)
		{
			cout << "puntero a memoria dinámica además es igual a NULL" << endl;
		}
	}

	int* arrayAMemoriaDinamica;
	// la memoria dinámica nos da 1,000,000 sin problemas, mientras que la estática nos limita desde antes de los 800,000.
	arrayAMemoriaDinamica = new int[1000000]; 
	// delete &arrayAMemoriaDinamica[6]; // este tipo de cosas no te deja hacerlo :D
	delete[] arrayAMemoriaDinamica;

	int numeroDeElementos = 1000;
	// int myArrayDe27[numeroDeElementos]; // no puedes hacer esto con memoria estática.
	int* arrayDeTamanoDinamico = new int[numeroDeElementos];


	// 18 alumnos
	int numeroDeAlumnos = 18;
	int* calificacionesDeAlumnos = new int[numeroDeAlumnos];
	
	int* otroPuntero = new int(99);

	float* punteroFloat = new float(2.5);


	NombreDePersona(1, 2, 3);

	float areaCuadrado = Area(5);

	float areaRectangulo = Area(10, 11);

	float areaTriangulo = AreaConParametroPorDefecto(10, 11, false);

	float areaTresDimensiones = Area(11, 12, (float)13);

	cinco - myInt; // esto no sirve de nada porque 1) no se guarda el resultado en ninguna variable y 2) porque no se genera una salida/mensaje/print/log etc.

	// Guardamos el resultado en una variable, entonces sí sirve realizar esa resta.
	cout << "resultado de cinco menos myInt: " << cinco - myInt;


	// Generamos una salida/print/log del resultado de esa resta.
	// cout << "resultado: " << cinco - cuatro;

	// primero se terminan de ejecutar todas las funciones de una línea antes de que se ejecute esa línea en sí.
	cout << "resultado de Resta(): " << Resta();

	cout << " resultado de Suma(): " << Suma();

	cout << " imprimir 65: " << 65;


	int my65 = 65;
	cout << " imprimir 65: " << (char)my65 << endl;

	// GO-TO 76

	// se dice que una condición "se cumple" cuando el resultado de ella es Verdadero.
	// verdadero quiere decir que su valor en bits es 1 o más. La única forma en que algo es Falso
	// es cuando su valor en bits es = 0.

	// operadores de comparación
	// operador de igualdad == 
		// el hecho de que sean dos '==' lo hace distinto del operador de asignación =
	// operador de inigualdad (inequality) != y es para comparar si dos valores son distintos entre sí.

	// ifs aninados, 
	// múltiples condiciones por if
	// operador ternario.

	// un if nos dice cuáles líneas sí se van a ejecutar cuando se cumpla cierta condición.
	// my65 es igual a 64?
	if (my65 == 64 /*condición*/)
	{

		// líneas a ejecutarse cuando se cumple dicha condición.
		cout << " es verdadero: que my65 es igual a 64 " << endl;

	}
	else // else es QUÉ hacer cuando el IF de arriba no se cumplió.
	{
		cout << "ELSE. es verdadero: que my65 es distinto a 64 " << endl;
	}

	// my65 es distinto a 64?
	if (my65 != 64 /*condición*/)
	{
		// líneas a ejecutarse cuando se cumple dicha condición.
		cout << "if con != es verdadero: que my65 es distinto a 64 " << endl;

	}

	// si X no es igual a Y, entonces X es distinta a Y

	// 0 = lunes, 1 = martes, 2 = miércoles, 3, = jueves, 4 = viernes, 5 = sábado, 6 = domingo
	int day = 3;
	//if (day < 6)
	//{
	//	if (day < 5)
	//	{
	//		if (day < 4)
	//		{
	//			if (day < 3)
	//			{
	//				if (day < 2)
	//				{
	//					if (day < 1)
	//					{
	//						
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else
	//	{
	//		// es sábado
	//	}
	//}
	//else
	//{
	//	// es domingo
	//}

	int fecha = 15;

	// si es domingo O es sábado entonces...
	if (day == 6 || day == 5) // el OR da verdadero con que al menos una de las condiciones sea verdadera.
	{
		// es fin de semana
	}

	// si es domingo O es sábado Y hace buen clima
	// (day == 6 || day == 5 && haceBuenClima)
	if ((day == 6 || day == 5) /* && haceBuenClima*/) // si es fin de semana Y hace buen clima
	{
		// ir a comer a un lugar bonito
	}

	bool esFinDeSemana = day == 6 || day == 5;
	if (esFinDeSemana /*&& haceBuenClima*/)
	{
	}


	// el signo de exclamación '!' es el operador NOT, que invierte de verdadero a falso y de falso a verdadero.
	if (day == 4 || day == 3 || day == 2 || day == 1 || day == 0)
	{

	}

	// si es el día 0 o más y es el día 4 o menos
	// día 0 es lunes, y día 4 es viernes
	// si es el día lunes o más y es el día viernes o menos
	// lunes o más es lunes, martes, miércoles... domingo.
	// viernes o menos es viernes, jueves, miércoles, martes, y lunes
	if (day >= 0 && day <= 4)
	{

	}

	// si es viernes o antes.
	if (day <= 4)
	{
		// OJO: en esta condición, si alguien nos pasara un valor de day menor que 0, sí entraría en este if, pero no 
		// en el de if (day >= 0 && day <= 4)
	}

	// entonces aquí dice si NO es fin de semana
	if (!(day == 6 || day == 5))
	{
	}

	if (1 == 1)
		if (!(1 != 1))



			// 
			// algo así sería para hacer un XOR
			// if( (a && !b) || (b && !a) )


			if (day == 6)
			{
				// es domingo
			}
			else if (day == 5)
			{
				// es sábado
			}
			else if (day == 4 && fecha == 15)
			{
				// entonces hacer un picnic
				// nada
				// es jueves
				if (fecha == 15)
				{
					// feliz día del maestro
				}
				// nada
			}
			else if (day == 3)
			{
				// es domingo
			}
			else if (day == 2)
			{
				// es domingo
			}


	// si es día de clase && es día feríado
	// entonces no hay clase

	switch (day)
	{
	case 6:
	{
		// es domingo.
	}
	break;
	case 5:
		// es sábado.
		break;
	case 4:
		// es viernes.
		break;
	}


	// mi perro es igual a un chihuahua?
	// cuál es la variable que me dice cuál es mi perro == chihuahua

	day = 5;
	// For/While es un ciclo, ejecuta las líneas de código que estén dentro de dicho ciclo varias veces,
	// es decir, las líneas que estén entre las llaves {} del for/while.
	while (day != 5) // se ejecuta una y otra vez hasta que lo que esté dentro de los paréntesis deje de ser verdadero
	{
		// Si day fuera 0, entonces 0 != 5, y por lo tanto se sigue ejecutando el ciclo
		// si day = 4, 4 != 5, entonces se sigue ejecutando el ciclo.

		cout << "se está ejecutando el ciclo while" << endl;
		day = day + 1;
		cout << "ahora el día es : " << day << endl;
	}

	for (int counter = 0; counter < day; counter += 2)
	{
		cout << "for <  ahora el día es : " << counter << endl;
	}

	// Primero se ejecuta la declaración o asignación de variable, 
	// Después se checa la condición, si es verdad se entra a las llaves del for, y si no se las salta.
	// Al llegar a la llave de abajo, primero se ejecuta la operación a realizar y después se comprueba la condición 
	// para ver si el ciclo debe continuar.
	for (int counter = 0 /*declaración de variable*/; counter != day /*Condición*/; counter += 2 /*operación a realizar tras llegar a la llave inferior*/)
	{
		if (counter > day)
		{
			break; // continua la ejecución del programa a partir de la siguiente línea de código después del ciclo en el que estoy.
		}

		cout << "for != ahora el día es : " << counter << endl;
	}


	// Ejemplo que eleva números al cuadro usando for y arrays.

	// algoritmos de ordenamiento así por encimita.

	int myInteger;
	int myInteger2 = 2;

	int myArray[10]; // pura declaración, los N elementos tienen BASURA, es decir, nada más se pidió la memoria pero no se le asignó un valor. Nunca se debe usar un valor basura.

	cout << "myArray[1] = " << myArray[1] << endl;

	int myArray2[MY_ARRAY2_SIZE] = { 1, 2 }; // Si no se ponen los N elementos individualmente, solo asigna los X valores que se hayan puesto

	int myIndex = 12;
	// myArray2[10] = 99; // por qué este no compila? porque es constante
	myArray2[myIndex] = 99; // pero este sí compila? porque es una variable.

	// Si se va a leer o escribir en un array en una posición/índice que no pertenece al tamaño del array
	// ¿cuáles posiciones NO pertecen al tamaño de un array? todas las que sean mayores que el número de elementos de nuestro array.
	// por ejemplo, myArray2[10] todas las posiciones no-válidas serían de 10 en adelante.
	// Pero, a veces también podría ser necesario checar que no sean números negativos
	if (myIndex >= MY_ARRAY2_SIZE
		|| myIndex < 0)
	{
		// entonces es mayor que el tamaño de nuestro array, se sale de sus límites.
		// o es negativo, por lo cual también se sale de los límites.
	}


	int myError = myArray2[10];
	cout << "myArray2[10] = " << myArray2[10] << endl;

	// La dirección de memoria que nuestra el depurador es la del primer elemento del array en memoria.
	int myArray3[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // le asigna un valor a cada elemento individualmente.

	cout << "myArray3[1] = " << myArray3[1] << endl;

	ImprimirCuadradosDeValoresDeArreglo(myArray3, 10);

	int myArray4[4] = { 1, 2, 4, 8 };

	ImprimirCuadradosDeValoresDeArreglo(myArray4, 4);

	int valorACambiar = 100;
	int valorCambiado = CambiarVariable(valorACambiar);

	CambiarVariablePorReferencia(valorACambiar);

	int myHora, myMinuto, mySegundo;
	ObtenerTiempo(myHora, myMinuto, mySegundo);

	cout << "son las: " << myHora << ":" << myMinuto << " con: " << mySegundo << " segundos" << endl;

	ImprimirYGuardarCuadradosDeValoresDeArreglo(myArray4, 4);

	int perimetro = 0;
	int area = 0;
	if (ObtenerPerimetroYArea(1, 4, perimetro, area))
	{
		cout << "el perímetro es de: " << perimetro << " metros y el area es de " << area << " metros cuadrados" << endl;
	}
	else
	{
		cout << "el alto o el ancho de la figura es menor que 0" << endl;
	}


	// vamos a hacer un ciclo que nos dé el cuadrado de cada valor que haya en un array.
	//for (int i = 0; i < 10; i++)
	//{
	//	// calculamos el valor cuadrado de cada valor del array
	//	int cuadrado = myArray2[i] * myArray2[i];
	//	// imprimimos el valor cuadrado:
	//	cout << "el cuadrado de: " << myArray2[i] << " es: " << cuadrado << endl;
	//}


	//int counter = 0;
	//while (counter < 10)
	//{
	//	// calculamos el valor cuadrado de cada valor del array
	//	int cuadrado = myArray3[counter] * myArray3[counter];
	//	// imprimimos el valor cuadrado:
	//	cout << "el cuadrado de: " << myArray3[counter] << " es: " << cuadrado << endl;
	//	counter++;
	//}

	int arrayUnidimensional[10];

	int arrayBidimensionalSencillo[1][10];

	int arrayBidimensionalSencilloDeDos[2][10];


	int arrayBidimensional[10][10];

	// Una tabla de excel, por ejemplo


	// versión no-optimizada del for para imprimir un array bidimensional
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << arrayBidimensional[x][y] << endl;
		}
	}

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << arrayBidimensional[y][x] << endl;
			// [0][0], [0][1], [0][2], [][3], [][4]
			// [1][0], [1][1]
		}
	}

	// La clave para un ciclo que sea eficaz en memoria está en que el For más interno sea el 
	// que está en el corchete más a la derecha.
	for (int x = 0; x < 9; x++) // 9 filas
	{
		for (int y = 0; y < 10; y++) // 10 columnas
		{
			cout << arrayBidimensional[x][y] << endl;
			// [0][0], [0][1], [0][2], [][3], [][4]
			// [1][0], [1][1]
		}
	}

	int tridimensional[10][9][8];

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			for (int z = 0; z < 8; z++)
			{
				cout << tridimensional[x][y][z] << endl;
				// [0][0][0], [0][0][1], [0][0][2], [0][0][3], [0][0][4]
				// [1][0], [1][1]
			}
		}
	}

	/*
	* Lo siguiente sería igual en memoria: un arreglo de [10][9][8] y uno de [720]
	[10][9][8] = un array unidimensional de 10*9*8 = 720
	[720]
	ValorDelPrimerCorchete*TamañoDelSegundoCorchete + ValorDelSegundoCorchete*TamañoDelTercerCorchete + ValorDelTercerCorchete
	[8][8]*/



	int combinacionDeSeguroDe4[10][10][10][10]; // https://img.uline.com/is/image/uline/H-7801?$Mobile_Zoom$
	int AtaquesPokemon[16][16][16][16];
	int nacimiento[24][31][12][1]; // [20][15][10][1994]



	// Por el momento no tenemos el conocimiento de Punteros, que son los que nos permiten pedir arrays 
	// en tiempo de ejecución.
	// int myArray4[]; // por eso no podemos declararlo así.



	ImprimirValor(my65);


	ImprimirValor( SumaConParametros(2, 3) );



	// Para usar las structs simplemente las usamos como si fueran un tipo de datos común,
	// por ejemplo declarar una variable de "tipo de dato" estructura
	Cuadrilatero myCuadrilatero;

	// el operador '.' nos permite acceder a las variables internas de una variable de tipo de dato estructura.
	myCuadrilatero.alto = 5;
	myCuadrilatero.ancho = 3;
	myCuadrilatero.color = 1;

	Cuadrilatero cuadroChico;
	cuadroChico.alto = 1;
	cuadroChico.ancho = 1;
	cuadroChico.color = 2;
	cuadroChico.peso = 100;

	Cuadrilatero cuadroCreado = InicializarCuadrilatero(10, 5, 3, 20);
	Cuadrilatero cuadroCreado2 = InicializarCuadrilatero(10, 5, 4, 10);

	Cuadrilatero CuadroConstruido = Cuadrilatero(10, 5, 5, 100);

	ClaseEjemplo claseEjemplo;
	claseEjemplo.alto = 5;
	claseEjemplo.ancho = 22;
	claseEjemplo.ImprimirPropiedades();

	ClaseEjemplo otraClaseEjemplo;
	otraClaseEjemplo.ImprimirPropiedades();

	
	ClaseEjemplo* claseEjemploDinamica = new ClaseEjemplo();

	int* cuentaBancaria = new int(100);
	claseEjemploDinamica->punteroACuentaBancaria = cuentaBancaria;

	// cuando haces delete, primero se manda a llamar el destructor y después se libera la memoria.
	delete claseEjemploDinamica;
	delete cuentaBancaria;




	// Licuadora myLicuadora;
	// myLicuadora.MeterIngrediente(Jitomate);
	// myLicuadora.MeterIngrediente(Chile);
	// myLicuadora.Licuar();


	// Calificaciones myCalis;
	// myCalis.CalificarAlumno("Eduardo Calderon", "100");

	// ControlTV control;
	// control.SubirVolumen();
	// control.CambiarCanal(666);
	// control.ApagarTV(TV);

	int alto;
	int ancho;
	int color;

	int altoFigura1;
	int anchoFigura1;
	int colorFigura1;

	int altoFigura2;
	int anchoFigura2;
	int colorFigura3;


	// Memoria Aleatoria
	// Random Access Memory (RAM)

	// no puedes declarar variables void
	// void myVoid;
	// pero sí puedes tener void en funciones como tipo de retorno.

	return 0;
}

// esta es la definición de la función porque es la que tiene las llaves {}
int Suma()
{
	return cinco + cuatro;
	//goto 70
}

int SumaConParametros(int a, int b)
{
	 return a + b;
}

// una función void hace un procedimiento internamente y no le regresa nada a quien la llamó.
void ImprimirValor(int valorAImprimir )
{
	cout << valorAImprimir << endl;
	return; // a pesar de que no regresas ningún tipo de dato, el return te saca de la función inmediatamente.
	cout << "esto no se va a imprimir porque está después del return" << endl;
}

//void CuadradosDeArreglo()
//{
//	cout << my65;
//}

// cinco - cuatro; aquí no me deja porque no está dentro de un "scope", dentro de algo que puedes ejecutar






