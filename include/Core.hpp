#include <vector>

enum class Models {
    Input,
    FullyConnected,
    Kernel = 2,
    Filter = 2
};

enum class ActivationFunction {
    none,
    Sigmoid,
    LeakyRelu,
    ReLU,
    Tanh
};

class Netsh {
    public:
    Netsh();
};