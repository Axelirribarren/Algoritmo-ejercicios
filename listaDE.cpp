#include <iostream>
using namespace std;

struct NListaDE{
    int dato;
    NListaDE * link;
    NListaDE * ant;
};

void agregar(NListaDE * &lista,int dato){
    NListaDE * nuevo = new(NListaDE);
    nuevo -> dato = dato;

    nuevo -> link = NULL;
    nuevo -> ant = nuevo;

    if(lista == NULL){
        nuevo -> ant = NULL;
        lista = nuevo;
    }
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