//Utilización de una función para calcular la hipotenusa de un triángulo rectántgulo
//La palabra método quiere decir lo mismo que función
#include<iostream>
#include<cmath>

using namespace std;

double calcularHipotenusa( double catetoAdyacente, double catetoOpuesto )		//Convención lowerCamelCase para nombrar funciones y variables
{
	//Utilizamos sqrt de la librería cmath para sacar la rapiza cuadrada y pow para elevar al cuadrado
	return sqrt( ( pow( catetoAdyacente, 2 ) + pow( catetoOpuesto, 2 ) ) );  //hipotenusa = Raíz cuadrada del cateto dayacente al cuadrado más el cateto opuesto al cuadrado
}

int main()
{
	double catetoAdyacente, catetoOpuesto;

	cout << "Ingresa el cateto opuesto: ";
	cin >> catetoOpuesto;
	cout << "Ingresa el cateto adyacente: ";
	cin >> catetoAdyacente;

	double hipotenusa = calcularHipotenusa( catetoAdyacente, catetoOpuesto );

	cout << "La hipotenusa es igual a: " << hipotenusa << endl;

	//También podríamos haber impreso la hipotenusa directamente sin almacenarla en una variable
	//cout << "La hipotenusa es igual a: " << calcularHipotenusa( catetoOpuesto, catetoAdyacente ) << endl;

	return 0;
}
