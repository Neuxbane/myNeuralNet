#include <iostream>

#include "include/NeuxbaneNet.hpp"

/*
TODO: (X = Incomplete, V = Complete, O = Onprogress)
Activation Function:
    [V]ReLU
    [V]LeakyReLU
    [V]BinaryStep
    [V]Sigmoid/Logistic
    [V]DerivativeSigmoid
    [V]Tanh
    [V]ELU
    [V]Linear

Neural Network:
    [O]Initialize Network
*/

int main(){
    std::cout<<ELU(10)<<'\n';
    std::cout<<ELU(-1)<<'\n';
}