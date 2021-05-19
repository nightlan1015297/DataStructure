#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
DynamicArray<T>::DynamicArray() {
    capacity=10;
    ptr = createspace(capacity);

};

template <typename T>
DynamicArray<T>::DynamicArray(int c) {
    capacity=c;
    ptr = createspace(capacity);
}

template <typename T>
T* DynamicArray<T>::createspace(int capacity) {
    return new T[capacity];
}

template <typename T>
void DynamicArray<T>::resize(int new_capacity) {
    capacity = new_capacity;
    T* Tempptr = createspace(new_capacity);
    for (int i=0;i<size;i++){
        *(Tempptr+i) = *(ptr+i);
    }
    ptr = Tempptr;
}

template <typename T>
T DynamicArray<T>::get(int index) {
    if (index<0 || index>size){
        throw invalid_argument("Get Failed, invalid index.") ;
    }
    return (*(ptr+index));
}

template <typename T>
int DynamicArray<T>::getSize() {
    return size;
}

template <typename T>
int DynamicArray<T>::getCapacity() {
    return capacity;
}

template <typename T>
bool DynamicArray<T>::isEmpty() {
    return (bool) size;
}

template <typename T>
bool DynamicArray<T>::contains(T data){
    for (int i ; i<size;i++){
        if (*(ptr+i)==data){
            return true;
        }
    }
    return false;
}

template <typename T>
int DynamicArray<T>::find(T data){
    for (int i=0 ; i<size;i++){
        if (*(ptr+i)==data){
            return i;
        }
    }
    return -1;
}

template <typename T>
void DynamicArray<T>::append(T data) {
    add(size , data);
}

template <typename T>
void DynamicArray<T>::add(int index, T data) {
    if (size+1==capacity){
        resize(capacity*2);
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
void DynamicArray<T>::del(int index) {
    if (index<0 || index>size){
        throw invalid_argument("Del Failed, invalid index.") ;
    }
    for (int i=index ; i<size;i++ ){
        *(ptr+i) = *(ptr+i+1);
    }
    size--;
    //This Condition triggers when size is smaller then half of capacity
    // to prevent complexity Oscillation
    if (size<(capacity/2)){
        resize(capacity/2);
    }
}

template <typename T>
bool DynamicArray<T>::removeElement(T data) {
    int index = find(data);
    if (index==-1){
        return false;
    }else{
        del(index);
        return true;
    }

}

template <typename T>
void DynamicArray<T>::set(int index, T data){
    if (index<0 || index>size){
        throw invalid_argument("Set Failed, invalid index.") ;
    }
    *(ptr+index) = data;
}

template <typename T>
void DynamicArray<T>::addFirst(T data) {
    add(0,data);
}


inline ostream& operator<< (ostream &os,DynamicArray<int>& arr) {
    os<<"Array Capacity :"<<arr.getCapacity()<<", Array Size :" << arr.getSize()<<endl;
    os<<"[";
    for (int i = 0 ; i<arr.getSize()-1;i++){
        os<<arr.get(i)<<",";
    }
    os<<arr.get(arr.getSize()-1)<<"]"<<endl;
    return os;}
