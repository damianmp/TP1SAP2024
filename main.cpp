#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

#include "listas.h"
#include "votos.h"
#include "archivos.h"

#define MAX_BANCAS 13

typedef int bancas[MAX_LISTAS][MAX_BANCAS];

void Votar(Lista[], int&, int&);
void MostrarVotos(Lista[], int&);
void OrdenarMayorMenor(Lista[]);
void AsignarBancas(Lista[], int);
void BancasOcupadas(Lista[], int); // ADD -- ED
void VotosRangoEdad(Lista*); // ADD -ED
void SumarEdadesPorLista(Lista&, Votante&);

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
	int totalValidos = 0;
	
#if __DEBUG__

	Votar(l, total, totalValidos);
	
#else

	srand((unsigned) time(NULL));
	int random = 0;
	for(int i = 0; i<=100; i++){
		random = rand() % (MAX_LISTAS+1);
		l[random].Votar();
		
	}
	total = 100;
	totalValidos = 80;
	
#endif

/*
	for(int i = 0; i <=100 ;i++){
		l[0].Votar();
	}
	
	
	for(int i = 0; i <=80 ;i++){
		l[1].Votar();
	}
	
	for(int i = 0; i <=70 ;i++){
		l[2].Votar();
	}
	
	total = 270;
	totalValidos = 270;
*/

	OrdenarMayorMenor(l);
	MostrarVotos(l, total);
	if(totalValidos > 0){
		AsignarBancas(l, totalValidos);
	}
	
	VotosRangoEdad(l);
	return 0;
}

void VotosRangoEdad(Lista* l){
	system("cls");
	
	cout << left << setw(51) << setfill(' ') << "Votos por rango de edades: " << endl;
	cout << right << setw(116) << setfill('-') <<" "<< endl;
	
	for(int i = 0; i < MAX_LISTAS; i++){
		
		if (l[i].MostrarCantidadVotos() > 0){

		cout << left << setw(40) << setfill(' ') << l[i].getNombre()
			<< left << setw(5) << setfill(' ') << " Lista " <<l[i].getNumeroLista()
			<< right << setw(5) << setfill(' ') <<" { " << l[i].MostrarCantidadVotos() << " Votos }" << endl;

			for(int j = 0; j < RangoEdad::MAX_RANGOEDAD; j++){
				switch(j){
					case RangoEdad::Dieciocho:{
						//<18
							cout << right << setw(70) << setfill(' ') << "Hasta 18 años: " << l[i].categoria[RangoEdad::Dieciocho] << endl;
						break;
					}
					case RangoEdad::Treinta:{
						//<30
							cout << right << setw(70) << setfill(' ') << "Hasta 30 años: " << l[i].categoria[RangoEdad::Treinta] << endl;
						break;
					}
					case RangoEdad::Cincuenta:{
						//<50
							cout << right << setw(70) << setfill(' ') << "Hasta 50 años: " << l[i].categoria[RangoEdad::Cincuenta] << endl;
						break;
					}
					case RangoEdad::Mayor50:{
						//<+
							cout << right << setw(70) << setfill(' ') << "Más de 50 años: " << l[i].categoria[RangoEdad::Mayor50] << endl;
						break;
					}
				}
			}
			cout<<endl;
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void AsignarBancas(Lista l[], int total){
	system("cls");
	
	bancas b;
	int maximo = 0;
	
	for(int i = 0; i < MAX_LISTAS ; i++){
		float porcentaje = (l[i].MostrarCantidadVotos()*100.00)/float(total);
		if(porcentaje > 3) {
			for(int j=1;j <= MAX_BANCAS; j++){
				b[i][j-1] = round(l[i].MostrarCantidadVotos()/j);
			}
			maximo++;
		}
		else{
			cout << "* " << l[i].getNombre() << " no superó el 3%." << endl;
		}
	}
	
	cout << left << setw(51) << setfill(' ')<< "Bancas";
	for(int j=1; j <=MAX_BANCAS; j++){
		cout << "{"<< right<< setw(3) << j << "}";
	}
	cout<< endl;
	
	cout << right << setw(116) << setfill('-')<< ""<<endl;
	
	for(int i=0; i < maximo; i++){
		cout << left << setw(40) << setfill(' ')<< l[i].getNombre() << left << setw(5) << setfill(' ')<< "Lista " << left << setw(5) << setfill(' ')<<l[i].getNumeroLista();
		for(int j=0; j < MAX_BANCAS; j++){
			cout << "{"<< right<< setw(3) << b[i][j] << "}";
		}
		cout << endl;
	}
	
	int bancasrestantes = MAX_BANCAS;
	
	for(int j=0;j<MAX_BANCAS;j++){
		for(int i=0;i< maximo; i++){
			if(bancasrestantes > 0 && b[i][j] > 0){
				l[i].asignarBancas();
				bancasrestantes--;
			}
		}
	}
	
	cout << endl;
	cout << "Bancas asignadas:" <<endl;
	
	for(int i=0; i < maximo; i++){
		cout << left << setw(40) << setfill(' ')<< l[i].getNombre() << left << setw(5) << setfill(' ')<< "Lista " << left << setw(5) << setfill(' ')<<l[i].getNumeroLista() << "{"<< right<< setw(3) << l[i].getCantidadBancas() << "}" << endl;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	BancasOcupadas(l, maximo); //ADD
}


 // ADD INI
void BancasOcupadas(Lista l[], int maximo){
	system("cls");
	
	bancas b;

	cout << left << setw(51) << setfill(' ')<< "Bancas ocupadas por candidato de cada partido: ";
	cout<< endl;
	
	cout << right << setw(116) << setfill('-')<< ""<<endl;
	
	int bancasrestantes = MAX_BANCAS;
	
	for(int i=0; i < maximo; i++){
		cout<< left << setw(40) << setfill(' ')<< l[i].getNombre()
			<< left << setw(5) << setfill(' ')<< "Lista " << left << setw(5) << setfill(' ')<<l[i].getNumeroLista()
			<< "{Obtiene "<< right<< setw(3) << l[i].getCantidadBancas();
			if (l[i].getCantidadBancas()>1){
			    cout<<" bancas}" << endl;
			}
			else{
				cout<<" banca}" << endl;
			};
			
			cout <<right << setw(63) <<setfill(' ')<<"Candidatos: "<<endl;
			for(int j=0; j < l[i].getCantidadBancas(); j++){			 	
			 	cout <<setw(53)<< "* "<< l[i].personas_candidatas[j] << endl;
 	
			}
			cout <<endl;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
 // ADD FIN


void OrdenarMayorMenor(Lista l[]) {
	system("cls");

	cout << "Sin ordenar:";
	for (int i = 0; i <= MAX_LISTAS ; i++) {
		cout << "{" << l[i].MostrarCantidadVotos() << "}";
	}
	cout << endl;

	for (int i = 0; i <= MAX_LISTAS; i++) {
		for (int j = 0; j<= MAX_LISTAS; j++) {
			if (l[j].MostrarCantidadVotos() < l[i].MostrarCantidadVotos()) {
				Lista aux = l[i];
				l[i] = l[j];
				l[j] = aux;
			}
		}
	}
	cout << "Ordenado:   ";
	for (int i = 0; i <= MAX_LISTAS; i++) {
		cout << "{" << l[i].MostrarCantidadVotos() << "}";
	}
	cout << endl;
	cout << "=== OrdenarMayorMenor ===" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void MostrarVotos(Lista l[], int &total) {
	system("cls");
	if (total > 0) {

		cout << "<" << right << setw(55) << setfill('.') << "TOTAL" << "><" << right << setw(14) << total << ">" << endl;

		for (int x = 0; x <= MAX_LISTAS + 2; x++) {

			float porcentaje = (l[x].MostrarCantidadVotos() * 100.00) / float(total);
			cout << "[" << right<<setw(50) <<l[x].getNombre() << " - "<< "Lista " <<l[x].getNumeroLista() << "][" << right << setw(3)<< l[x].MostrarCantidadVotos() << "][" << right << setw(3)<< porcentaje << "%]" << endl;
		}
	}
	else {
		cout << "NO HUBO VOTOS VÁLIDOS" << endl;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void Votar(Lista l[], int &total, int& totalValidos) {
	string input;
	Votante aux;
	do {
		system("cls");
		cout << "============================================================" << endl << "\tPrograma de votación de las P.A.S.O. " << endl << "============================================================" << endl;
		cout << "- Ingrese edad del votante:" << endl;
		cin >> input;
		if (input != "F" and input != "f") {
			aux.edad = stoi(input);

			cout << "- Ingrese genero del votante (0= Femenino, 1=Masculino, 2= Otro):" << endl;
			cin >> input;
			if (input != "F" and input != "f") {
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

				cout << "- Seleccione un partido a votar:" << endl;
				cin >> input;

				int ivoto = stoi(input);
				if (ivoto == 0) {
					l[MAX_LISTAS + 1].Votar();
					SumarEdadesPorLista(l[MAX_LISTAS + 1], aux);
				}
				else if (ivoto > MAX_LISTAS || ivoto < 0) {
					l[MAX_LISTAS + 2].Votar();
					SumarEdadesPorLista(l[MAX_LISTAS + 2], aux);
				}
				else {
					l[ivoto-1].Votar();
					SumarEdadesPorLista(l[ivoto-1], aux);
					totalValidos++;
				}
				total++;
			}
		}

	} while (input != "F" and input != "f");
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void SumarEdadesPorLista(Lista& l, Votante& v){
	/*--------------*/
	/* 0 | 1 | 2 | 3*/
	/*<18|<30|<50|<+*/
	/*--------------*/
	
	if(v.edad <= 18 ){
		l.categoria[RangoEdad::Dieciocho]+=1;
	}
	else if(v.edad <= 30){
		l.categoria[RangoEdad::Treinta]+=1;
	}
	else if(v.edad <= 50){
		l.categoria[RangoEdad::Cincuenta]+=1;
	}
	else{
		//despues de los 50
		l.categoria[RangoEdad::Mayor50]+=1;
	}
}
