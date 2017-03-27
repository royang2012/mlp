#ifndef TOPLAYER_H
#define TOPLAYER_H
#include"Layer.h"


class TopLayer : public Layer{

public:
	TopLayer() : Layer(10, 10){
		//// to make the backward() function consistant with all hidden layers
		//// Top layer has to have all one's weight and a different gradient
		//// for each input.
		//for (int i = 0; i < 10; i++){
		//	for (int j = 0; j < 10; j++){
		//		this->weight[i][j] = 0.1;
		//	}
		//}
		this->isTop = true;
	}; 
	// not sure yet! depends on how the backprop is designed and how the number of neuronsa are set.
	void forward(Layer* prevLayer);
	void backward(Layer* prevLayer, int actual);
	void set_y();
};

#endif