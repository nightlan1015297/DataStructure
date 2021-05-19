#ifndef DATASTRUCTURE_DYNAMICARRAY_H
#define DATASTRUCTURE_DYNAMICARRAY_H

#include <string>
#include <iostream>
#include <exception>
using namespace std;

template<typename T>

class DynamicArray {
public:
    DynamicArray();

    explicit DynamicArray(int c);

    T get(int index);

    int getSize();

    int getCapacity () ;

    bool isEmpty () ;

    bool contains(T data);

    int find(T data);

    void append(T data) ;

    void add(int index,T data);

    void del(int index);

    bool removeElement(T data);

    void set(int index ,T data);

    void addFirst(T data);

    friend ostream& operator <<(ostream &os ,DynamicArray<int>& );

private:
    int capacity;
    int size = 0;
    T *ptr;

    T * createspace (int capacity);

    void resize(int capacity);
};



#endif //DATASTRUCTURE_DYNAMICARRAY_H
