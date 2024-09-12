#ifndef DEPORTES_H
#define DEPORTES_H

#include <iostream>
#include <string>
using namespace std;

void imprimirDeporte(int indice);
void mostrarDeportes();
void mostrarDeportesIndividuales();
void listarDeportesPorCategoria(const char* categoria, const int* indices, int numIndices);
void mostrarDeportesColectivos();

#endif // DEPORTES_H