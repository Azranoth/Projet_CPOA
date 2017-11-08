#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Array.h"

template<typename T, int N>
Array<T,N>::Array(){
    for(int i=0; i<N; i++){
        data[i] = T(0);
    }
}

template<typename T, int N>
T Array<T,N>::operator[](const int index) const{
    return data[index];
}

template<typename T, int N>
T& Array<T,N>::operator[](const int index){
    return data[index];
}

template<typename T, int N>
const T* Array<T,N>::get_ptr() const{
    return data;
}

#endif
