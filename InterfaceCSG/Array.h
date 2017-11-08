#ifndef ARRAY_H
#define ARRAY_H

template <typename T, int N>
class Array{
    protected :
        T data[N];
    public :
        Array();
        T operator[](const int index) const;
        T& operator[](const int index);
        const T* get_ptr() const;

};


#include "Array.hpp"

#endif
