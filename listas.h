#pragma once

#define LISTAS 7
#define CANDIDATOS_TOTALES 10

typedef string candidatos[CANDIDATOS_TOTALES];

enum TipoVoto {
	VNulo = -1,
	VBlanco = 0
};

enum Titularidad {
	Titular = 0,
	Suplente = 5
};

struct Lista {
	int numero_lista;
	string nombre_lista;

	candidatos personas_candidatas;

	void Mostrar() {

		int sum = 0;

		cout << "============================" << endl
			<< "N°: " << numero_lista << endl
			<< "Partido: " << nombre_lista << endl
			<< "Candidates: "<< endl;

		for (int i = 0; i < CANDIDATOS_TOTALES; i++) {
			if (personas_candidatas[i].length() > 1) {
				switch (i) {
				case Titular:  cout << "\t= Titulares: =" << endl ;
					break;
				case Suplente:  cout << "\t= Suplentes: =" << endl ;
					break;
				}
				cout << "\t*" << personas_candidatas[i] << endl;
			}
			else {
				sum++;
			}
		}

		if (sum == 10) {
			cout << "\t(Sin candidatos)" << endl;
		}

		cout << "============================" << endl;
	}
};

struct Nulo : Lista {
	Nulo() {
		numero_lista = VNulo;
		nombre_lista = "NULO";

		personas_candidatas[0] = { "\0" };
	}
};

struct Blanco : Lista {
	Blanco() {
		numero_lista = VBlanco;
		nombre_lista = "BLANCO";

		personas_candidatas[0] = { "\0" };
	}
};