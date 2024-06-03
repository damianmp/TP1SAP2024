/*
Se debe desarrollar una soluci�n algor�tmica para el an�lisis de los resultados de las elecciones PASO Nacionales en la Ciudad Aut�noma
de Buenos Aires correspondientes al a�o 2023 donde se deber�n renovar trece bancas correspondientes a igual n�mero de diputados nacionales
Se presentan 7 listas con 10 candidatos cada una, los primeros 5 corresponden a candidatos "titulares" mientras que los restantes son
candidatos "suplentes"
Una vez realizada la elecci�n, para el escrutinio (conteo de votos) se utilizar� el Sistema D � Hont mecanismo que se utiliza para la
asignaci�n de las bancas.
Para una correcta comprensi�n del problema planteado es importante que vean documentaci�n acerca de la distribuci�n de bancas en
una elecci�n, para lo cual les proponemos varios links (no son los �nicos publicados)
*/

#include <iostream>
#include <string>

#define CANDIDATOS 10;

using namespace std;



struct Partido {
	int numero_lista;
	string nombre_lista;

};


void main() {
	/*
	1.
Para obtener una banca, al menos se deben obtener el 3% de los votos:
Una vez contados todos los votos v�lidos (no se consideran votos en blanco ni votos nulos) de cada lista votada se
descartan aquellos que obtuvieron menos del 3%.
Supongamos
en el ejemplo que en 4 listas NO ALCANZARON el 3%, por lo tanto las bancas se van a REPARTIR en las 3
listas restantes.
*/



	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}