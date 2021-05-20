#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "DynamicArray.h"
#include "DynamicArray.cpp"

template<typename T>
class Stack {
public:
    Stack();

    explicit Stack(int capacity);

    T peek();

    void pop();

    void push(T data);

    bool isEmpty();

    friend ostream & operator <<(ostream& os ,Stack<T>& stack){
        return os<<stack.arr;
    }
private:
    DynamicArray<T> arr ;
};


#endif //DATASTRUCTURE_STACK_H
