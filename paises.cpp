#include <iostream>
#include <string>
#define numPaises 196
using namespace std;
const char* paises[] = {
	"Afganist�n", "Albania", "Alemania", "Andorra", "Angola",
	"Antigua y Barbuda", "Arabia Saudita", "Argelia", "Argentina", "Armenia",
	"Australia", "Austria", "Azerbaiy�n", "Bahamas", "Banglad�s",
	"Barbados", "Bar�in", "Belar�s", "B�lgica", "Belice",
	"Ben�n", "Bermudas", "Bhut�n", "Bolivia", "Bosnia y Herzegovina",
	"Botsuana", "Brasil", "Brunei", "Bulgaria", "Burkina Faso",
	"Burundi", "Cabo Verde", "Camboya", "Camer�n", "Canad�",
	"Catar", "Chad", "Chile", "China", "Chipre",
	"Colombia", "Comoras", "Congo", "Corea del Norte", "Corea del Sur",
	"Costa de Marfil", "Costa Rica", "Croacia", "Cuba", "Dinamarca",
	"Dominica", "Ecuador", "Egipto", "El Salvador", "Emiratos Arabes Unidos",
	"Eritrea", "Eslovaquia", "Eslovenia", "Espa�a", "Estados Unidos",
	"Estonia", "Esuatini", "Etiop�a", "Filipinas", "Fiyi",
	"Finlandia", "Francia", "Gab�n", "Gambia", "Georgia",
	"Ghana", "Granada", "Grecia", "Guatemala", "Guinea",
	"Guinea-Bis�u", "Guinea Ecuatorial", "Guyana", "Hait�", "Honduras",
	"Hungr�a", "India", "Indonesia", "Irak", "Ir�n",
	"Irlanda", "Islandia", "Islas Cook", "Islas Marshall", "Islas Salom�n",
	"Israel", "Italia", "Jamaica", "Jap�n", "Jordania",
	"Kazajist�n", "Kenia", "Kirguist�n", "Kiribati", "Kosovo",
	"Kuwait", "Laos", "Lesoto", "Letonia", "L�bano",
	"Liberia", "Libia", "Liechtenstein", "Lituania", "Luxemburgo",
	"Madagascar", "Malasia", "Malaui", "Maldivas", "Mal�",
	"Malta", "Marruecos", "Mauricio", "Mauritania", "M�xico",
	"Micronesia", "Moldavia", "M�naco", "Mongolia", "Montenegro",
	"Mozambique", "Namibia", "Nauru", "Nepal", "Nicaragua",
	"N�ger", "Nigeria", "Noruega", "Nueva Zelanda", "Om�n",
	"Pa�ses Bajos", "Pakist�n", "Palaos", "Palestina", "Panam�",
	"Pap�a Nueva Guinea", "Paraguay", "Per�", "Polonia", "Portugal",
	"Puerto Rico", "Reino Unido", "Rep�blica Centroafricana",
	"Rep�blica Checa", "Rep�blica del Congo", "Rep�blica Dominicana",
	"Ruanda", "Ruman�a", "Rusia", "Samoa", 	"Samoa Americana", 
	"San Crist�bal y Nieves", "San Marino", 
	"San Vicente y las Granadinas", "Santa Luc�a",
	"Santo Tom� y Pr�ncipe", "Senegal", "Serbia", "Seychelles", 
	"Sierra Leona",	"Singapur", "Siria", "Somalia", "Sri Lanka",
	"Sud�frica", "Sud�n", "Sud�n del Sur", "Suecia", "Suiza", "Surinam",
	"Tailandia", "Tayikist�n", "Tanzania", "Timor Oriental", "Togo",
	"Tonga", "Trinidad y Tobago", "T�nez", "Turqu�a", "Turkmenist�n",
	"Tuvalu", "Ucrania", "Uganda", "Uruguay", "Uzbekist�n",
	"Vanuatu", "Venezuela", "Vietnam", "Yemen", "Yibuti",
	"Zambia", "Zimbabue"
};

void imprimirPais(int indice) {
	if (indice >= 1 && indice <= numPaises) {
		cout << paises[indice - 1] << endl; 
	} else {
		cout << "Indice fuera de rango" << endl;
	}
}

void listarPaises() {
	for (int indice=0; indice <= numPaises; indice++) {
		cout <<indice+1<<" - "<< paises[indice]<<", "; 
	} 
}
