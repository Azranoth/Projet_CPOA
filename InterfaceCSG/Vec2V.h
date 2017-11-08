#ifndef VEC2V_H
#define VEC2V_H

#include "Vec2.h"


class Vec2V : public Vec2<float>{
    protected :
        Array<float,2> vitesse;
    public :
        inline Vec2V(){
            float dx = float(std::rand())/RAND_MAX;
            float dy = float(std::rand())/RAND_MAX;
            vitesse[0]=(dx-0.5f)/50;
            vitesse[1]=(dy-0.5f)/50;
        }

        inline void avance(float Ox=0, float Oy=0){
            float n = norme();
            data[0] += vitesse[0];
            data[1] += vitesse[1];

            if(n>1.414f){
                data[0]= Ox;
                data[1]= Oy;
            }
        }
};

#endif
