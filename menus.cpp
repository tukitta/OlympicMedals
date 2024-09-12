#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#include "recursos.h"
#include "menus.h"
#include "paises.h"
#include "idioma.h"

#define Lineas 6 //color de las lineas del logo
#define Cere  12 //color del cerebro del logo
#define Banda 76
#define meda 110
#define fondo 15

using namespace std;

//ESTRUCTURAS
struct competidores {
	int paises[16];
	int tl;
};

void margensuperiorinferior(){
	int i=0;
	while(i<208){
		xy(i,0);cout<<"=";
		xy(i,48);cout<<"=";
		i++;}
}
	
void margenlaterales(){
	int x=0;
	while(x<48){
		xy(0,x);cout<<"#";
		xy(208,x);cout<<"#";
		x++;
	}
}

// Función para imprimir márgenes
void margenes() { margensuperiorinferior(); margenlaterales(); }

// Funcion para centrar el texto verticalmente
void bajar(int veces) { for (int i=0;i<veces;i++) cout << endl; }

//Funcion para centrar el texto horizontalmente
void centrar(int espacios) { string espacio = "             "; for (int i=0; i<espacios; i++) cout<< espacio; }

//Funcion para limpiar la pantalla
void limpiarPantalla() {
	system("CLS");
}

//barra de carga animacion
void pantallaCarga() {
	// system("mode con: cols=1920 lines=1080");
	double porcentaje = 0.0;
	while(porcentaje<100){
		if(porcentaje<25){color(4);}
		if(porcentaje>25 and porcentaje<50){color(6);}
		if(porcentaje>50 and porcentaje<75){color(14);}
		if(porcentaje>75) {color(10);}
		string barra;
		barra += string(porcentaje, '#');
		barra += string(100 - porcentaje, '-');
		bajar(25);
		centrar(4);
		cout << "[" << barra << "]" << endl;
		centrar(7);
		cout << msgCarga() << ": %" << fixed << setprecision(2) << porcentaje << endl;
		Sleep(70);
		limpiarPantalla();
		if (porcentaje == 0) {porcentaje ++;}
		porcentaje = porcentaje * 1.24;
	}
	color(fondo);
}

//pantalla animada de transicion
void pantallaTransicion(const int frames){
	for (int x=0 ; x<frames ; x++) {
		bajar(25); centrar(8);
		cout << msgCarga() << string(x%3, '.');
		Sleep(500);
		limpiarPantalla();
	}	
}

//pantallaprincipal
bool pantallaPrincipal(){
	//margenes();
	//Mostrar logo
	//system("mode con: cols=1920 lines=1080");
	for (int fila=0, y=2; fila<34; fila++, y++) { xy(65,y); logo(fila); }
	color(7);
	for (int fila=0, y=38 ; fila<4; fila++, y++) { xy(85,y); msgLogo(fila); }
	xy(180,47); cout << msgCR();
	bool banderaPresionado = false;
	//Ciclo para analizar si el boton SHIFT fue presionado con anterioridad, analizando cada 1 segundo
	while (!banderaPresionado) {
		Sleep(1000);
		if (GetAsyncKeyState(VK_SHIFT)) { limpiarPantalla(); banderaPresionado = true; }
		else banderaPresionado=false;
	}
	return banderaPresionado;
}

void vercompetencia(competidores comp[]){
	for (int i = 0; i<87;i++){
		color(4);cout<<"Competencia: "<<i<<endl;color(fondo);
		for (int j = 0; j<comp[i].tl; j++){
			color(7);imprimirPais(comp[i].paises[j]+1);color(fondo);
		}
		//system("pause");
		//Sleep(2000);
	}
}

void gener(bool& Ing, competidores competencia[]){
	srand(time(NULL));
	pantallaTransicion(6);
	for(int i = 0;i<87;i++){
		competencia[i].tl = (rand()%13)+4;
		//color(7);cout<<"Competencia"<<i<<": "; color(6);cout<<competencia[i].tl<<endl;color(fondo);
		//cout<<competencia[i].tl<<endl;
		//Sleep(1000);
		int partic[16];
		int t = 0;
		for(int j = 0;j<competencia[i].tl;j++){
			int a = (rand()%195)+1;
			//cout<<a<<endl;
			//Sleep(1000);
			int c = 0;
			bool agreg = false;
			while(c<t && a!=partic[c]){
				c++;
				if(c==t){
					partic[t] = a;
					agreg = true;
					t++;
				}
			}
			if (t==0){
				partic[t] = a;
				t++;
				agreg = true;
			}
			if (agreg){
				competencia[i].paises[j] = a;
				//color(4);cout<<j<<" : "<<competencia[i].paises[j]<<endl;color(fondo);
				//color(2);cout<<"Agregado"<<endl;color(fondo);
			} else {
				j--;
			}
		}
		//system("pause");
	}
	Ing = true;
	vercompetencia(competencia);
}
//Menu Principal
						
//void cambiavector(int opsn[]){int opns[4] = {112, 5, 5,fondo};}
void menuPrincipal() {
	bool ejecutar=false, auxiliar=false, ing = false, ing1 = false, aux = false;
	int x = 90, ultima = 0, depor_medallas[87][3];
	competidores competencia[87];
	do {
		// margenes();
		for (int fila=0, y=30; fila<17; fila++, y++) { xy(70,y); podio(fila); }
		for (int fila=0, y=1;  fila<8;  fila++, y++) { xy(30,y); cout << tituloMenuPrincipal(fila) << endl; }
		int opcion = ultima, opns[5] = {112, 8, 8, fondo, fondo};
		if (ing) { opns[1]=fondo; if (ing1) opns[2]=fondo; }
		while (!(GetAsyncKeyState(VK_SPACE))) {
			xy(x,20);color(6);cout << msgPrincipal(1) << endl;color(6);
			xy(x,21);cout << msgPrincipal(2) <<endl;
			xy(x,22);color(opns[0]);cout << msgPrincipal(3); color(fondo);
			xy(x,23);color(opns[1]);cout << msgPrincipal(4); color(fondo);
			xy(x,24);color(opns[2]);cout << msgPrincipal(5); color(fondo);
			xy(x,25);color(opns[3]);cout << msgPrincipal(6); color(fondo);
			xy(x,26);color(opns[4]);cout << msgPrincipal(7); color(fondo);
			xy(65,27);color(fondo);cout << msgTip();
			xy(x,28);color(0);system("pause");
			
			if (!ing) {
				if (opcion>=0 && opcion<4 && GetAsyncKeyState(VK_DOWN)) {
					opns[opcion] = fondo;
					if (!opcion) opcion+=3;
					else opcion++;
					opns[opcion] = 112;
				}
				if (opcion<=5 && GetAsyncKeyState(VK_UP)) { 
					opns[opcion] = fondo; 
					if (opcion==3) opcion-=3;
					else opcion--;
					opns[opcion] = 112;
				}
			} else {
				if (ing1) {
					if (opcion<3 && GetAsyncKeyState(VK_DOWN)) {
						opns[opcion] = fondo;
						opcion++;
						opns[opcion] = 112;
					}
					if (opcion>0 && GetAsyncKeyState(VK_UP)) { opns[opcion] = fondo; opcion--; opns[opcion] = 112; }
				} else {
					if (opcion>4 && GetAsyncKeyState(VK_DOWN)) {
						opns[opcion] = fondo;
						if (opcion==1) opcion+=2;
						else opcion++;
						opns[opcion] = 112;
					}
					if (opcion>0 && GetAsyncKeyState(VK_UP)) {
						opns[opcion] = fondo;
						if (opcion==3) opcion-=2;
						else opcion--;
						opns[opcion] = 112;
					}
				}
			}
		}
		
		
		
		switch (opcion) {
			//falta finalizar la funcion 
			case 0:{ xy(x,22);color(39);cout << msgPrincipal(3);Sleep(500);ejecutar=true;color(fondo);limpiarPantalla();if(!ing){opcion=0;gener(ing, competencia);}else{gene();}break;}
			case 1:{ xy(x,23);color(39);cout << msgPrincipal(4);Sleep(500);ejecutar=true;color(fondo);limpiarPantalla();if(ing){opcion=1;cargarMedallas(ing1);}else{gene();}break;}
			case 2:{ xy(x,24);color(39);cout << msgPrincipal(5);Sleep(500);ejecutar=true;color(fondo);limpiarPantalla();if(ing1){opcion=2;mostrarMedallero();}else{gene();}break;}
			case 3:{ xy(x,25);color(39);cout << msgPrincipal(6);Sleep(500);color(fondo);alternarIdioma();limpiarPantalla();opcion=3;break;}
			case 4:{ xy(x,26);color(39);cout << msgPrincipal(7);Sleep(500);color(fondo);opcion=4;ejecutar=true;
					if(pantallaConfirmacion()){limpiarPantalla();auxiliar=true;}break;}
		}
		ejecutar=false;
	} while (!(ejecutar||auxiliar));
}

//Generador de competenecias
//void pantallaCompetenciaGenerada() {

//}

//Pantalla desarrollo
void pantallaDesarrollo() {
	xy(90,22); cout << msgDesarrollo(1) << endl;
	xy(85,23); cout << msgDesarrollo(2) << endl;
	Sleep(2000); limpiarPantalla();
}

// Confirmación de salida
bool pantallaConfirmacion() {
	limpiarPantalla();
	margensuperiorinferior();
	margenlaterales();
	int opcion = 0, opns[2] = {79, 112};
	while (!(GetAsyncKeyState(VK_SPACE))) {
		recuadroConfirmacion();
		xy(85, 26); color(128); cout << msgConfirmacion(1) << endl;
		xy(95, 29); color(opns[0]); cout << msgConfirmacion(2) << endl;
		xy(110,29); color(opns[1]); cout << msgConfirmacion(3) << endl;
		xy(95, 32); color(0); system("pause");
		if (!opcion && GetAsyncKeyState(VK_RIGHT)) {
			opns[opcion] = 112;
			++opcion;
			opns[opcion] = 79;
		}
		if (opcion && GetAsyncKeyState(VK_LEFT)) {
			opns[opcion] = 112;
			--opcion;
			opns[opcion] = 47;
		}
	}

	switch (opcion) {
		case 0: { xy(95, 29); color(160); cout << msgConfirmacion(2); Sleep(500); color(fondo); limpiarPantalla(); return false; }
		case 1: { xy(110, 29); color(160); cout << msgConfirmacion(3); Sleep(500); color(fondo); limpiarPantalla(); return true; }
		default: return false;
	}
}

//CARGA DE MEDALLAS POR DEPORTE INDIVIDUAL
void deporInd(){
	
}

//menu de cargar medallas
void cargarMedallas(bool& Ing1){
	bool menuPrincipal=false;
	while(!menuPrincipal){
		margensuperiorinferior();
		margenlaterales();
		int c=30;
		for (int l=0; l < 17; l++){xy(70,c);podio(l);c++;}
		//Muestra el cartel por pantalla
		
		int e=1;
		for (int i=0; i < 10; i++) {xy(30,e);cout <<tituloCargaMedallas(i) << endl;e++;}
		
		int opcion1 = 0;
		int opns[3] = {112, fondo, fondo};
		
		while(!(GetAsyncKeyState(VK_SPACE))){
			
			xy(85,14);color(6);cout <<"   SUBMENU CARGA DE MEDALLAS POR DEPORTE   ";
			xy(90,15);cout <<"==========================";
			xy(90,16);color(opns[0]);cout <<"1. Carga por Deporte Individual";color(fondo);
			xy(90,17);color(opns[1]);cout<<"2. Carga por Deporte Colectivo";color(fondo);
			xy(90,18);color(opns[2]);cout <<"X. Volver al menu principal";color(fondo);
			xy(90,19);cout <<"Por favor elija una opcion";
			xy(75,20);color(fondo);cout<<"Desplazarse usando las flechas del teclado y presionar SPACE para seleccionar.";
			xy(90,21);color(0);system("pause");
			
			if((GetAsyncKeyState(VK_DOWN))and(opcion1<2)){
				opns[opcion1] = fondo;
				opcion1++;
				opns[opcion1] = 112;
			}
			if ((GetAsyncKeyState(VK_UP))and(opcion1>0)){
				opns[opcion1] = fondo;
				opcion1--;
				opns[opcion1] = 112;
			}
		}
		
		switch (opcion1+1){
		case 1:{xy(90,16);color(39);cout <<"3. Carga por Deporte Individual";Sleep(500);color(fondo);limpiarPantalla(); pantallaDesarrollo();limpiarPantalla();break;}
		case 2:{xy(90,17);color(39);cout <<"4. Carga por Deporte Colectivo";Sleep(500);color(fondo);limpiarPantalla(); pantallaDesarrollo();limpiarPantalla();break;}
		case 3:{xy(90,18);color(39);cout <<"X. Volver al menu principal";Sleep(500);color(fondo);menuPrincipal=true;limpiarPantalla();Ing1 = true;return;}
		}
	}
}

//Menu mostrar medallero
void mostrarMedallero(){
	bool menuPrincipal=false;
	while(!menuPrincipal){
		//llamada a margenes
		margensuperiorinferior();
		margenlaterales();
		int e=1;
		int j=30;
		for (int l=0; l < 17; l++){xy(70,j);podio(l);j++;}
		color(7);
		for (int i=0; i < 7; i++){xy(20,e);cout<< tituloMostrarMedallero(i) << endl;e++;}
		int opcion1 = 0;
		int opns[4] = {112, fondo, fondo,fondo};
		while(!(GetAsyncKeyState(VK_SPACE))){
			xy(90,14);color(6);cout <<"   MENU MOSTRAR MEDALLERO"<<endl;
			xy(90,15);cout <<"=========================="<<endl;
			xy(90,16);color(opns[0]);cout <<"1. Medallero por Pais"<<endl;color(fondo);
			xy(90,17);color(opns[1]);cout <<"2. Medallero por Deporte"<<endl;color(fondo);
			xy(90,18);color(opns[2]);cout <<"3. Top medallero"<<endl;color(fondo);
			xy(90,19);color(opns[3]);cout << "X. Volver al menu principal"<<endl;color(fondo);
			xy(90,20);cout << "Por favor elija una opcion"<<endl;
			xy(65,21);color(fondo);cout<<"Desplazarse usando las flechas del teclado y presionar SPACE para seleccionar.";
			xy(90,22);color(0);system("pause");color(fondo);
			
			if((GetAsyncKeyState(VK_DOWN))and(opcion1<3)){
				opns[opcion1] = fondo;
				opcion1++;
				opns[opcion1] = 112;
			}
			if ((GetAsyncKeyState(VK_UP))and(opcion1>0)){
				opns[opcion1] = fondo;
				opcion1--;
				opns[opcion1] = 112;
			}
		}
		
		
		switch (opcion1+1){
		case 1:{xy(90,16);color(39);cout <<"1. Medallero por Pais";Sleep(500);color(fondo);limpiarPantalla();pantallaDesarrollo();limpiarPantalla();break;}
		case 2:{xy(90,17);color(39);cout <<"2. Medallero por Deporte";Sleep(500);color(fondo);limpiarPantalla(); pantallaDesarrollo();limpiarPantalla();break;}
		case 3:{xy(90,18);color(39);cout <<"3. Top medallero";Sleep(500);color(fondo);limpiarPantalla(); pantallaDesarrollo();limpiarPantalla();break;}
		case 4:{xy(90,19);color(39);cout << "X. Volver al menu principal";color(fondo);Sleep(200);limpiarPantalla();menuPrincipal=true;return;}
		}}
}
										
//Contraseña
bool Contr(int verd){
	string c[20] = { "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x"};
	char v;
	int cont = 0;
	int i = 0;
	bool verf = false;
	while(i<20){
		xy(i+90,29);
		v = getch();
		if ((v>='0')and(v<='9')){
			c[i] = to_string(v-48);
			cont++;
			xy(i+90,29);cout<<v;
			Sleep(500);
			xy(i+90,29);cout<<"*";
			i++;
		}
		if (v == '\r'){
			c[i] = "x";
			i = 20; 
		}
		if (v == '\b' and i>0){
			c[i-1] = "x";
			i--;
			cont--;
			xy(i+90,29);color(112);cout<<" ";
			
		}
	}
	verf=true;
	
	string contr = "";
	for (int n = 0; n < cont; n++){
		contr = contr + c[n];
	}
	if(to_string(verd) == contr){
		verf = true;
	}
	return verf;
}

//Pantalla login
void pantallaLogin (int & intentos){
	bool inten = false;
	while(!inten){
		margensuperiorinferior();
		margenlaterales();
		//Declaracion de las variables
		int Contrasena;
		int c1, c2, c3;
		int Usuario;
		int numeroauxiliar;
		int c=15;
		int d=15;
		int e=1;
		
		//Mostrar medallas 
		for (int i=0; i < 28; i++){xy(5,c);medalla(i);c++;}
		for (int p=0; p < 28; p++){xy(120,d);medalla(p);d++;}
		
		//Cartel del login
		for (int i=0; i < 16; i++) {xy(50,e);cout << tituloLogin(i);e++;}
		
		//Recuadro ingreso de datos
		
		if (intentos<3) {
		recuadroLogin();
		color(7);
		xy(85,25);color(128);cout << msgLogin(1);
		xy(85,28);color(128);cout << msgLogin(2) << endl;
		xy(180,47); color (fondo); cout << msgCR();
		xy(90,26);color(112);cin>>Usuario;color(112);}
		
		//Calculo de la contrasena
		c1=(Usuario%10);
		c2=(Usuario/100)%10;
		c3=(Usuario/10000)%10;
		
		//Crear numero con datos extraidos del legajo
		numeroauxiliar=c1+(c2*10)+(c3*100);
		bool capicuaencontrado=false;
		int capicua;
		
		//Ciclo que busca el capicua mas cercano
		while(! capicuaencontrado){
			int primero, segundo;
			primero=numeroauxiliar%10;
			segundo=(numeroauxiliar/100);
			if (primero==segundo){capicuaencontrado=true; capicua=numeroauxiliar;}
			else {numeroauxiliar++;}}
		
		//Creacion de la contraseña
		Contrasena=(2024*capicua)+(Usuario%1000);
		
		//Pide ingreso de contraseña
		//int intentocontrasena;
		//xy(90,29);color(112);cin>>intentocontrasena;color(112);
		bool verific;
		verific = Contr(Contrasena); 
		if (verific){color(fondo);limpiarPantalla();menuPrincipal();inten=true;}
		
		intentos++;
		if(intentos>=3){color(75);recuadroFallido();xy(87,27);cout<<"Demasiado intentos fallidos"<<endl;xy(0,0);Sleep(2000);color(fondo);limpiarPantalla();inten=true;}
		
		else if(Usuario<10000 or Usuario>99999){
			
			color(75);recuadroFallido();xy(85,27);cout<<"Usuario o Contrasena Invalido"<<endl;xy(0,0);Sleep(2000);color(fondo);limpiarPantalla();}
		
		else if(!verific){
			
			color(75);recuadroFallido();xy(87,27);cout<<"Usuario o Contrasena Invalido"<<endl; xy(0,0);Sleep(2000);color(fondo);limpiarPantalla();}
		
	}
}
