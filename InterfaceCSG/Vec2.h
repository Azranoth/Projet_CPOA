#ifndef VEC2_H
#define VEC2_H

#include "Array.h"

template<typename T>
class Vec2 : public Array<T,2>{
    public :
        T norme() const;
};

#include "Vec2.hpp"

#endif
