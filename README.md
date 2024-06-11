Marcos generales:
=================

1) Al usar un puntero como referencia se debe:

```
char *pArg;
{objeto puntero}->Metodo( &pArg )
                            |
                            v
char *Metodo(char **ppszValue){...}
```
