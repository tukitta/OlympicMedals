#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
using namespace std;

//Declaracion de las funciones herramientas;
void bajar(int);
void centrar(int);
void limpiarPantalla();

// Pantallas
void pantallaLogin(int &);
void pantallaCarga();
bool pantallaPrincipal();
void pantallaTransicion(const int frames);
void pantallaDesarrollo();

// Declaracion de menus
void cargarMedallas(bool&);
void mostrarMedallero();
void menuPrincipal();

//declaracion funcion confirmacion de salida
bool pantallaConfirmacion();

#endif // MENUS_H