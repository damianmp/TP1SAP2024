/*
Se debe desarrollar una solución algorítmica para el análisis de los resultados de las elecciones PASO Nacionales en la Ciudad Autónoma
de Buenos Aires correspondientes al año 2023 donde se deberán renovar trece bancas correspondientes a igual número de diputados nacionales
Se presentan 7 listas con 10 candidatos cada una, los primeros 5 corresponden a candidatos "titulares" mientras que los restantes son
candidatos "suplentes"
Una vez realizada la elección, para el escrutinio (conteo de votos) se utilizará el Sistema D ´ Hont mecanismo que se utiliza para la
asignación de las bancas.
Para una correcta comprensión del problema planteado es importante que vean documentación acerca de la distribución de bancas en
una elección, para lo cual les proponemos varios links (no son los únicos publicados)
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
Una vez contados todos los votos válidos (no se consideran votos en blanco ni votos nulos) de cada lista votada se
descartan aquellos que obtuvieron menos del 3%.
Supongamos
en el ejemplo que en 4 listas NO ALCANZARON el 3%, por lo tanto las bancas se van a REPARTIR en las 3
listas restantes.
*/



	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}