/* 
 * File:   Queque.hpp
 * Author: helmuth
 *
 * Created on 1 de marzo de 2020, 18:43
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.h"
template <class T>
class Queue{
    
    public:
        Queue();
        void add(T value);
        T remove();
        T peek();
        bool isEmpty();
        void clear();
    
    private:
        Node<T>* header;
        Node<T>* end;
        bool isEmptyQueue();
};

#endif /* QUEUE_HPP */

