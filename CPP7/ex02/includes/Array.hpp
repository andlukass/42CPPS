#pragma once

#include <stdexcept>

#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
    private:
        T* _array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array( const Array& toCopy );
        Array& operator=( const Array& toCopy );
        T& operator[]( unsigned int index );

        unsigned int size() const ;

};

template <typename T>
Array<T>::Array() {
    this->_array = new T[0];
    this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->_array = new T[n]();
    this->_size = n;
}

template <typename T>
Array<T>::~Array() {
    delete []this->_array;
}

template <typename T>
Array<T>::Array( const Array& toCopy ) {
    this->_array = new T[0];
    *this = toCopy;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& toCopy ) {
    if (&toCopy == this) {
        return *this;
    }
    delete []this->_array;
    unsigned int size = toCopy.size();
    this->_array = new T[size];
    this->_size = size;
    for (unsigned int i = 0; i < size; i++) {
        this->_array[i] = toCopy._array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->_size) {
        throw std::exception();
    }
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->_size;
}