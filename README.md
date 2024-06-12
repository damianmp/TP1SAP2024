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
