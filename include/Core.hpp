#include <tuple>
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
    std::map<int, std::vector<std::vector<int> > > size;
    std::vector<float> neural;
    std::map<int, std::vector<std::map<std::string, float*> > > cached;//pointer of parameters
    std::vector<std::map<int, float*> > calcode;
    std::map<int, Activation> activ;
    Netsh();
    ~Netsh();
    void create(Models model, Activation activation, std::vector<int> channels, std::vector<int> size, /*(padding and stepSize) only for Models::(Kernel/Filter)*/ int stepSize, int padding);
    void stackUp(std::vector<int> channels);
    void flattened(std::vector<int> channels);
    std::map<int, std::map<std::string, float> > calculate(std::map<int, std::vector<float> > input);
};