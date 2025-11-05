#include <iostream>
using namespace std;

struct NCola{
    int dato;
    NCola * link;
};

void agregar(NCola* frente, NCola * fondo, int dato){
    //se crea un nodo como siempre
    NCola* nuevo = new(NCola);
    nuevo -> dato = dato;
    nuevo -> link = NULL;
    //este "if" permite saber si tenemos solo 1 dato
    //es frente y fondo a la vez...
    if(frente == NULL){
        frente = nuevo;
        fondo = nuevo;
    }
    //esto en realidad nos permite enlazarlo solo al fondo,
    //en caso de tener varios nodos...
    else{
        fondo -> link = nuevo;
        fondo = nuevo;
    }
}
//Es la misma que pila
//Creas un aux, asignas el dato de la cola
//pasas al sig de la cola, eliminas aux y retornas el dato.
bool obtener(NCola * cola){
    NCola * aux = cola;
    int dato = cola -> dato;
    cola = cola -> link;
    delete aux;
    return dato;
}


int main() {
    
    return 0;
}