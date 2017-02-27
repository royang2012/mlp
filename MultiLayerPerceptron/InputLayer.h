#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include"Layer.h"
#include<iostream>
using namespace std;
class InputLayer : public Layer{
public:
	void set_activation(vector<double> inputVec);
};
#endif