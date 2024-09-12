#include <iostream>
#include <string>
using namespace std;

char predeterminado = 'E'; // Español

void alternarIdioma() {
	switch (predeterminado) {
		case 'E': { predeterminado = 'I'; break; }
		case 'I': predeterminado = 'E';
	}
}

string msgLogo(const int fila) {
	switch (fila) {
		case 1: return "            Olympic Medals";
		case 2: return "              by New Mind";
		case 3: {
			switch (predeterminado) {
				case 'E': return  "     Presione SHIFT para continuar";
				case 'I': return  "        Press SHIFT to continue";
			}
		}
	    default: return "";
	}
}

string msgCarga() {
	switch (predeterminado) {
		case 'E': return "Cargando";
		case 'I': return "Loading";
	}
}

string msgConfirmacion(const int mensaje) {
	switch (mensaje) {
		case 1: {
			switch (predeterminado) {
				case 'E': return "      Esta seguro que desea salir? ";
				case 'I': return "    Are you sure you want to quit? ";	
			}
		}
		case 2: return "  NO  ";
		case 3: {
			switch (predeterminado) {
				case 'E': return "  SI  ";
				case 'I': return "  YES ";	
			}
		}
		default: return "";
	}
}

string msgLogin(const int fila) {
	switch (fila) {
		case 1: {
			switch (predeterminado) {
				case 'E': return " Por favor ingrese su usuario:      ";
				case 'I': return " Please type your username:         ";
			} 
		}
		case 2: {
			switch (predeterminado) {
				case 'E': return " Por favor ingrese su contrasena:   ";
				case 'I': return " Please type your password:         ";
			}
		}
	    default: return "";
	}
}

string msgDesarrollo(const int fila) {
	switch (fila) {
		case 1: {
			switch (predeterminado) {
				case 'E': return "FUNCIONALIDAD EN DESARROLLO";
				case 'I': return " FEATURE UNDER DEVELOPMENT";
			} 
		}
		case 2: {
			switch (predeterminado) {
				case 'E': return "(Disponible para versiones posteriores)";
				case 'I': return "    (Available for newer versions)";
			}
		}
	    default: return "";
	}
}

string msgCR() {
	switch (predeterminado) {
		case 'E': return "Todos los derechos reservados - NewMind, Olympic Medals v1.0";
		case 'I': return "    All rights reserved - NewMind, Olympic Medals v1.0";
	}
}

string msgTip() {
	switch (predeterminado) {
		case 'E': return "Desplazarse usando las flechas del teclado y presionar SPACE para seleccionar.";
		case 'I': return "      Use arrows keys from keyboard to move and press SPACE to select.";
	}
}

string msgPrincipal(const int opcion) {
	const int ancho = 26;
	switch (opcion) {
		case 1: {
			switch (predeterminado) {
				case 'E': return "      MENU PRINCIPAL";
				case 'I': return "        MAIN MENU";
			}
		}
		case 2: { return string(ancho,'='); }
		case 3: {
			switch (predeterminado) {
				case 'E': return "1. Generar competencia";
				case 'I': return "1. Generate match";
			}
		}
		case 4: {
			switch (predeterminado) {
				case 'E': return "2. Cargar Medallas";
				case 'I': return "2. Load Medals";
			}
		}
		case 5: {
			switch (predeterminado) {
				case 'E': return "3. Mostrar medallero";
				case 'I': return "3. Display medals";
			}
		}
		case 6: {
			switch (predeterminado) {
				case 'E': return "4. Cambiar Idioma";
				case 'I': return "4. Change Language";
			}
		}
		case 7: {
			switch (predeterminado) {
				case 'E': return "5. Salir del programa";
				case 'I': return "5. Quit the program";
			}
		}
	    default: return "";
	}
}
