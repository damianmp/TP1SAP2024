#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#include <listas.h>
#include <votos.h>
#include <archivos.h>

void Votar(Lista[], int&);
void MostrarVotos(Lista[], int&);
void OrdenarMayorMenor(Lista[]);

int main() {
	setlocale(LC_CTYPE, "Spanish");
	
	//cargo el archivo con los partidos politicos
	Lista l[MAX_LISTAS+3];
	ArchivoALista("datos_partidos.csv", l, MAX_LISTAS+3);
	l[MAX_LISTAS + 1] = Blanco();
	l[MAX_LISTAS + 2] = Nulo();

	//pantalla principal
	/*
	-Mostrar por pantalla, para cada lista la cantidad de votos por rango de edades hasta 18
	 años hasta 30 años hasta 50 años más de 50 años
	*/

	int total = 0;

	Votar(l, total);
	OrdenarMayorMenor(l);
	MostrarVotos(l, total);

	return 0;
}

void OrdenarMayorMenor(Lista l[]) {
	system("cls");

	for (int i = 0; i < MAX_LISTAS + 2; i++) {
		cout << "{" << l[i].MostrarCantidadVotos() << "}";
	}
	cout << endl;

	for (int i = 0; i < MAX_LISTAS + 2; i++) {
		for (int j = 0; j< MAX_LISTAS + 2 ; j++) {
			if (l[j].MostrarCantidadVotos() < l[i].MostrarCantidadVotos()) {
				Lista aux = l[i];
				l[i] = l[j];
				l[j] = aux;
			}
		}
	}

	for (int i = 0; i < MAX_LISTAS + 2; i++) {
		cout << "{" << l[i].MostrarCantidadVotos() << "}";
	}
	cout << endl;
	cout << "=== OrdenarMayorMenor ===" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void MostrarVotos(Lista l[], int &total) {
	system("cls");
	if (total > 0) {
		for (int x = 0; x < MAX_LISTAS + 2; x++) {

			float porcentaje = (l[x].MostrarCantidadVotos() * 100.00) / float(total);
			cout << "[" << right<<setw(50) <<l[x].getNombre() << "][" << right << setw(3)<< l[x].MostrarCantidadVotos() << "][" << right << setw(3)<< porcentaje << "%]" << endl;
		}
	}
	else{
		cout << "NO HUBO VOTOS VÁLIDOS" << endl;
	}	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Votar(Lista l[], int &total) {
	string input;
	Votante aux;
	do {
		system("cls");
		cout << "============================================================" << endl << "\tPrograma de votación de las P.A.S.O. " << endl << "============================================================" << endl;
		cout << "- Ingrese edad del votante:" << endl;
		cin >> input;
		if (input != "F") {
			aux.edad = stoi(input);

			cout << "- Ingrese genero del votante (0= Femenino, 1=Masculino, 2= Otro):" << endl;
			cin >> input;
			if (input != "F") {
				switch (stoi(input)) {
					case Femenino: {
						aux.genero = Femenino;
						break;
					}
					case Masculino: {
						aux.genero = Masculino;
						break;
					}
					case Otro: {
						aux.genero = Otro;
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
					l[stoi(input)].Votar();
				}
				if (stoi(input) < MAX_LISTAS + 2) {
					total++;
				}
			}
		}

	} while (input != "F");
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}