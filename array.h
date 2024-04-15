#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#define CAP 10

typedef struct
{
    int d;
    int m;
    int a;

}Fecha;


typedef struct
{
    int vec[CAP];
    int ce;

}Lista;

int listaInsertarOrdenado(Lista* lista, int elemento);
int listaInsertarInicio(Lista* listita, int elem);
int listaInsertarFinal(Lista* listita, int elem);

#endif // ARRAY_H_INCLUDED
