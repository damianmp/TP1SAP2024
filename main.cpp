#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include <listas.h>
#include <votos.h>
#include <archivos.h>

int main() {
	setlocale(LC_CTYPE, "Spanish");

	Lista l[2];

	ArchivoALista("datos_partidos.csv", l, 2);

	l[0].Mostrar();
	l[1].Mostrar();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}