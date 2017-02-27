#include"TopLayer.h"
#include<math.h>
#include<cstring>

using namespace std;

void TopLayer::forward(Layer prevLayer){
	// change what the constructor just did...
	
	for (int i = 0; i < prevLayer.numNeuron; i++){
		this->weight[i][0] = 1;
	}
}

void TopLayer::backward(){
	double actualArr[10];
	std::memset(actualArr, 0.0, sizeof(actual));
	actualArr[actual] = 1.0;
	for (int i = 0; i < 10; i++){
		this->gradient[i] = i - actualArr[i];
	}
}

