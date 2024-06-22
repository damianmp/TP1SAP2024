#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include <listas.h>
#include <votos.h>
#include <archivos.h>

bool checkclose(string s);

int main() {
	setlocale(LC_CTYPE, "Spanish");
	
	//cargo el archivo con los partidos politicos
	Lista l[MAX_LISTAS+3];
	ArchivoALista("datos_partidos.csv", l, MAX_LISTAS+3);
	l[MAX_LISTAS + 1] = Blanco();
	l[MAX_LISTAS + 2] = Nulo();

	//pantalla principal
	string input;
	Votante aux[1];
	int ini = 0;
	do {
		cout << "============================================================" << endl << "\tPrograma de votación de las P.A.S.O. " << endl << "============================================================" << endl;
		cout << "- Ingrese edad del votante:" << endl;
		cin >> input;
		if (input != "F") {
			aux[ini].edad = stoi(input);

			cout << "- Ingrese genero del votante (0= Femenino, 1=Masculino, 2= Otro):" << endl;
			cin >> input;
			if (input != "F") {
				switch (stoi(input)) {
				case Femenino: {
					aux[ini].genero = Femenino;
					break;
				}
				case Masculino: {
					aux[ini].genero = Masculino;
					break;
				}
				case Otro: {
					aux[ini].genero = Otro;
					break;
				}
				}
				//pantalla votacion
				system("cls");
				for (int i = 0; i < MAX_LISTAS; i++) {
					cout << i + 1 << ") " << l[i].getNombre() << " - lista " << l[i].getNumeroLista() << endl;

					for (int j = 0; j < CANDIDATOS_TOTALES; j++) {
						if ((*l[i].getCandidatos())[j].size() > 0) {

							cout << (*l[i].getCandidatos())[j] << " - ";

						}
					}
					cout << endl;
				}

				cout << MAX_LISTAS + 1 << ") " << l[MAX_LISTAS + 1].getNombre() << " - lista " << l[MAX_LISTAS + 1].getNumeroLista() << endl;
				cout << MAX_LISTAS + 2 << ") " << l[MAX_LISTAS + 2].getNombre() << " - lista " << l[MAX_LISTAS + 2].getNumeroLista() << endl;

				cout << "- Seleccione un partido a votar:" << endl;
				cin >> input;
				if (stoi(input) <= MAX_LISTAS + 2) {
					l[stoi(input)-1].Votar();
				}

				system("cls");
			}
		}

	} while (input != "F");

	system("cls");

	for (int x = 0; x < MAX_LISTAS + 3; x++) {
		cout << l[x].getNombre() << ") - " << l[x].MostrarCantidadVotos() << endl;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}

bool checkclose(string s) {
	if (s == "F") {
		return true;
	}
	return false;
}