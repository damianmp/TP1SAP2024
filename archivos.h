#pragma once
void nextPalabra(string& linea, int& pos, string& palabra);

void ArchivoALista(string dir, Lista lista[], int size) {

	ifstream archivo(dir);

	string linea;
	string palabra;

	int i = 0;

	while (getline(archivo, linea)) {
		int pos = 0;
		int primero = 0;

		int numero_lista = 0;
		string nombre_lista = "";
		candidatos can;

		int titulares = 0;
		int suplentes = 0;

		string mark;

		while(pos > -1){

			pos = linea.find(",");
			palabra = linea.substr(0, pos);

			if (palabra == "P" || palabra == "T" || palabra == "S") {
				mark = palabra;
				nextPalabra(linea, pos, palabra);

				if (mark == "P") {
					numero_lista = stoi(palabra);
					nextPalabra(linea, pos, palabra);
					nombre_lista = palabra;
				}
				if (mark == "T") {
					do {
						nextPalabra(linea, pos, palabra);

						if (palabra != "S") {
							can[Titularidad::Titular + titulares] = palabra;
							titulares++;
						}
					} while (palabra != "S");
					mark = "S";
				}
				if (mark == "S") {
					do {
						nextPalabra(linea, pos, palabra);

						can[Titularidad::Suplente + suplentes] = palabra;
						suplentes++;
					} while (pos != -1);
				}
			}
			linea = linea.substr(pos+1);
		}

		Lista l(numero_lista, nombre_lista, can);
		lista[i] = l;
		i++;
	}

	archivo.close();
}

void nextPalabra(string &linea, int &pos, string &palabra) {
	linea = linea.substr(pos + 1);
	pos = linea.find(",");
	palabra = linea.substr(0, pos);
}

