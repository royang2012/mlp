#include"InputLayer.h"
#include<iostream>
using namespace std;

void InputLayer::set_activation(vector<double> inputVec){
	if (inputVec.size() != this->numNeuron){
		cout << "Warning! Input layer size does not match!" << endl;
	}
	this->activation = inputVec;
}
