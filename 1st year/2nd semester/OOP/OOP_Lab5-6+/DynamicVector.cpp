//
// Created by sysadmin on 23.03.2018.
//

/*
#include "DynamicVector.h"

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
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& v) {
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
*/