#include <vector>
#include <map>
#include <string>

enum class Models {
    Input,
    FullyConnected,
    Kernel = 2,
    Filter = 2
};

enum class Activation {
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
    private:
    //size[channel][layer][dimension]
    public:
    std::vector<std::vector<std::vector<int> > > size;
    Netsh();
    ~Netsh();
    void create(Models model, Activation activation, std::vector<int> channels, std::vector<int> size, /*(padding and stepSize) only for Models::(Kernel/Filter)*/ int stepSize, int padding);
    void stackUp(std::vector<int> channels);
};