//
// Created by sysadmin on 23.03.2018.
//

#ifndef LAB5_6_DYNAMICVECTOR_H
#define LAB5_6_DYNAMICVECTOR_H

#include "Axolotl.h"

template <class T>
class DynamicVector {
    public:
        // default constructor for a DynamicVector
        DynamicVector(int capacity = 10);

        // copy constructor for a DynamicVector
        DynamicVector(const DynamicVector& v);
        ~DynamicVector();

        // assignment operator for a DynamicVector
        DynamicVector& operator=(const DynamicVector& v);

        DynamicVector& operator+(T& element);

        // Adds an element to the current DynamicVector.
        //void add(TElement e);
        void add(T e);

        /*
        Overloading the subscript operator
        Input: pos - a valid position within the vector.
        Output: a reference to the element o position pos.
        */
        //TElement& operator[](int pos);
        T& operator[](int pos);

        int getSize() const;
        int getCapacity() const;

        int searchElement(string name);
        void deleteElement(int index);
        void updateElement(int index, Axolotl::Breed breed, string name, int age, string photograph);

    private:
        // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
        void resize(double factor = 2);

        //TElement* elems;
        T* elems;
        int size;
        int capacity;
};

template <class T>
int DynamicVector<T>::getCapacity() const {
    return this->capacity;
}

template <class T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    //this->elems = new TElement[capacity];
    this->elems = new T[capacity];
}

template <class T>
DynamicVector<T>::DynamicVector(const DynamicVector& v) {
    this->size = v.size;
    this->capacity = v.capacity;
    //this->elems = new TElement[this->capacity];
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
}

template <class T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->elems;
}

template <class T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v) {
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    //this->elems = new TElement[this->capacity];
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}

template <class T>
DynamicVector<T>& DynamicVector<T>::operator+(T& element) {
    this->add(element);

    return *this;
}

template <class T>
DynamicVector<T>& operator+(T& element, DynamicVector<T>& dynamicVector) {
    dynamicVector.add(element);

    return dynamicVector;
}

template <class T>
//void DynamicVector::add(TElement e) {
void DynamicVector<T>::add(T e) {
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size] = e;
    this->size++;
}

template <class T>
void DynamicVector<T>::resize(double factor) {
    this->capacity *= factor;

    //TElement* els = new TElement[this->capacity];
    T* els = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elems[i];

    delete[] this->elems;
    elems = els;
}

template <class T>
//TElement& DynamicVector::operator[](int pos) {
T& DynamicVector<T>::operator[](int pos) {
    return this->elems[pos];
}

template <class T>
int DynamicVector<T>::getSize() const {
    return this->size;
}

template <class T>
int DynamicVector<T>::searchElement(string name) {
    for (int i = 0; i < this->size; ++i) {
        if (this->elems[i].getName() == name) {
            return i;
        }
    }

    return -1;
}

template <class T>
void DynamicVector<T>::deleteElement(int index) {
    for (; index < this->size - 1; ++index) {
        this->elems[index] = this->elems[index + 1];
    }

    --this->size;
}

template <class T>
void DynamicVector<T>::updateElement(int index, Axolotl::Breed breed, string name, int age, string photograph) {
    this->elems[index].setBreed(breed);
    this->elems[index].setName(name);
    this->elems[index].setAge(age);
    this->elems[index].setPhoto(photograph);
}



#endif //LAB5_6_DYNAMICVECTOR_H
