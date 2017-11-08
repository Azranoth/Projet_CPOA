#ifndef VECTOR
#define VECTOR

// LIBS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
// SOURCES
#include "Array.h"


//--------Classe Vector générique--------//
template<typename T, int N>
class Vector: public Array<T,N>{

public:
    // CONSTRUCTEURS
    inline Vector(){
        for(int i = 0; i < N; i++)
            this->data[i] = T(0);
    }

    inline Vector(const T input[N]){
        for(int i = 0; i < N; i++)
            this->data[i] = input[i];
    }

    inline Vector(const Array<T,N>& input){
        for(int i = 0; i < N; i++)
            this->data[i] = input[i];
    }

    // AFFICHAGE D'UN VECTEUR
    void display(){
        std::cout << "[";
        for(int i = 0; i < N; i++){
            std::cout << " " << this->data[i] << " ";
        }
        std::cout << "]\n";
    }

    // ACCESSEURS
    T operator[](const int idx) const {
        return this->data[idx];
    }

    T& operator[](const int index){
        return this->data[index];
    }

    // OPERATIONS ENTRE VECTEURS
    bool operator==(const Vector<T,N>& vec){
        bool b = true;
        for(int i = 0; i < N; i++){
            if(this->data[i] != vec.data[i])
                b = false;
        }
        return b;
    }

    Vector<T,N> operator+(const Vector<T,N>& vec){
        Vector<T,N> res = Vector<T,N>();
        for(int i = 0; i < N; i++){
            res.data[i] = this->data[i]+vec.data[i];
        }
        return res;
    }

    Vector<T,N> operator-(const Vector<T,N>& vec){
        Vector<T,N> res = Vector();
        for(int i = 0; i < N; i++){
            res.data[i] = this->data[i]-vec.data[i];
        }
        return res;
    }

    void operator+=(const Vector<T,N>& vec){
        for(int i = 0; i < N; i++){
            this->data[i]+=vec.data[i];
        }
    }

    void operator-=(const Vector<T,N>& vec){
        for(int i = 0; i < N; i++){
            this->data[i]-=vec.data[i];
        }
    }
        // Produit scalaire
    T dot(const Vector<T,N>& vec){
        int sum = 0;
        for(int i = 0; i<N; i++)
            sum+=(this->data[i]*vec.data[i]);
        return sum;
    }

    // OPERATIONS ENTRE SCALAIRES & VECTEURS
    Vector<T,N> operator*(float& s){
        Vector<T,N> res = Vector();
        for(int i = 0; i < N; i++){
            res.data[i] = this->data[i]*s;
        }
        return res;
    }

};

// Gestion du cas des flottants

template<typename T, int N>
Vector<T,N> operator *(float& f, const Vector<T,N>& vec){
    Vector<T,N> res = Vector<T,N>();
    for(int i = 0; i < N; i++){
        res[i] = vec[i]*f;
    }
    return res;
}


// -----Définition des variantes de Vector----- //

// Vecteurs d'entiers
class Vec2i : public Vector<int,2>{
public:
    inline Vec2i() : Vector<int,2>(){}
    inline Vec2i(const int input[2]) : Vector<int,2>(input){}
    inline Vec2i(const Array<int,2> array) : Vector<int,2>(array){}

};

class Vec3i : public Vector<int,3>{

public:
    inline Vec3i() : Vector<int,3>(){}
    inline Vec3i(const int input[3]) : Vector<int,3>(input){}
    inline Vec3i(const Array<int,3> array) : Vector<int,3>(array){}

        // Produit vectoriel
    Vec3i cross(const Vec3i& vec){
        Vec3i res = Vec3i();

        res.data[0]=(this->data[1]*vec.data[2]) - (this->data[2]*vec.data[1]);
        res.data[1]=(this->data[2]*vec.data[0]) - (this->data[0]*vec.data[2]);
        res.data[2]=(this->data[0]*vec.data[1]) - (this->data[1]*vec.data[0]);

        return res;
    }
};

class Vec4i : public Vector<int,4>{
public:
    inline Vec4i() : Vector<int,4>(){}
    inline Vec4i(const int input[4]) : Vector<int,4>(input){}
    inline Vec4i(const Array<int,4> array) : Vector<int,4>(array){}
};


// Vecteurs de flottants
class Vec2f : public Vector<double,2>{
public:
    inline Vec2f() : Vector<double,2>(){}
    inline Vec2f(const double input[2]) : Vector<double,2>(input){}
    inline Vec2f(const Array<double,2> array) : Vector<double,2>(array){}
};

class Vec3f : public Vector<double,3>{

public:
    inline Vec3f() : Vector<double,3>(){}
    inline Vec3f(const double input[3]) : Vector<double,3>(input){}
    inline Vec3f(const Array<double,3> array) : Vector<double,3>(array){}

            // Produit vectoriel
    Vec3f cross(const Vec3f& vec){
        Vec3f res = Vec3f();

        res.data[0]=(data[1]*vec.data[2]) - (data[2]*vec.data[1]);
        res.data[1]=(data[2]*vec.data[0]) - (data[0]*vec.data[2]);
        res.data[0]=(data[0]*vec.data[1]) - (data[1]*vec.data[0]);

        return res;
    }
};

class Vec4f : public Vector<double,4>{
public:
    inline Vec4f() : Vector<double,4>(){}
    inline Vec4f(const double input[4]) : Vector<double,4>(input){}
    inline Vec4f(const Array<double,4> array) : Vector<double,4>(array){}
};



#endif // VECTOR

