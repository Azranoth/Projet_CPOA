#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Array.h"

template<typename T, int N>
T Array<T,N>::operator[](const int index) const{
    return data[index];
}

template<typename T, int N>
T& Array<T,N>::operator[](const int index){
    return data[index];
}

template<typename T, int N>
Array<T,N>& Array<T,N>::operator=(const Array<T,N>& input){
    Array<T,N> res = Array<T,N>();
    for(int i = 0; i < N; i++){
        res[i] = input[i];
    }
    return res;
}

template<typename T, int N>
Array<T,N>& Array<T,N>::operator=(const T input[N]){
    Array<T,N> res = Array<T,N>();
    for(int i = 0; i < N; i++){
        res[i] = input[i];
    }
    return res;
}

template<typename T, int N>
void Array<T,N>::swap(Array<T,N>& array){
    Array<T,N> temp = Array(array);
    for(int i = 0; i < N; i++){
        data[i] = array[i];
        array[i] = temp[i];
    }
}

template<typename T, int N>
const T* Array<T,N>::get_ptr() const{
    return data;
}

#endif
