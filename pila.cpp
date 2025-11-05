#include <iostream>
using namespace std;

struct NPila{
    int dato;
    NPila * link;
};

void agregarPila(NPila * &pila, int dato){
    NPila * nuevo = new(NPila);
    nuevo -> dato = dato;
    nuevo -> link = pila;
    pila = nuevo;
}
//1- creas el aux
//2- creas una variable dato, obteniendo de la pila -> dato
//3- pila pasa a la siguiente
//4- eliminas el aux, y retornas el dato
int obtenerDato(NPila * pila){
    NPila * aux = pila;
    int dato_obt = pila -> dato;
    pila = pila -> link;
    delete aux;
    return dato_obt;
}

int main() {
    
    return 0;
}