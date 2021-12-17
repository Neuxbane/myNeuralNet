#include <math.h>

float E = 2.71828;

float ReLU(float x){
    return x>0?x:0;// if (x > 0) return x; else 0;
}

float LeakyReLU(float x){
    return x>0 ? x : x*  0.1;// if (x > 0) return x; else x*0.1;
}

float BinaryStep(float x){
    return x>0 ? 1 : 0;// if (x > 0) return 1; else 0;
}

float Sigmoid(float x){
    return 1/(1 + pow(E, -x));
}

float DerivativeSigmoid(float x){
    float s = Sigmoid(x);
    return s*(1-s);
}

float ELU(float x){
    return x>=0 ? x : (pow(E, x)-1);
}