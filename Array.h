#ifndef DATASTRUCTURE_ARRAY_H
#define DATASTRUCTURE_ARRAY_H


#include <string>
#include <iostream>
#include <exception>
using namespace std;

template<typename T>

class Array {
public:
    Array();

    explicit Array(int c);

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

    friend ostream& operator <<(ostream &os ,Array<int>& );

private:
    int capacity;
    int size = 0;
    T *ptr;

    T * createspace (int capacity);
};






#endif //DATASTRUCTURE_ARRAY_H
