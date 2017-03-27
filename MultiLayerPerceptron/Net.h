#ifndef NET_H
#define NET_H

#include"Layer.h"
#include"InputLayer.h"
#include"TopLayer.h"
#include "my_MNIST_utils.hpp"

#include<vector>
#include<string>
using namespace std;
class Net{
private:
	int numLayer;
	int miniBatchSize;
	double eta;
	vector<int> layerInfo;
	InputLayer* inputLayer;
	vector<Layer*> percepNet;
	TopLayer* topLayer;

public:
	Net(vector<int> layerInfo, int miniBatchSize, double eta);
	//void setup();
	void SGD_minibatch(miniBatch batch);
	void train(int numEpoch);
	void feed_forward();
	void back_propagation(int actual);
	void update_paras();
	void print_all_dim();
	void set_weight(vector<vector<double> > weightValue, int layerCnt);
	void set_bias(vector<double> biasValue, int layerCnt);
	//void set_weight(vector<vector<int> >weightPosition);

};

#endif