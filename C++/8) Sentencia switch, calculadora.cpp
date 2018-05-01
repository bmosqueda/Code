//Sentencia switch, calculadora de dos números
#include<iostream>

using namespace std;

int main()
{
	int num1;
	int num2;
	int opcion;

	cout << "Ingresa dos números: "; 		//Se ingresan los dos números
	cin >> num1 >> num2;

	cout << endl << "Selecciona una de las siguientes operaciones para tratar los núemeros ingresados:" << endl
		<< "1)Suma\n2)Resta\n3)Multiplicación\n4)División" << endl;			//Se muestra el menú de opciones

	cin >> opcion;		//Se lee la opción

	switch( opcion )	//Le indicamos a la instrucción que debe comparar en base a la variable opcion
	{
		case 1:		//Si opción es igual a 1 entra en este caso y ejecuta el código adentro
			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
			break;	//Indica que debe de salir de la instrucción porque sino también ejecutarías los siguientes casos
		case 2:
			cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
			break;
		case 3:
			cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;
			break;
		case 4:
			cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
			break;
		default:	//En caso de que no haya coincidido con ninguno de los casos va a mostrar el siguiente mensaje
			cout << "La opción ingresada no es correcta, intenta de nuevo" << endl;

		return 0;
	}
}