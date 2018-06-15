//
//  Light.cpp
//  CG
//
//  Created by Trident on 09/05/2018.
//

#include "Light.hpp"


Light::Light(int type_, int number_, float cutoff_, float * dir_, float * pos_, float *ambi_ , float* diff_, float *spec_){
    Light::type = type_;
    Light::nr = number_;
    Light::cutoff = cutoff_;
    for (int i = 0;i<4; i++) {
        Light::pos[i] = pos_[i];
        Light::ambi[i] = ambi_[i];
        Light::diff[i] = diff_[i];
        Light::spec[i] = spec_[i];
        if (i<3) {
            Light::dir[i] =dir_[i];
        }
    }
}
//1-> dir 2-> spot 3-> point
void Light::lightUp(){
    if (type==1){
        pos[3]=0;
    }else{pos[3]=1;}
    glLightfv(nr+GL_LIGHT0, GL_POSITION, pos);
    glLightfv(nr+GL_LIGHT0, GL_AMBIENT, ambi);
    glLightfv(nr+GL_LIGHT0, GL_DIFFUSE, diff);
    glLightfv(nr+GL_LIGHT0, GL_SPECULAR, spec);
    if (type==2) {
        glLightfv(nr+GL_LIGHT0, GL_SPOT_DIRECTION, dir);
        glLightf(nr+GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
    }
}
