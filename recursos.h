#ifndef RECURSOS_H
#define RECURSOS_H

#include <iostream>
#include <string>
using namespace std;

// Funciones estéticas
void xy(const int x, const int y);
void color(const int c);

// Impresión de recursos
void logo(const int fila);
void podio(const int fila) ;
void medalla(const int fila) ;

// Impresión de recuadros
void recuadroConfirmacion ();
void recuadroFallido();
void recuadroLogin();

void gene();

// Titulos de menús
string tituloMostrarMedallero(const int fila);
string tituloCargaMedallas(const int fila);
string tituloMenuPrincipal(const int fila);
string tituloLogin(const int fila);

#endif // RECURSOS_H