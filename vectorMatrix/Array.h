#ifndef ARRAY_H
#define ARRAY_H

#include <math.h>

template <typename T, int N>
class Array{
    protected :
        T data[N];
    public :
        inline Array(){
            for(int i=0; i<N; i++){
                data[i] = T(0);
            }
        }

        inline Array(const T tab[N]){
            for(int i = 0; i < N; i++){
                data[i] = tab[i];
            }
        }

        inline Array(const Array<T,N>& array){
            for(int i = 0; i < N; i++){
                data[i] = array[i];
            }
        }

        T operator[](const int index) const;
        T& operator[](const int index);
        Array<T,N>& operator=(const Array<T,N>& input);
        Array<T,N>& operator=(const T input[N]);
        void swap(Array<T,N>& array);
        const T* get_ptr() const;

};


#include "Array.hpp"

#endif
