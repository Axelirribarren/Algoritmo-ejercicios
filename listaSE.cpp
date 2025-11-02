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
    NListaSE * actual = lista;
    NListaSE * anterior = NULL;
    NListaSE * aux = NULL;

    while(actual != NULL && actual -> dato != dato){
        anterior = actual;
        actual = actual -> link;
    }
}

int main() {
    
    return 0;
}