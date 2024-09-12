#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#include "menus.h"

#define Lineas 6 //color de las lineas del logo
#define Cere  12 //color del cerebro del logo
#define Banda 76
#define meda 110
#define fondo 15
#define plata 119
#define oro 102
#define cobre 68

using namespace std;

void xy(const int x, const int y){ //Los gotoxys, funcionan, agregandole una coordenada x e y, como argumento en su llamada.
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos; dwPos.X = x; dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
	//Funcion de colores.
	void color(const int c){
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, c);
	}
		
// Sprite podio
void podio(const int fila) {
	color(7);
	switch(fila) {
		case 0: {  cout<<"                     ";color(oro);cout<<"@@@@@@@@@@@@@@@@@@@@@";color(fondo); break;}
		case 1: {  cout<<"                     ";color(oro);cout<<"@@";color(fondo);cout<<"                 ";color(oro);cout<<"@@";color(fondo); break;}
		case 2: {  cout<<"                     ";color(oro);cout<<"@@";color(fondo);cout<<"                 ";color(oro);cout<<"@@";color(fondo); break;}
		case 3: {  cout<<"                     ";color(oro);cout<<"@@";color(fondo);cout<<"        ";color(oro);cout<<"@@";color(fondo);cout<<"       ";color(oro);cout<<"@@";color(fondo); break;}
		case 4: {  cout<<"                     ";color(oro);cout<<"@@";color(fondo);cout<<"       ";color(oro);cout<<"@@@";color(fondo);cout<<"       ";color(oro);cout<<"@@";color(fondo);break; }
		case 5: {  cout<<"                     ";color(oro);cout<<"@@";color(fondo);cout<<"     ";color(oro);cout<<"@@";color(fondo);cout<<"  ";color(oro);cout<<"@";color(fondo);cout<<"       ";color(oro);cout<<"@@";color(fondo);break; }
		case 6: {  color(plata);cout<<"@@@@@@@@@@@@@@@@@@@@@@";color(oro);cout<<"@";color(fondo);cout<<"         ";color(oro);cout<<"@";color(fondo);cout<<"       ";color(oro);cout<<"@@";color(fondo);break; }
		case 7: {  color(plata);cout<<"@@";color(fondo);cout<<"                   ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"         ";color(oro);cout<<"@";color(fondo);cout<<"       ";color(oro);cout<<"@";color(cobre);cout<<"@@@@@@@@@@@@@@@@@@@@@@@";color(fondo);break; }
		case 8: {  color(plata);cout<<"@@";color(fondo);cout<<"       ";color(plata);cout<<"@@@@@";color(fondo);cout<<"       ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"         ";color(oro);cout<<"@";color(fondo);cout<<"       ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"                    ";color(cobre);cout<<"@@";color(fondo);break; }
		case 9: {  color(plata);cout<<"@@";color(fondo);cout<<"      ";color(plata);cout<<"@@";color(fondo);cout<<"   ";color(plata);cout<<"@@";color(fondo);cout<<"      ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"     ";color(oro);cout<<"@@@@@@@@";color(fondo);cout<<"    ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"        ";color(cobre);cout<<"@@@@";color(fondo);cout<<"        ";color(cobre);cout<<"@@";color(fondo);break; }
		case 10: { color(plata);cout<<"@@";color(fondo);cout<<"           ";color(plata);cout<<"@@";color(fondo);cout<<"      ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"                 ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"       ";color(cobre);cout<<"@@";color(fondo);cout<<"  ";color(cobre);cout<<"@@";color(fondo);cout<<"       ";color(cobre);cout<<"@@";color(fondo);break; }
		case 11: { color(plata);cout<<"@@";color(fondo);cout<<"         ";color(plata);cout<<"@@";color(fondo);cout<<"        ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"                 ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"          ";color(cobre);cout<<"@@";color(fondo);cout<<"        ";color(cobre);cout<<"@@";color(fondo);break; }
		case 12: { color(plata);cout<<"@@";color(fondo);cout<<"       ";color(plata);cout<<"@@";color(fondo);cout<<"          ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"                 ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"          ";color(cobre);cout<<"@@";color(fondo);cout<<"        ";color(cobre);cout<<"@@";color(fondo);break; }
		case 13: { color(plata);cout<<"@@";color(fondo);cout<<"     ";color(plata);cout<<"@@@";color(fondo);cout<<"           ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"                 ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"       ";color(cobre);cout<<"@@";color(fondo);cout<<"   ";color(cobre);cout<<"@";color(fondo);cout<<"       ";color(cobre);cout<<"@@";color(fondo);break;}
		case 14: { color(plata);cout<<"@@";color(fondo);cout<<"     ";color(plata);cout<<"@@@@@@@@";color(fondo);cout<<"      ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"                 ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"        ";color(cobre);cout<<"@@@@";color(fondo);cout<<"        ";color(cobre);cout<<"@@";color(fondo);break;}
		case 15: { color(plata);cout<<"@@";color(fondo);cout<<"                   ";color(plata);cout<<"@";color(oro);cout<<"@";color(fondo);cout<<"                 ";color(oro);cout<<"@";color(cobre);cout<<"@";color(fondo);cout<<"                    ";color(cobre);cout<<"@";color(cobre);cout<<"@";color(fondo);break;}
		case 16: { color(plata);cout<<"@@@@@@@@@@@@@@@@@@@@@@";color(oro);cout<<"@@@@@@@@@@@@@@@@@@@";color(cobre);cout<<"@@@@@@@@@@@@@@@@@@@@@@@";color(fondo); }
	}
}

// Titulo mostrar medallero
string tituloMostrarMedallero(const int fila) {
	color(7);
	switch (fila) {
		case 0: { return "             @@@@   @@@@  @@@@@@@   @@@@@@  @@@@@@@ @@@@@@    @@@@    @@@@@@      @@@@@ %@@@   @@@@@  @@@@@@@   @@@@@  @@@    @@@    @@@@@  @@@@@@@   @@@@@@                   "; }
		case 1: { return "             @@@@@ @@@@@  @@@  @@  @@@  @%    @@@   @@  @@@   @@@@@   @@@  @@     @@@@@ @@@@   @@     @@@  @@   @@ @@  @@@    @@@    @@@    @@@  @@  @@@  @@@                  "; }
		case 2: { return "             @@@ @ @ @@@  @@@  @@   @@@       @@@   @@@*@@   @@  @@   @@@ @@@     @@@@@ @@@@   @@@    @@@  @@@  @  @@  @@@    @@@    @@@    @@@-@@@  @@@  @@@                  "; }
		case 3: { return "             @@@ @@@ @@@  @@@  @@     @@@@    @@@   @@@ @@   @@  @@   @@@ @@      @@ @@@  @@   @@@@@  @@@  @@@  @  @@  @@@    @@@    @@@@@  @@@ @@   @@@  @@@                  "; }
		case 4: { return "             @@@ @@@ @@@  @@@  @@  @@@  @@%   @@@   @@  @@@  @@@@@@@  @@@  @@     @@  @@  @@   @@     @@@  @@@  @@@@@  @@@    @@@    @@@    @@@  @@  @@@  @@@                  "; }
		case 5: { return "             @@@  @  @@@  @@@  @@  @@@  @@#   @@@   @@  @@@ @@@  @@@  @@@  @@     @@  @@  @@   @@@    @@@  @@  @@@  @@ @@@@   @@@    @@@    @@@  @@  *@@  @@@                  "; }
		case 6: { return "             @@@  @  @@@    @@@      @@@@     @@@   @@  @@@ @@@  @@@  @@@  @@     @@  @@  @@   @@@@@  @@@@@@   @@   @@@ @@@@@@ @@@@@  @@@@@  @@@  @@    @@@@                    "; }
		default: return "";
	}
}
//cartel login
string tituloLogin(const int fila) {
	color(7);
	switch (fila) {
		case 0: {  return "     #----------------------------------------------------------------------------------------------#"; }
		case 1: {  return "     |                   @@@@        @@@@@@@       @@@@@@@     @@@@   @@@@   @@@@                   |"; }
		case 2: {  return "     |                   @@@@      @@@@@@@@@@@   @@@@@@@@@@@   @@@@   @@@@@  @@@@                   |"; }
		case 3: {  return "     |                   @@@@      @@@@  @@@@@   @@@@   @@@@   @@@@   @@@@@  @@@@                   |"; }
		case 4: {  return "     |                   @@@@      @@@@  @@@@@   @@@@   @@@@   @@@@   @@@@@@ @@@@                   |"; }
		case 5: {  return "     |                   @@@@      @@@@  @@@@@   @@@@          @@@@   @@@@@@ @@@@                   |"; }
		case 6: {  return "     |                   @@@@      @@@@  @@@@@   @@@@  @@@@@   @@@@   @@@@@@@@@@@                   |"; }
		case 7: {  return "     |                   @@@@      @@@@  @@@@@   @@@@  @@@@@   @@@@   @@@@ @@@@@@                   |"; }
		case 8: {  return "     |                   @@@@      @@@@  @@@@@   @@@@   @@@@   @@@@   @@@@ @@@@@@                   |"; }
		case 9: {  return "     |                   @@@@      @@@@  @@@@@   @@@@   @@@@   @@@@   @@@@  @@@@@                   |"; }
		case 10: { return "     |                   @@@@@@@@  @@@@@@@@@@@   @@@@@@@@@@@   @@@@   @@@@  @@@@@                   |"; }
		case 11: { return "     |                   @@@@@@@@    @@@@@@@       @@@@@ @@@   @@@@   @@@@   @@@@                   |"; }
		case 12: { return "     #----------------------------------------------------------------------------------------------#"; }
		default: return "";
	}
}
//cartel logo cerebro
void logo(const int fila) {
	color(12);
	switch (fila) {
		case 0:  {cout<<"                    @@@@@@@@                       @@@@@@@=                    ";break;}
		case 1:  {cout<<"               @@@@@@@:   @@@-                   -@@@   -@@@@@@@               ";break;}
		case 2:  {cout<<"             @@@@--:-@     @@@                   @@=    -@- :-@@@@             ";break;}
		case 3:  {cout<<"            @@@       @    -@@                  -@@     @       @@@            ";break;}
		case 4:  {cout<<"         =-@@@        *    %@@                   @@-   :-        @@@--         ";break;}
		case 5:  {cout<<"      @@@@@@@-            @@@-                   -@@@            @@@@@@@@      ";break;}
		case 6:  {cout<<"    -@@@    @-           ";color(Lineas);cout<<"-@@@@@@@@@@@@@@@@@@@@@@@@@@@-";color(Cere);cout<<"      :    -@   -@@@-    ";break;}
		case 7:  {cout<<"   @@@-     @@   @        -@@                     @@-        @   @@     -@@-   ";break;}
		case 8:  {cout<<"   @@=      :@=@@  ";color(Lineas);cout<<"-@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@";color(Cere);cout<<"   @@=@       @@@   ";break;}
		case 9:  {cout<<"   @@-       -@@         ";color(Lineas);cout<<":@@@  -@@                @@@";color(Cere);cout<<"          @@        -@@   ";break;}
		case 10: {cout<<"   @@@-        @@-         @@@";color(Lineas);cout<<"@@    @@           #";color(Cere);cout<<"@@         -@@      - -@@@   ";break;}
		case 11: {cout<<"   @@@@@@        @-        @@@";color(Lineas);cout<<"    :@@@@@@@@@@@@@@@@@";color(Cere);cout<<"        @@        @@@@@@   ";break;}
		case 12: {cout<<"  @@@   @         @        @@@    ";color(Lineas);cout<<" @@@@          @@-";color(Cere);cout<<"        @        -@   @@@  ";break;}
		case 13: {cout<<" @@@    +@         +       @@@              ";color(Lineas);cout<<"@@@@@@";color(Cere);cout<<"@@       @         @+    @@@ ";break;}
		case 14: {cout<<"@@@      -@@       .      @@@            ";color(Lineas);cout<<".@@";color(Cere);cout<<"      @@@              @@.      @@@";break;}
		case 15: {cout<<"@@*  -                  *@@@@           ";color(Lineas);cout<<"@@        @";color(Cere);cout<<"@@@-                  -  @@@";break;}
		case 16: {cout<<"@@-  @                @@. .@@@";color(Lineas);cout<<"@@@@@@@@@@         @";color(Cere);cout<<"@@: -@@                @  +@@";break;}
		case 17: {cout<<"@@*  @@            @@      -@@                   @@-      @@            @@  @@@";break;}
		case 18: {cout<<"@@@    -@@+@@#             @@@         ";color(Lineas);cout<<"@@@@@-**=";color(Cere);cout<<"-@@-             @@@@@@-    @@@";break;}
		case 19: {cout<<" @@@     @   @@@+          @@@        ";color(Lineas);cout<<" @@@@@    ";color(Cere);cout<<" @@@          =@@@   @     @@@ ";break;}
		case 20: {cout<<"  @@@--@-    @   @@%+@     @@@                   @@-    -@=#@@   @    *@--@@@  ";break;}
		case 21: {cout<<"   @@@@     @-             @@@";color(Lineas);cout<<"      @@@#";color(Cere);cout<<"         @@@             @@    .@@@@   ";break;}
		case 22: {cout<<"    @@-    @%          ";color(Lineas);cout<<"%@@@@@@@@@@@@@@@@         -@";color(Cere);cout<<"@@@@-          @@    @@@    ";break;}
		case 23: {cout<<"    @@-         @     @    @@";color(Lineas);cout<<"+      *@@   @@@@@@@";color(Cere);cout<<"@@@   :@     @         -@@    ";break;}
		case 24: {cout<<"    @--      -   -   @     --@";color(Lineas);cout<<"          @@       %";color(Cere);cout<<"@-     @   -          *-@    ";break;}
		case 25: {cout<<"    @@@-     @   @         -@@";color(Lineas);cout<<"        @@=  @@@-  ";color(Cere);cout<<"@@-         -   @     -@@     ";break;}
		case 26: {cout<<"     @@@-    @   %         ";color(Lineas);cout<<"@@@@@@@@@@@@   @@@@@@@@@-";color(Cere);cout<<"         %   @    -@@@     ";break;}
		case 27: {cout<<"      -@@@@-@-  @@#        @@";color(Lineas);cout<<"@             @@@   @";color(Cere);cout<<"@-        @@@  -@-@@@@-      ";break;}
		case 28: {cout<<"        -@@+@: -  @@       ";color(Lineas);cout<<"%-%                   @";color(Cere);cout<<"@@      -@*  *  %@@@.        ";break;}
		case 29: {cout<<"           @@@      -@@#   @";color(Lineas);cout<<"@@@@@@@@@@@@@@@@@@@@@@@";color(Cere);cout<<"@   @@@-      @@@           ";break;}
		case 30: {cout<<"          -@@#       @-   @@@                   @@@   @@       %@@-            ";break;}
		case 31: {cout<<"            -@@@#---@@@@   @@=                   =@@:  @@@@---@@@@             ";break;}
		case 32: {cout<<"               @@@@@@@@@- -@@                     @@@ .@@@@@@@@@               ";break;}
		case 33: {cout<<"                      @@@@@@                      -@@@@@@                      ";break;}
	}
}

// Titulo carga de medallas
string tituloCargaMedallas(const int fila) {
	switch (fila) {
		case 0: { return "      @@@@@@@   @@@@@    @@@@@@@   @@@@@@@   .@@@@@       @@@@@@@   @@@@@     @@@@@  @@@@   @@@@@  @@@@@@@@   @@@@@    @@@    @@@     @@@@@    @@@@@@@      ";}
		case 1: { return "     @@@  @@@   @@@@@@   @@@  @@@  @@@ -@@@  @@@@@@       @@  @@@+  @@@       @@@@@  @@@@   @@@    @@@  @@@   @@@@@*   @@@    @@@     @@#@@*  @@@  @@@      ";}
		case 2: { return "     @@@  @@@   @@ @@@   @@@ *@@   @@@       @@@ @@       @@  @@@*  @@@       @@@ @ @@@@@   @@@    @@@  @@@   @@ %@@   @@@    @@@     @@ @@@   @@@          ";}
		case 3: { return "     @@@        @@  @@   @@@@@@    @@@ @@@@  @@  @@@      @@  @@@*  @@@@@     @@@ @@@@ @@   @@@@@  @@@  @@@-  @@  @@   @@@    @@@    @@@  @@    @@@@@       ";}
		case 4: { return "     @@@  @@@  @@@  @@-  @@@  @@@  @@@  @@@  @@  @@@      @@  @@@*  @@@       @@@ @@@  @@   @@@    @@@  @@@- @@@  @@   @@@    @@@    @@@  @@       @@@      ";}
		case 5: { return "     @@@  @@@  @@@@@@@@  @@@  @@@  @@@  @@@  @@@@@@@      @@  @@@+  @@@       @@@  @@  @@   @@@    @@@  @@@  @@@@@@@@  @@@    @@@    @@@@@@@* +@@  @@@      ";}
		case 6: { return "      @@@@@@@  @@@  @@@  @@@  @@@  @@@@@@@@ @@@  @@@      @@@@@@@   @@@@@     @@@  @@  @@   @@@@@@ @@@@@@@@  @@@  @@@  @@@@@  @@@@@  @@@  @@@  @@@@@@@      ";}
		default: return "";
	}
}

// Titulo menu principal
string tituloMenuPrincipal(const int fila) {
	switch (fila) {
		case 0: { return "              @@@@  @@@@@  @@@@@@  @@@  @@@  @@@  @@@     @@@@@@    @@@@@@    @@@  @@@   @@    *@@@@    @@@  @@@@@@    @@@@@   :@@@                         ";}
		case 1: { return "              @@@@: @@@@@  @@@@@@  @@@  @@@  @@@  @@@     @@@@ @@@  @@@%@@@@  @@@  @@@@  @@  @@@@ @@@@ .@@@  @@@@@@@@  @@@@@   #@@@                         ";}
		case 2: { return "              @@@@@ @@@@@  @@@     @@@@ @@@  @@@  @@@     @@@@  @@  @@@  @@@  @@@  @@@@@ @@  @@@@  @@@ .@@@  @@@  @@@ @@@ @@@  #@@@                         ";}
		case 3: { return "              @@@@@@@@@@@  @@@@@   @@@@@@@@  @@@  @@@     @@@@ @@@  @@@@@@@   @@@  @@@@@@@@  @@@@      .@@@  @@@@@@@@ @@@ @@@  #@@@                         ";}
		case 4: { return "              @@*@@@@ @@@  @@@@%   @@@@@@@@  @@@  @@@     @@@@@@@   @@@*@@@-  @@@  @@@@@@@@  @@@@      .@@@  @@@@@@-  @@@ @@@  #@@@                         ";}
		case 5: { return "              @@* @@@ @@@  @@@     @@@ @@@@  @@@  @@@     @@@@      @@@  @@@  @@@  @@@ @@@@  @@@@  @@@ .@@@  @@@      @@@@@@@@ #@@@                         ";}
		case 6: { return "              @@* @@@ @@@  @@@@@@  @@@ @@@@  @@@% @@@     @@@@      @@@  @@@  @@@  @@@  @@@  @@@@ @@@@ .@@@  @@@     @@@@ @@@@ #@@@@@                       ";}
		case 7: { return "              @@* @@  @@@  @@@@@@  @@@  @@@    @@@@@      @@@@      @@@  @@@  @@@  @@@  @@@    @@@@@   .@@@  @@@     @@@-  @@@ #@@@@@                       ";}
	    default: return "";
	}
}

// Sprite medalla
void medalla(const int fila) {
	switch (fila) {
		case 0:  { cout<<"                           ";color(Banda);cout<<"                           ";color(fondo);break;}
		case 1:  { cout<<"                          ";color(Banda);cout<<"                             ";color(fondo);break;}
		case 2:  { cout<<"                         ";color(Banda);cout<<"       ";color(fondo);cout<<"                   ";color(Banda);cout<<"      ";color(fondo);break;}
		case 3:  { cout<<"                       ";color(Banda);cout<<"       ";color(fondo);cout<<"                      ";color(Banda);cout<<"     ";color(fondo);break;}
		case 4:  { cout<<"                      ";color(Banda);cout<<"       ";color(fondo);cout<<"                        ";color(Banda);cout<<"     ";color(fondo);break;}
		case 5:  { cout<<"                      ";color(Banda);cout<<"       ";color(fondo);cout<<"                        ";color(Banda);cout<<"      ";color(fondo);break;}
		case 6:  { cout<<"                       ";color(Banda);cout<<"       ";color(fondo);cout<<"                      ";color(Banda);cout<<"      ";color(fondo);break;}
		case 7:  { cout<<"                       ";color(Banda);cout<<"       ";color(fondo);cout<<"                    ";color(Banda);cout<<"       ";color(fondo);break;}
		case 8:  { cout<<"                        ";color(Banda);cout<<"       ";color(fondo);cout<<"                  ";color(Banda);cout<<"       ";color(fondo);break;}
		case 9:  { cout<<"                          ";color(Banda);cout<<"       ";color(fondo);cout<<"                ";color(Banda);cout<<"      ";color(fondo);break;}
		case 10: { cout<<"                           ";color(Banda);cout<<"       ";color(fondo);cout<<"             ";color(Banda);cout<<"       ";color(fondo);break;}
		case 11: { cout<<"                            ";color(Banda);cout<<"       ";color(fondo);cout<<"           ";color(Banda);cout<<"       ";color(fondo);break;}
		case 12: { cout<<"                            ";color(Banda);cout<<"                       ";color(fondo);break;}
		case 13: { cout<<"                              ";color(Banda);cout<<"  ";color(meda);cout<<"                ";color(Banda);cout<<"  ";color(fondo);break;}
		case 14: { cout<<"                              ";color(meda);cout<<"                    ";color(fondo);break;}
		case 15: { cout<<"                            ";color(meda);cout<<"                        ";color(fondo);break;}
		case 16: { cout<<"                           ";color(meda);cout<<"                           ";color(fondo);break;}
		case 17: { cout<<"                         ";color(meda);cout<<"                             ";color(fondo);break;}
		case 18: { cout<<"                        ";color(meda);cout<<"                                ";color(fondo);break;}
		case 19: { cout<<"                       ";color(meda);cout<<"                                 ";color(fondo);break;}
		case 20: { cout<<"                        ";color(meda);cout<<"                                ";color(fondo);break;}
		case 21: { cout<<"                         ";color(meda);cout<<"                              ";color(fondo);break;}
		case 22: { cout<<"                         ";color(meda);cout<<"                              ";color(fondo);break;}
		case 23: { cout<<"                          ";color(meda);cout<<"                            ";color(fondo);break;}
		case 24: { cout<<"                            ";color(meda);cout<<"                         ";color(fondo); break; }
		case 25: { cout<<"                             ";color(meda);cout<<"                      ";color(fondo); break; }
		case 26: { cout<<"                               ";color(meda);cout<<"                  ";color(fondo); break; }
		case 27: { cout<<"                                   ";color(meda);cout<<"            ";color(fondo); break; }
	}
}

//  Recuadro login
void recuadroLogin(){
	xy(80,24); color(128);cout<<"=========================================";
	xy(80,25); color(128);cout<<"                                         ";
	xy(80,26); color(128);cout<<"                                         ";
	xy(80,27); color(128);cout<<"                                         ";
	xy(80,29); color(128);cout<<"           ";
	xy(90,26); color(112);cout<<"                    ";
	xy(80,28); color(128);cout<<"           ";
	xy(90,29); color(112);cout<<"                    ";
	xy(110,27);color(128);cout<<"           ";
	xy(110,29);color(128);cout<<"           ";
	xy(80,30); color(128);cout<<"                                         ";
	xy(80,31); color(128);cout<<"=========================================";
}

// Recuadro intento fallido
void recuadroFallido(){
	for (int y = 24; y<32; y++) {
	  const int ancho = 41; xy(80,y);
	  if (y==24||y==31) cout << string(ancho,'=');
	  else cout << string(ancho,' ');
	}
}

// Recuadro confirmacion de salida
void recuadroConfirmacion (){
	xy(85,24);color(128);cout<<"=========================================";
	xy(85,25);color(128);cout<<"                                         ";
	xy(85,26);color(128);cout<<"                                         ";
	xy(85,27);color(128);cout<<"                                         ";
	xy(85,28);color(128);cout<<"                                         ";
	xy(85,29);color(128);cout<<"                                         ";
	xy(85,30);color(128);cout<<"                                         ";
	xy(95,29);color(112);cout<<"     ";
	xy(110,29);color(112);cout<<"     ";
	xy(85,30);color(128);cout<<"                                         ";
	xy(85,31);color(128);cout<<"=========================================";
}

void gene(){
	xy(90,22);cout<<"NO SE HA GENERADO COMPETENCIA"<<endl;
	xy(85,23);cout<<"(Ya has generado una competencia en esta sesion)"<<endl;
	Sleep(2000);
	limpiarPantalla();
}