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
	Netsh a;
	a.create(Models::Input, Activation::Linear, std::vector<int>{0}, std::vector<int>{2});
	a.create(Models::FullyConnected, Activation::Tanh, std::vector<int>{0}, std::vector<int>{10});
	a.create(Models::FullyConnected, Activation::Tanh, std::vector<int>{0}, std::vector<int>{1});
	//a.create(Models::FullyConnected, Activation::Tanh, std::vector<int>{1}, std::vector<int>{1});
	//a.create(Models::Kernel, Activation::LeakyReLU, std::vector<int>{0}, std::vector<int>{2}, 5);
	//a.create(Models::FullyConnected, Activation::Sigmoid, std::vector<int>{0}, std::vector<int>{1});
	//a.stackUp(std::vector<int>{0,1});

	for(size_t x = 0; x < a.size.size(); x++){
		for(size_t y = 0; y < a.size[x].size(); y++){
			for(size_t z = 0; z < a.size[x][y].size(); z++){
				std::cout  << x << ' ' << y << ' ' << z << ' ' << a.size[x][y][z] <<'\n';
			}

		}
	}
	std::cout<<"\n\n";
	int be = 12;
	int *br = &be;
	std::cout<<*br;
	*br = 9;
	std::cout<<"\n";
	std::cout<<be;
	std::cout<<"\n";
}