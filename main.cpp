#include <iostream>
#include <string>
#include "menus.h"
using namespace std;

int main() {
	int intentos=0;
	system("mode con: cols=210 lines=55");
	/* pantallaCarga();
	if (pantallaPrincipal()) pantallaTransicion();
	limpiarPantalla(); */
	// pantallaLogin(intentos);
	menuPrincipal();
	return 0;
}
