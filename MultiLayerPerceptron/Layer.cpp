#include"Layer.h"
#include"Activations.h"
#include<iostream>
#include<random>
using namespace std;


Layer::Layer(int numNeuron, int prevNumNeuron){
	this->numNeuron = numNeuron;
	this->prevNumNeuron = prevNumNeuron;
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

void Layer::forward(Layer prevLayer){
	// matrix multiplication
	for (int i = 0; i < this->numNeuron; i++){
		double newOutput = 0;
		for (int j = 0; j < prevLayer.numNeuron; j++){
			newOutput += this->weight[i][j] * prevLayer.activation[j];
		}
		// update corresponding field
		this->output[i] = newOutput;
		this->activation[i] = sigmoid(newOutput);
	}
}

void Layer::backward(Layer nextLayer, Layer prevLayer){
	for (int i = 0; i < this->numNeuron; i++){
		// w(next)' dot(*) gradient(next) * sig_prime
		double newGradient = 0;
		for (int j = 0; j < nextLayer.numNeuron; j++){
			newGradient += nextLayer.weight[j][i] * nextLayer.gradient[j];
		}
		newGradient *= sigmoid_prime(output[i]);
		// add increment to detlaBias
		this->deltaBias[i] += newGradient;
		for (int j = 0; j < prevLayer.numNeuron; j++){
			this->deltaWeight[i][j] = newGradient * prevLayer.activation[j];
		}
	}
}

void Layer::update_weight(){
	for (int i = 0; i < this->numNeuron; i++){
		for (int j = 0; j < prevNumNeuron; j++){
			this->weight[i][j] += this->deltaWeight[i][j];
		}
		this->bias[i] += this->deltaBias[i];
	}
}

void Layer::batch_clean(){
	for (int i = 0; i < this->numNeuron; i++){
		for (int j = 0; j < prevNumNeuron; j++){
			this->weight[i][j] = 0;
		}
		this->bias[i] += this->deltaBias[i];
	}
}




