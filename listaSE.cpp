#include <iostream>
using namespace std;

struct nodo_lista_se{
    int dato;
    struct nodo_lista_se * link;
};
typedef struct nodo_lista_se NListaSE;


void agregar(NListaSE * lista, int dato){
    NListaSE * aux = lista;
    NListaSE * nuevo = new(NListaSE);
    nuevo -> dato = dato;
    nuevo -> link = NULL;

    if(aux == NULL) lista = nuevo;
    else while(aux -> link != NULL) aux = aux -> link;
    aux -> link = nuevo;
}
bool eliminar(NListaSE* lista, int dato){
    //NListaSE de actual, anterior y aux
    NListaSE * actual = lista;
    NListaSE * anterior = NULL;
    NListaSE * aux = NULL;
    
    //While actual != NULL Y su DATO != DATO, buscando el dato
    while(actual != NULL && actual -> dato != dato){
        anterior = actual;
        actual = actual -> link;
    }
    //En caso que encuentre al actual y el anterior sea null
    //Actual se le asigna a aux, lista pasa la siguiente.
    //eliminas el aux, es verdadero.
    if(actual != NULL && anterior == NULL){
        aux = actual;
        lista = lista -> link;
        delete aux;
        return true;
    }
    //Si no, anterior es el ultimo, aux se le asigna actual
    //el siguiente del anterior pasa a ser actual siguiente.
    //eliminas aux, y retornas verdadero.
    else if(actual != NULL && anterior != NULL){
        aux = actual;
        anterior -> link = actual -> link;
        delete aux;
        return true;
    }
    return false;
}


int main() {
    
    return 0;
}