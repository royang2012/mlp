#include"Layer.h"
#include"Activations.h"
#include<iostream>
#include<random>
#include<vector>

using namespace std;


Layer::Layer(int numNeuron, int prevNumNeuron){
	this->numNeuron = numNeuron;
	this->prevNumNeuron = prevNumNeuron;
	this->isTop = false;
	// initialize the weight matrix and bias vector
	for (int i = 0; i < numNeuron; i++){
		vector<double> newRandWeight;
		vector<double> newZeroWeight;
		for (int j = 0; j < prevNumNeuron; j++){
			newRandWeight.push_back((double)rand() / RAND_MAX);
			newZeroWeight.push_back(0);
		}
		this->weight.push_back(newRandWeight);
		this->deltaWeight.push_back(newZeroWeight);
		this->bias.push_back((double)rand() / RAND_MAX);
		this->deltaBias.push_back(0);
		this->output.push_back(0);
		this->activation.push_back(0);
		this->gradient.push_back(0);
	}
}

void Layer::print_info(){
	cout << "Neuron#: " << this->prevNumNeuron << " " 
		<<this->numNeuron << endl;
}

void Layer::forward(Layer* prevLayer){
	// matrix multiplication
	cout << "actvation: ";
	for (int i = 0; i < this->numNeuron; i++){
		double newOutput = 0;
		for (int j = 0; j < prevLayer->numNeuron; j++){
			newOutput += this->weight[i][j] * prevLayer->activation[j];
		}
		// update corresponding field
		this->output[i] = newOutput;
		this->activation[i] = sigmoid(newOutput);
		cout << "--" << activation[i];
	}
	cout << endl;
}

void Layer::backward(Layer* nextLayer, Layer* prevLayer){
	for (int i = 0; i < this->numNeuron; i++){
		// w(next)' dot(*) gradient(next) * sig_prime
		double newGradient = 0;
		if (nextLayer->isTop)
			newGradient = nextLayer->gradient[i];
		else{
			for (int j = 0; j < nextLayer->numNeuron; j++){
				newGradient += nextLayer->weight[j][i] * nextLayer->gradient[j];
			}
		}
		newGradient *= sigmoid_prime(output[i]);
		// add increment to detlaBias
		this->deltaBias[i] += newGradient;
		for (int j = 0; j < prevLayer->numNeuron; j++){
			this->deltaWeight[i][j] = newGradient * prevLayer->activation[j];
		}
	}
}

void Layer::update_weight(double eta, double miniBatchSize){
	for (int i = 0; i < this->numNeuron; i++){
		for (int j = 0; j < prevNumNeuron; j++){
			this->weight[i][j] -= this->deltaWeight[i][j] * eta / miniBatchSize;
		}
		this->bias[i] -= this->deltaBias[i] * eta / miniBatchSize;
	}
}

void Layer::batch_clean(){
// clearn all stored delta weights generated in a mini-batch	
	for (int i = 0; i < this->numNeuron; i++){
		for (int j = 0; j < prevNumNeuron; j++){
			this->weight[i][j] = 0;
		}
		this->bias[i] += this->deltaBias[i];
	}
}




