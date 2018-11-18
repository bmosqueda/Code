//Suma de dos números enteros
#include<iostream>

using namespace std;

int main()
{
	//Declaración de variables, su nombre no puede empezar con un número y es sensible a mayúsculas y minúsculas
	int numero1;	//Primer entero a sumar, asignar nombres significativos
	int numero2;	//Segundo entero a sumar
	int suma;		//Variable que almacenará la suma de los dos números

	cout << "Escriba un número entero: ";
	cin >> numero1;			//Lee números y caracteres hasta que se presiona ENTER
	cout << "Escriba otro número entero: ";
	cin >> numero2;

	suma = numero1 + numero2;		//operador de asignación

	cout << "La suma es " << suma << endl;	

	/*Los cálculos tmabién se pueden imprimir directamente, por loq ue podríamos haber escrito:
	cout << "La suma es " << numero1 + numero2 << endl;
	y nos mostraría lo mismo, primero resuleve la operación y luego lo muestra*/
	return 0;
}
