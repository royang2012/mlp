#include <iostream>
#include <vector>
#include "Net.h"
#include "my_MNIST_utils.hpp"
//#include "mnist_data_read.hpp"
//#include "batch_generator.hpp"
using namespace std;
void main(){
	/*  test the network by using a simple setup:
			input	hidden	 output
			  1		  10	   10
		in this case the weight matrix is 1 * 10, bias is 10 * 1
	*/
	vector<int> layerInfo;
	layerInfo.push_back(1); 
	layerInfo.push_back(10);
	Net* network = new Net(layerInfo, 1, 0.1);
	network->print_all_dim();
	// input to the network is 1.0
	vector<double> input; input.push_back(1.0);
	int output = 0;
	MNIST_instance ins1 = {
		input,
		output,
	};
	vector<MNIST_instance> insVec; insVec.push_back(ins1);
	miniBatch batch1 = {
		insVec,
	};
	// set the weight matrix to 0.5 uniform and bias to 0
	vector<double> wi; wi.push_back(0.2);
	vector<vector<double> > weightValue;
	for (int i = 0; i < 10; i++) weightValue.push_back(wi);
	network->set_weight(weightValue, 1);
	vector<double> bi; 
	for (int i = 0; i < 10; i++) bi.push_back(0.0);
	network->set_bias(bi, 1);
	network->SGD_minibatch(batch1);
	network->update_paras();
	//vector<int> layerInfo;
	//layerInfo.push_back(784);
	//layerInfo.push_back(100);
	//layerInfo.push_back(10);
	//Net* network = new Net(layerInfo, 64, 0.01);
	//network->print_all_dim();
	//// dataset is a struct with all MNIST data, it contains:
	////	trainImgs, 2D vector<double>, 60000 * 784
	////	trainLabels, 1D vector<double>, 60000
	////	testImgs, 2D vector<double>, 10000 * 784
	////	testLabels, 1D vector<double>, 10000
	//auto dataset = mnist_data_read();
	//// test features, erase some input data
	//dataset.trainSet.erase(dataset.trainSet.begin() + 1000, dataset.trainSet.end());
	//auto batchSet = batch_generator(dataset, 64);

	//for (int i = 0; i < batchSet.size(); i++){
	//	network->SGD_minibatch(batchSet[i]);
	//	network->update_paras();
	//	if (i % 100 == 0){
	//		cout << "Performing SGD on batch # " << i << endl;
	//	}
	//}

	int waste;
	cin >> waste;
}