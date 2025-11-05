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

bool eliminar(NListaDE * &lista, int dato){

    //Creas la lista
    NListaDE * actual = lista;
    //recorres buscando el nodo
    while(actual != NULL && actual -> dato != dato){
        actual = actual -> link;
    }
    // si no existe, entonces no se encuentra
    if (actual == NULL){
        return false;
    }
    //Verificamos si es el primero de la lista.
    if(actual -> ant == NULL){
        //haces un aux, opcional para comodidad.
        NListaDE * aux = actual;
        // asignas el primero
        lista = actual-> link;
        //si la lista no es null, entonces,el anterior es null.
        if(lista != NULL){
            lista-> ant = NULL;
        }
        //lo eliminamos ya que lo encontramos.
        delete aux; 
    }
    else{
        //sino, en caso de que este en el medio
        actual -> ant -> link = actual -> link;
        //excepcion el cual, nos hace ver si es el "ultimo"
        // ya que sino se rompe todo
        if(actual -> link != NULL) actual -> link -> ant = actual -> ant;
        //eliminas el actual, no es necesario usar aux
        delete actual;
    }
    return true;

}

int main() {
    
    return 0;
}