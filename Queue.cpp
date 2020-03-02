/* 
 * File:   Queque.cpp
 * Author: helmuth
 * 
 * Created on 1 de marzo de 2020, 18:43
 */

#include "Queue.hpp"
#include "Node.h"
#include "Node.cpp"

template <typename T>
Queue<T>::Queue(){
    this->header = NULL;
    this->end = NULL;
}

/*
 * Metodo encargado de insertar un nuevo elemento en el final  de la cola.
 * Crea un nuevo nodo con el valor que recibe como parametro y asigna el end al nodo creado.
 * Si las lista se encuentra vacia se asigna al header el nodo creado, de lo contario se 
 * establece el siguiente del nodo apuntado por el end hacia el nodo recien creado. 
 */
template <typename T>
void Queue<T>::add(T value){
    Node<T>* node = new Node<T>(value);
    if(this->isEmpty()){
        this->header = node;
    }
    else{
        end->setNext(node);
    }
    this->end = node;
}

/*
 * Metodo encargado de remover el elemento de la cima de la cola.
 *  1. crea un nuevo nodo que apunta hacia el header.
 *  2. Se establece el header al siguiente del nodo actual.
 *  3. Se almacena el valor contenido dentro del nodo actual.
 *  4. Se elimina el nodo actual. 
 *  5. Se retorna el valor almacenado.
 */
template <typename T>
T Queue<T>::remove(){
    if(!this->isEmptyQueue()){
        Node<T>* node = this->header;
        header = node->getNext();
        T value = node->getValue();
        delete node;
        return value;
    }
    return (T)NULL;
}

/*
 * Metodo encargado de obtener y devolver el valor contenido en la cima de la cola.
 * Devuelve el valor contenido dentro del nodo que es apuntado por header.
 */
template <typename T>
T Queue<T>::peek() {
    if(!this->isEmptyQueue()){
        return header->getValue();
    }
    return (T)NULL;
}

/*
 * Metodo encargado de validar si la cola se encuentra vacia.
 * Si el puntero header apunta a NULL devuelve true.
 */
template <typename T>
bool Queue<T>::isEmpty(){
    return this->header == NULL;
}

/*
 * Metodo encargado de vaciar la cola.
 * Recorre cada nodo hasta que la cola se encuentre vacia, elimina cada nodo recorrido.
 */
template <typename T>
void Queue<T>::clear(){
    Node<T>* node;
    while(!this->isEmpty()){
        node = this->header;
        header = header->getNext();
        delete node; 
    }
}

/*
 * Metodo encargado de verificar si la cola esta vacia y lanzar una excepcion.
 * Caso contario devuelve false.
 */
template <typename T>
bool Queue<T>::isEmptyQueue(){
    if(this->isEmpty()){
        std::string msg = "Error: La cola se encuentra vacia"; 
        throw msg;
    }
    return false;
}