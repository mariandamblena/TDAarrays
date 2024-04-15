#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int listaInsertarOrdenado(Lista* lista, int elemento){

if(lista->ce == CAP) // chequeo si el vector esta lleno
    return 0; // significa vector lleno
int i=0;
while(i<lista->ce && elemento>lista->vec[i])
    i++;
if(i<lista->ce && elemento==lista->vec[i])
    return 1;
for(int j=lista->ce - 1;j>=i;j--){
    lista->vec[j+1] = lista->vec[j];
}
lista->vec[i]=elemento;;
lista->ce ++;
return 2;
}

int listaInsertarInicio(Lista* listita, int elem){
if (listita->ce == CAP)
    return 0;
int i= 0;
for(int j = listita->ce-1;j>=i;j--){
    listita->vec[j+1]= listita->vec[j];
}
listita->vec[i] = elem;
listita->ce ++;
return 2;

}

int listaInsertarFinal(Lista* listita, int elem){
if (listita->ce == CAP)
    return 0;

listita->vec[listita->ce] = elem;
listita->ce ++;
return 2;

}

int listaInsertarOrdPunteros(Lista* listita, int elem){
if(listita->ce == CAP)
    return 0;
int* i= listita->vec; // pongo al puntero al inicio del vector
int* ult = listita->vec + listita->ce-1; // pongo otro puntero al final del vec
while(i<=ult && elem > *i)
    i++;
if(i<ult && elem == *i)
    return 1;
for(int *j = ult; j>=i; j--)
    *(j+1)= *j;
*i = elem;
listita->ce++;
return 2;
}

_Bool listaEliminarOrd(Lista* listita, int elem){
if(listita->ce==0)
    return false;

int* i= listita->vec;
int* ult = listita->vec + listita->ce-1;

while(i <=ult && elem > *i)// que no se vaya de rango y busco los casos en los que no esta el valor
    i++;
if(i > ult || elem< *i)
    return false;
for(int* j=i+1; j<=ult ;j++)
    *(j-1)=*j;
listita->ce--;
return true;
}


////////////////////////////////////////////////////////////////////////////////////
int insertarPuntero(Lista* lista, int elem){

if(lista->ce == CAP) // si esta lleno no cargo nada
    return 0;

int* i= lista->vec; // declaro puntero al inicio del vector 
int* ult= lista->vec + lista->ce - 1; // declaro puntero al final del vector

while(i<=ult && elem>*i)
    i++;

if(i<=ult && *i == elem)
    return 1;

for(int* j=ult  ;j>=i;j--)
    *(j+1)=*j;

*i=elem;
lista->ce++;
return 2;
}

_Bool eliminarPunteros(Lista* lista ,int elem){

if(lista->ce == 0)
    return false;

int* i = lista->vec;
int* ult = lista->vec + lista->ce-1;

while(i<=ult && elem> *i)
    i++;

if(i>ult || elem < *i)
    return false;

for(int* j= i+1 ;j<=ult ;j++)
    *(j-1)= *j


}


int insertarEnPosicionPunteros(Lista* vector, int posicion, int* elemento){

if(vector->ce == CAP)
    return 0;

int* ultimo = vector->vec + vector->ce-1;
int* posicion = vector->vec + posicion;

for (int* j = ultimo; posicion <= j; j--)
{
    *(j+1) = *j;
}

*posicion = *elemento;
vector->ce++;
return 2;
}

int insertarEnPosicionPunteros(Lista* vector, int posicion, int* elemento) {
    if (vector->ce == CAP) {
        return 0; // Si el array está lleno, retorna 0 (fallo en la inserción)
    }

    if (posicion < 0 || posicion > vector->ce) {
        return 0; // Si la posición está fuera de los límites, retorna 0 (fallo en la inserción)
    }

    int* ultimo = vector->vec + vector->ce - 1;
    int* pos = vector->vec + posicion;

    for (int* j = ultimo; j >= pos; j--) {
        *(j + 1) = *j; // Desplaza los elementos para abrir espacio para el nuevo elemento
    }

    *pos = *elemento; // Inserta el nuevo elemento en la posición indicada
    vector->ce++; // Incrementa la cantidad de elementos en la lista
    return 1; // Retorna 1 (éxito en la inserción)
}


int insertarEnPosicion(Lista* lista, int elemento){

if(lista->ce == CAP)
    return 0; 

int* i = lista->vec;
int* fin = lista->vec + lista->ce - 1; 

while(i<fin && *i<*elemento){
    i++;
}
for (int* j= ultimo; j >= i; j--)
{
    *(j+1)=*j;
}
*i = elemento;
return 2;


}

int insertarOrdPunt(Lista* vector, int* elemento){

if (vector->ce == CAP) {
        return 0; // Si el array está lleno, retorna 0 (fallo en la inserción)
    }

int* i = lista->vec;
int* ult = lista->vec + lista->ce-1;

while (i<=ult && *i<*elemento)
{
    i++;
}

if(i<=ult && *i == *elemento)
    return 1;

for (int* j = ult; i <= j; j--)
{
    *(j+1) = *j;
}

*i = *elemento;
vector->ce++;
return 2;
}


int EliminarOrdPunt(Lista* vector, int* elemento) {
if (vector->ce == 0) {
    return 0; // Si el array está vacío, retorna 0 (falla eliminación)
}

int* i = vector->vec;
int* ult = vector->vec + vector->ce - 1;

while (i <= ult && *i != *elemento) {
    i++;
}

if (i > ult || *i != *elemento) {
    return 0; // Elemento no encontrado, retorna 0 (falla eliminación)
}

for (int* j = i; j <= ult - 1; j++) {
    *j = *(j + 1); // Desplaza los elementos para eliminar el elemento
}

vector->ce--;
return 1; // Elemento encontrado y eliminado correctamente, retorna 1
}
