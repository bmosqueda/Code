#include <iostream>
#include <mysql/mysql.h>  // require libmysqlclient-dev
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  char option, temp;
  do {
    system("clear");
    cout << "Selecciona el tipo de servidor de Base de datos:" << endl
          << "1) MariaDB" << endl << "2) PostgreSQL" << endl;
    cin >> option;

    if(option != '1' && option != '2')
      cout << option << " no es una opción válida" << endl;
    cin.get(temp);

    cout << "Presiona ENTER para continuar" << endl;
    cin.get(temp);
  } while(option != '1' && option != '2');

  return 0;
}