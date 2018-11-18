//Alcance, variable global
#include<iostream>

using namespace std;

int variableGlobal;		//Se le considera global porque no forma parte de ningún método en específico y puede usarse en cualquier parte del programa

void cuadrado( int numero )
{
	variableGlobal = numero * numero;
	cout << "Ahora número vale " << variableGlobal << " dentro del método cuadrado()" << endl;		//Método que modifica la varible global e imprime un mensaje
}

int main()
{
	int numero;
	cout << "Ingresa un valor para la varible global: ";
	cin >> numero;
	
	cuadrado( numero );		//Se manda llamar el método cuadrado que modificará la variable global e imprimirá su valor

	cout << "El valor de variableGlobal dentro de main es: " << variableGlobal << endl;		//Se vuelve a imprimir la variable global para comprobar que es la misma que se llamó en el método

	return 0;
}
