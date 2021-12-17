#pragma once
#include <vector>
#include <map>
#include <string>

enum class Models {
    Input,
    FullyConnected,
    Kernel = 2,
    Filter = 2
};

enum class ActivationFunction {
    Linear,
    ReLU,
    LeakyReLU,
    BinaryStep,
    Sigmoid = 5,
    Logistic = 5,
    DerivativeSigmoid,
    Tanh,
    ELU
};

class Netsh {
    public:
    Netsh();
    ~Netsh();
    void create(Models model, ActivationFunction activation );
};