#include "Stack.h"
#include <stdexcept>


template<typename T>
Stack<T>::Stack(){
    arr =  DynamicArray<T>(10);
}

template<typename T>
Stack<T>::Stack(int capacity){
    arr =  DynamicArray<T>(capacity);
}

template<typename T>
T Stack<T>::peek(){
    if (arr.getSize==0){
        throw invalid_argument("Stack is void");
    }else{
        return arr.get(arr.getSize()-1);
    }
}

template<typename T>
bool Stack<T>::isEmpty() {
    return arr.isEmpty();
}

template<typename T>
void Stack<T>::pop() {
    if (arr.getSize()==0){
        throw invalid_argument("Stack is void");
    }else{
        return arr.del(arr.getSize()-1);
    }
}

template<typename T>
void Stack<T>::push(T data){
    arr.append(data);
}

