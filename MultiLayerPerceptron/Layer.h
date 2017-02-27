#ifndef LAYER_H
#define LAYER_H
#include<vector>
#include<string>
class Layer{
private:

public: 
	int numNeuron;
	int prevNumNeuron;
	vector< vector<double> > weight;
	vector<double> bias;
	vector<double> output;
	vector<double> activation;
	vector<double> gradient;
	vector<vector<double> > deltaWeight;
	vector<double> deltaBias;


	Layer(int numNeuron, int prevNumNeuron);
	void update_weight();
	virtual void forward(Layer prevLayer);
	virtual void backward(Layer nextLayer, Layer prevLayer);
	void print_info();
	void batch_clean();
};
#endif