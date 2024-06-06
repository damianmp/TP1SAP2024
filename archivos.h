#pragma once
void nextPalabra(string& linea, int& pos, string& palabra);

void ArchivoALista(string dir, Lista l[], int lentgh) {

	ifstream archivo(dir);

	string linea;
	string palabra;

	getline(archivo, linea);

	while (getline(archivo, linea)) {
		int pos = 0;
		int primero = 0;
		string lastindex;

		while(pos > -1){

			pos = linea.find(",");
			palabra = linea.substr(0, pos);

			if (palabra == "P" || palabra == "T" || palabra == "S") {
				nextPalabra(linea, pos, palabra);

				//cout << "\t PARTIDO => " << palabra << endl;
			}

			cout << "| Pos: " << pos << " TXT: " << palabra << "|" << endl;
			linea = linea.substr(pos+1);
		}
	}
}

void nextPalabra(string &linea, int &pos, string &palabra) {
	linea = linea.substr(pos + 1);
	pos = linea.find(",");
	palabra = linea.substr(0, pos);
}

