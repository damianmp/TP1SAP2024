#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include <listas.h>
#include <votos.h>
#include <archivos.h>

int main() {
	setlocale(LC_CTYPE, "Spanish");

	/*candidatos can;
	can[Titularidad::Titular] = "Gonza";
	can[Titularidad::Suplente] = "Facu";

	Lista lista(1, "Partido germanico", &can);
	lista.Mostrar();
	can[Titularidad::Suplente] = "Fede";
	lista.Mostrar();*/

	Lista l[6];

	ArchivoALista("datos_partidos.csv", l, 6);

	l[1].Mostrar();
	l[2].Mostrar();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}