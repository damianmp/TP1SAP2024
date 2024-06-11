#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include <listas.h>
#include <votos.h>
#include <archivos.h>

int main() {
	setlocale(LC_CTYPE, "Spanish");

	Lista l[6];

	ArchivoALista("datos_partidos.csv", l, 2);

	l[0].Mostrar();

	//testeo roto
	l[4].Mostrar();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}