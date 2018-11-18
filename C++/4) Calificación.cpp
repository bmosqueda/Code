//Calificación de un estudiante
#include<iostream>

using namespace std;

int main()
{
	int calificacion;

	cout << "Ingresa la calificación por favor: "; cin >> calificacion;

	if( calificacion >= 60 )
		cout << "Aprobado" << endl;
	else
		cout << "Reprobado" << endl;

	//También se puede hacer de la siguiente forma y representa lo mismo
	// cout << ( calificacion >= 60 ? "Aprobado" : "Reprobado" );

	return 0;
}
