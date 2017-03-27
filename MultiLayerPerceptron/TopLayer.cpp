#include"TopLayer.h"
#include<math.h>
#include<cstring>
#include<iostream>
using namespace std;

void TopLayer::forward(Layer* prevLayer){
	// change what the constructor just did...
	
	for (int i = 0; i < prevLayer->numNeuron; i++){
		this->weight[0][i] = 1;
	}

}

void TopLayer::backward(Layer* prevLayer, int actual){
	double actualArr[10];
	std::memset(actualArr, 0.0, sizeof(actualArr));
	actualArr[actual] = 1.0;
	cout << "Top Layer gradient: ";
	for (int i = 0; i < 10; i++){
		this->gradient[i] = prevLayer->activation[i] - actualArr[i];
		cout << "--" << gradient[i];
	}
	cout << endl;
}

