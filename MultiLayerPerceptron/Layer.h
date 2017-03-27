#ifndef LAYER_H
#define LAYER_H
#include<vector>
#include<string>
using namespace std;
class Layer{

public: 
	int numNeuron;
	int prevNumNeuron;
	bool isTop;
	vector< vector<double> > weight;
	vector<double> bias;
	vector<double> output;
	vector<double> activation;
	vector<double> gradient;
	vector<vector<double> > deltaWeight;
	vector<double> deltaBias;


	Layer(int numNeuron, int prevNumNeuron);
	void update_weight(double eta, double batchSize);
	virtual void forward(Layer* prevLayer);
	virtual void backward(Layer* nextLayer, Layer* prevLayer);
	void print_info();
	void batch_clean();
};
#endif