#include "Utilities.h"
#include "Core.hpp"

Netsh::Netsh(){

}

Netsh::~Netsh(){

}

void Netsh::create(Models model, std::vector<int> channels, std::vector<int> size, Activation activation = Activation::Linear, /*(padding and stepSize) only for Models::(Kernel/Filter)*/ int stepSize = 1, int padding = 0){
	std::map<int, std::map<std::string, float*> > precached;
	for(int channel : channels){
		switch (model){
			case Models::Input: {
				std::vector<std::vector<int> > siz;
				siz.push_back(size);
				this->size[channel] = siz;
				std::vector<int> dim;
				size_t max = 1;
				for(size_t point = 0; point < size.size(); point++){
					dim.push_back(0); max *= size[point];
				}
				for(size_t a=0;a<max;a++){
					std::string id = "";
					for(size_t x : dim){id += '_'+std::to_string(x);}
					this->neural.push_back(drand());
					precached[channel][id] = &this->neural.back();
					dim[0]++;
					if(dim[0] == size[0]){
						for(size_t check = 0; check < dim.size()-1; check++){
							if(dim[check] == size[check]){
								dim[check]=0;
								dim[check+1]++;
							}
						}
					}
				}
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
			case Models::FullyConnected: {
				this->size[channel].push_back(size);
				std::vector<int> dim;
				size_t max = 1;
				for(size_t point = 0; point < size.size(); point++){
					dim.push_back(0); max *= size[point];
				}
				for(size_t a=0;a<max;a++){
					std::string id = "";
					for(size_t x : dim){id += '_'+std::to_string(x);}
					this->neural.push_back(drand());
					precached[channel][id] = &this->neural.back();

					std::vector<int> wsize = this->size[channel][this->size.size()-1];
					std::vector<int> wdim;
					size_t wmax = 1;
					for(size_t point = 0; point < wsize.size(); point++){
						wdim.push_back(0); wmax *= wsize[point];
					}
					for(size_t a=0;a<wmax;a++){
						std::string wid = "";
						for(size_t x : wdim){wid += '_'+std::to_string(x);}
						std::map<int, float*> code;
						code[0] = &this->neural.back();
						code[1] = this->cached[channel][wid];
						this->neural.push_back(drand());
						code[2] = &this->neural.back();
						this->calcode.push_back(code);
						std::cout<<wid<<'\n';
						wdim[0]++;
						if(wdim[0] == wsize[0]){
							for(size_t check = 0; check < wdim.size()-1; check++){
								if(wdim[check] == wsize[check]){
									wdim[check]=0;
									wdim[check+1]++;
								}
							}
						}
					}
					std::map<int, float*> code;
					this->activ[this->calcode.size()] = activation;
					code[0] = precached[channel][id];
					this->calcode.push_back(code);
					std::cout<<"BID:"<<id<<"\n\n";

					dim[0]++;
					if(dim[0] == size[0]){
						for(size_t check = 0; check < dim.size()-1; check++){
							if(dim[check] == size[check]){
								dim[check]=0;
								dim[check+1]++;
							}
						}
					}
				}
				break;
			}
			default:{
				this->size[channel].push_back(size);
				break;
			}
		}
	}
	this->cached = precached;
}

void Netsh::stackUp(std::vector<int> channels){

}

void Netsh::flattened(std::vector<int> channels){

}

std::map<int, std::vector<float> > Netsh::calculate(std::map<int, std::vector<float> > input){
	for(size_t at = 0; at < this->calcode.size(); at++){
		float* target = this->calcode[at][0];
		if (this->calcode.size() == 1){
			switch (this->activ[at]){
				case Activation::ReLU:
					*target = ReLU(*target);
					break;
				
				case Activation::LeakyReLU:
					*target = LeakyReLU(*target);
					break;
			
				case Activation::BinaryStep:
					*target = BinaryStep(*target);
					break;

				case Activation::Sigmoid:
					*target = Sigmoid(*target);
					break;

				case Activation::Logistic:
					*target = Logistic(*target);
					break;
			
				case Activation::DerivativeSigmoid:
					*target = DerivativeSigmoid(*target);
					break;

				case Activation::Tanh:
					*target = Tanh(*target);
					break;

				case Activation::ELU:
					*target = ELU(*target);
					break;
				
				case Activation::Linear:
					break;

				default:
					break;
			}
		} else {
			*target += (*this->calcode[at][1])*(*this->calcode[at][2]);
		}
	}
	std::map<int, std::vector<float> > ret;
	
	return ret;
}

/*
neural with 1 channel, 2->3->1 size
[n1][n2]
[n3[w1*n1] [w2*n2]] [n4[w3*n1] [w4*n2]] [n5[w5*n1] [w6*n2]] for (this-size{3}){ for (before-size{2}) {this= this-w * before} }

[n6[] [] []]
*/