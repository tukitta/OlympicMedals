#ifndef IDIOMA_H
#define IDIOMA_H

#include <iostream>
#include <string>
using namespace std;

void alternarIdioma();

string msgCarga();
string msgConfirmacion(const int mensaje);
string msgCR(); // CopytRight
string msgTip(); // Sugerencia para el usuario
string msgPrincipal(const int opcion);
string msgDesarrollo(const int fila);
string msgLogin(const int fila);
string msgLogo(const int fila);

#endif // IDIOMA_H