#include "Utilities.h"
#include "Core.hpp"

Netsh::Netsh(){

}

Netsh::~Netsh(){

}

void Netsh::create(Models model, Activation activation, std::vector<int> channels, std::vector<int> size, /*(padding and stepSize) only for Models::(Kernel/Filter)*/ int stepSize = 1, int padding = 0){
	for(int channel : channels){
		switch (model){
			case Models::Input: {
				std::vector<std::vector<int> > a;
				a.push_back(size);
				this->size.push_back(a);
				break;
			}
			case Models::Kernel: {
				std::vector<int> a;
				for(size_t y = 0; y < size.size(); y++){
					a.push_back((this->size[channel][this->size[channel].size()-1][y]-size[y]+2*padding)/stepSize + 1);
				}
				this->size[channel].push_back(a);
				break;
			}
			default:
				this->size[channel].push_back(size);
				break;
		}
		if(Models::Input == model){
		}
	}
}