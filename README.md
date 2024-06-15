Apuntes:
=================

1) Al usar un puntero como referencia se debe:

```
char *pArg;
{objeto puntero}->Metodo( &pArg )
                            |
                            v
char *Metodo(char **ppszValue){...}
```
2) A la hora de redimensionar punteros vectores se debe:
```
Votante* votos = new Votante[1];
Votante *votos2 = new Votante[10];
/*
  a la hora de asignar el espacio, el sizeof calcula el tamaño
  total del Struct Votante y sus 10 lugares en el array

  sizeof(Votante) = 276 bytes
  276 * 10 lugares del array = 2760 bytes aprox.

  asi se ahora tiempo en copiar pegar cada elemento de la lista
*/
memcpy(votos2, votos , 10*sizeof(Votante));
```
3) Manejo práctico de la memoria con punteros y referencias
```
struct test {
	int a;
	char b[12]; // b* == b[]
};

test t2;
t2.a = 15;
memcpy(t2.b, "Hola!", sizeof(char) * 12);

test* t = &t2;
cout << (*t).a << " -> " << (*t).b << endl;

test t3[3];
t3[0].a = 13;
memcpy(t3[0].b, "Mundo", sizeof(char) * 12);
t3[2].a = 123;
memcpy(t3[2].b, "Eto e c++", sizeof(char) * 12);

test* t4 = t3;
cout << t4[0].a << " -> " << t4[2].a << endl;
cout << (*t).b << " " << t4[0].b << " " << t4[2].b << endl;
```
4) Ejemplo de concatenación y muestra de datos en una matriz
```
char matrix[30][10][5];

for (int i = 0; i <= 10; i++) {
	for (int j = 0; j <= 5; j++) {
		sprintf(matrix[i][j], "| %3i |", ((i * 10)+j));
	}
}

for (int i = 0; i <= 10; i++) {
	for (int j = 0; j <= 5; j++) {
		cout << matrix[i][j];
	}
	cout << endl;
}
```
