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

using namespace std;

#include <listas.h>
#include <votos.h>

int main() {
	/*
	1.
Para obtener una banca, al menos se deben obtener el 3% de los votos:
Una vez contados todos los votos v�lidos (no se consideran votos en blanco ni votos nulos) de cada lista votada se
descartan aquellos que obtuvieron menos del 3%.
Supongamos
en el ejemplo que en 4 listas NO ALCANZARON el 3%, por lo tanto las bancas se van a REPARTIR en las 3
listas restantes.
*/

	Lista l;
	l.nombre_lista = "Loques de los asados!";
	l.numero_lista = 19;
	l.personas_candidatas[Titularidad::Titular] = "Camilo";
	l.personas_candidatas[Titularidad::Titular+1] = "Zapata";
	l.personas_candidatas[Titularidad::Suplente] = "Julieta";
	l.personas_candidatas[Titularidad::Suplente+1] = "Carlos";

	l.Mostrar();

	Lista l1 = Nulo();
	l1.Mostrar();
	Lista l2 = Blanco();
	l2.Mostrar();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}