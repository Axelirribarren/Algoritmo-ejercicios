#include <iostream>
using namespace std;

struct NListaDE{
    int dato;
    NListaDE * link;
    NListaDE * ant;
};

void agregar(NListaDE * &lista,int dato){
    //CREAMOS EN NODO
    NListaDE * nuevo = new(NListaDE);
    nuevo -> dato = dato;
    //ASIGNAMOS link(NULL) y ant(nuevo)
    nuevo -> link = NULL;
    nuevo -> ant = nuevo;
    //si la lista esta vacia
    //no hay nada antes del nodo
    //lista apunta al nuevo
    if(lista == NULL){
        nuevo -> ant = NULL;
        lista = nuevo;
    }
    //sino esta vacia, creamos un aux
    //esto nos permite avanzar al ultimo nodo
    //entonces aux apunta al ultimo nodo
    //conectamos link y ant
    //aux -> link = nuevo (Significa que el siguiente
    //seria el nuevo nodo)
    //aux -> ant = aux, implica que el anterior era el "ultimo"
    else{
        NListaDE * aux = lista;
        while(aux -> link != NULL){
            aux = aux -> link;
        }
        aux -> link = nuevo;
        nuevo->ant = aux;
    }
}



int main() {
    
    return 0;
}