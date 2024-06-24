#pragma once

#include <iostream>
#include <string>

template <typename T>
void printElement(T& a){
     std::cout << a << std::endl;
}

template <typename T,typename U>
void iter(T* a, unsigned long int size, U* func) {

    for (unsigned long int i = 0; i < size; i++){
        func(a[i]);
    }
}
