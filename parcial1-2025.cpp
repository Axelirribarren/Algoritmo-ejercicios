#include <iostream>
using namespace std;
/*
Tiene una lista doblemente enlazada implementada con estructuras de datos dinámicas
que contiene información sobre los clientes de una organización. Los datos que se
guardan son los siguientes: id_cliente, nombre, dirección, edad, saldo (el mismo puede
ser positivo o negativo). Esta lista no tiene orden alguno.
Realizar una función que reciba como parámetro de entrada la lista descripta y elimine "el
nodo MEDIO de la lista".
Si la cantidad de nodos es impar, el medio es el elemento que se encuentra exactamente
en la mitad.
Si la cantidad de nodos es par, debe eliminar los dos elementos que se encuentran en la
mitad.
*/
struct NListaDE{
    
    string nombre;
    string direccion;
    int edad;
    float saldo;

    int id_cliente;
    NListaDE * sig;
    NListaDE * ant;
};

bool eliminarNodoMedio(NListaDE * lista){
    NListaDE * aux = lista;
    int cantNodos = 0;
    // buscamos cant nodos.
    while(aux != NULL){
        aux = aux -> sig;
        cantNodos++;
    }
    if(cantNodos <= 1){
        return false;
    }
    // calculamos los nodos pares e impares
    if(cantNodos % 2 == 0){
        int par1 = (cantNodos/2);
        int par2 = par1 +1;
        NListaDE * aux = lista;
        

        for(int i = 1; i < par1; i++){
            aux =aux -> sig;
        }
        NListaDE * aux2 = aux;
        aux2 = aux2 -> sig;

        if(aux -> ant == NULL){
            lista = aux2 -> sig;
            if(lista != NULL){
                lista -> ant = NULL;
            }
        }
        // si llega a ser el ultimo o medio
        else{
            aux-> ant -> sig = aux2 -> sig;
            if(aux2 -> sig != NULL){
                aux2 -> sig -> ant = aux -> ant;
            }
        }
        
        delete aux;
        delete aux2;
        return true;

    }
    else{
        // en el caso de impar, se busca enlazar y verificar
        // que no se rompa todo.
        
        int impar = (cantNodos/2) +1;
        NListaDE* actual = lista;
        //saltamos al nodo impar
        for(int i = 1; i < impar; i++){
            actual = actual -> sig;
        }
        // si es el primero
        if(actual -> ant == NULL){
            lista = actual -> sig;
            if(lista != NULL){
                lista -> ant = NULL;
            }
        }
        // si llega a ser el ultimo o medio
        else{
            actual -> ant -> sig = actual -> sig;
            if(actual -> sig != NULL){
                actual -> sig -> ant = actual -> ant;
            }
        }
        delete actual;
        
    }
}


int main() {
    
    return 0;
}