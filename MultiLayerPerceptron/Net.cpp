#include "Net.h"
#include <iostream>

using namespace std;

Net::Net(vector<int> layerInfo, int miniBatchSize, double eta){
	// Top layer will always have 10 outputs and no weight/bias in it.
	// so it is not counted in the layerInfo vector
	this->numLayer = layerInfo.size() + 1;
	this->layerInfo = layerInfo;
	this->miniBatchSize = miniBatchSize;
	this->eta = eta;
	if (numLayer < 3) {
		// There should at least be an input layer, an output layer and a mid layer
		exit(EXIT_FAILURE);
	}
	// initialize the input layer
	this->inputLayer = new InputLayer(layerInfo[0]);
	percepNet.push_back(inputLayer);
	// all hidden layers
	Layer* layerPtr;
	for (int i = 1; i < numLayer - 1; i++){
		layerPtr = new Layer(layerInfo[i], layerInfo[i - 1]);
		percepNet.push_back(layerPtr);
	}
	// output layer
	this->topLayer = new TopLayer();
	percepNet.push_back(topLayer);

}

void Net::back_propagation(int actual){
	// first compute the 10 class loss using the overloaded backward()
	topLayer->backward(percepNet[numLayer-2], actual);
	for (int i = numLayer - 2; i > 0; i--){
		// start from the last hidden layer, to the first hidden layer
		percepNet[i]->backward(percepNet[i+1], percepNet[i-1]);
	}
}

void Net::feed_forward(){
	for (int i = 1; i < numLayer - 1; i++){
		// all the way from the first hidden layer to the top layer
		percepNet[i]->forward(percepNet[i - 1]);
	}
}

void Net::update_paras(){
	for (int i = 1; i < numLayer - 1; i++){ 
		percepNet[i]->update_weight(eta, miniBatchSize);
	}
}

void Net::SGD_minibatch(miniBatch batch){
	for (int i = 0; i < batch.instances.size(); i++){
		cout << "Batch #" << i ;
		cout << "--Setting input...";
		inputLayer->set_activation(batch.instances[i].input);
		cout << "--forward...";
		feed_forward();
		cout << "--backword...";
		back_propagation(batch.instances[i].output);
	} 
	// update the weight after all instances in minibatch are used
	update_paras();
}

void Net::print_all_dim(){
	cout << "Number of hidden layers: " << numLayer - 2 << endl;
	for (int i = 0; i < numLayer ; i++){
		percepNet[i]->print_info();
	}
}

void Net::set_bias(vector<double> biasValue, int layerCnt){
	percepNet[layerCnt]->bias = biasValue;
}

void Net::set_weight(vector<vector<double> > weightValue, int layerCnt){
	percepNet[layerCnt]->weight = weightValue;
}

///*
//* \Test feature. Set the weight matrix to 0 except for the elements located at
//* \weightPosition, which are set to 1. Due to the linearity of MLP, only one
//* \series of elements needs to be valiated.
//* \each weightPosition vector contains two elements, which correspond to 2d 
//* \cordinates
//*/
//void Net::set_weight(vector<vector<int> >weightPosition){
//	if (weightPosition.size() != numLayer - 2){
//		cout << "Net dimension does not match!" << endl;
//	}
//	for (int i = 0; i < weightPosition.size(); i++){
//		int xRange = percepNet[i]->weight.size();
//		int yRange = percepNet[i]->weight[0].size();
//		for (int j = 0; j < xRange; j++){
//			for (int k = 0; k < yRange; k++){
//				percepNet[i]->weight[j][k] = 0;
//			}
//		}
//		percepNet[i]->weight[weightPosition[i][0]][weightPosition[i][1]] = 1;
//	}
//}


