#pragma once

#define MAX_LISTAS 7
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
public:
	int numero_lista;
	string nombre_lista;
private:
	candidatos personas_candidatas;
	int cantidad_votos = 0;
public:
	Lista(){}
	Lista(int m_numero_lista, string m_nombre_lista, candidatos m_personas_candidatas) :
		numero_lista(m_numero_lista), nombre_lista(m_nombre_lista){
		for (int i = 0; i < CANDIDATOS_TOTALES; i++) {
			personas_candidatas[i] = m_personas_candidatas[i];
		}
	}
	int MostrarCantidadVotos() {
		return cantidad_votos;
	}

	void Votar() {
		cantidad_votos++;
	}

	void Mostrar(){
		int sum = 0;
		cout << "============================" << endl
			<< "N�: " << numero_lista << endl
			<< "Partido: " << nombre_lista << endl
			<< "Candidates: "<< endl;
		if (personas_candidatas != NULL)
		{
			for (int i = 0; i < CANDIDATOS_TOTALES; i++) {
				if (personas_candidatas[i].length() > 0) {
					switch (i) {
					case Titular:  cout << "\t= Titulares: =" << endl;
						break;
					case Suplente:  cout << "\t= Suplentes: =" << endl;
						break;
					}
					cout << "\t*" << personas_candidatas[i] << endl;
				}
				else {
					sum++;
				}
			}
		}
		else {
			sum = CANDIDATOS_TOTALES;
		}

		if (sum == CANDIDATOS_TOTALES) {
			cout << "\t(Sin candidatos)" << endl;
		}

		cout << "============================" << endl;
	}

	candidatos* getCandidatos(){
		return &personas_candidatas;
	}

	string getNombre() {
		return this->nombre_lista;
	}

	int getNumeroLista() {
		return this->numero_lista;
	}
};

struct Nulo : Lista {
	Nulo() {
		numero_lista = VNulo;
		nombre_lista = "NULO";
	}
};

struct Blanco : Lista {
	Blanco() {
		numero_lista = VBlanco;
		nombre_lista = "BLANCO";
	}
};