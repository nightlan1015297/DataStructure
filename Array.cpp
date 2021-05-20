#include "Array.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
Array<T>::Array() {
    capacity=10;
    ptr = createspace(capacity);

};

template <typename T>
Array<T>::Array(int c) {
    capacity=c;
    ptr = createspace(capacity);
}

template <typename T>
T * Array<T>::createspace(int capacity) {
    return new T[capacity];
}

template <typename T>
T Array<T>::get(int index) {
    if (index<0 || index>size){
        throw invalid_argument("Get Failed, invalid index.") ;
    }
    return (*(ptr+index));
}

template <typename T>
int Array<T>::getSize() {
    return size;
}

template <typename T>
int Array<T>::getCapacity() {
    return capacity;
}

template <typename T>
bool Array<T>::isEmpty() {
    return (bool) size;
}

template <typename T>
bool Array<T>::contains(T data){
    for (int i ; i<size;i++){
        if (*(ptr+i)==data){
            return true;
        }
    }
    return false;
}

template <typename T>
int Array<T>::find(T data){
    for (int i=0 ; i<size;i++){
        if (*(ptr+i)==data){
            return i;
        }
    }
    return -1;
}

template <typename T>
void Array<T>::append(T data) {
    add(size , data);
}

template <typename T>
void Array<T>::add(int index, T data) {
    if (size+1==capacity){
        throw invalid_argument("Array is full" );
    }
    if (index<0 || index>size){
        throw invalid_argument("Add Failed, invalid index.") ;
    }
    for (int i =size ; i>index ; i--){
        *(ptr+i) = *(ptr+i-1);
    }
    *(ptr+index) = data ;
    size++;
}

template <typename T>
void Array<T>::del(int index) {
    if (index<0 || index>size){
        throw invalid_argument("Del Failed, invalid index.") ;
    }
    for (int i=index ; i<size;i++ ){
        *(ptr+i) = *(ptr+i+1);
    }
    size--;
}

template <typename T>
bool Array<T>::removeElement(T data) {
    int index = find(data);
    if (index==-1){
        return false;
    }else{
        del(index);
        return true;
    }

}

template <typename T>
void Array<T>::set(int index, T data){
    if (index<0 || index>size){
        throw invalid_argument("Set Failed, invalid index.") ;
    }
    *(ptr+index) = data;
}

template <typename T>
void Array<T>::addFirst(T data) {
    add(0,data);
}
