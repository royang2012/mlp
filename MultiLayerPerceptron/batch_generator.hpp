#ifndef BATCH_GENERATOR_HPP
#define BATCH_GENERATOR_HPP
#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include "my_MNIST_utils.hpp"
using namespace std;



vector<miniBatch> batch_generator(MNIST_instance_set dataset, int batchSize){
	random_shuffle(dataset.trainSet.begin(), dataset.trainSet.end());
	int numBatch = dataset.trainSet.size() / batchSize;
	cout << "Generating mini batches..." << endl;
	vector<miniBatch> batchSet;
	for (int i = 0; i < numBatch; i++){
		vector<MNIST_instance>::const_iterator firstIns = dataset.trainSet.begin()
			+ i * batchSize;
		vector<MNIST_instance>::const_iterator lastIns = dataset.trainSet.begin()
			+ ( i + 1 ) * batchSize;
		vector<MNIST_instance> instances(firstIns, lastIns);
		miniBatch batchIns = {
			instances,
		};
		batchSet.push_back(batchIns);
	}
	cout << "Generated " << numBatch << " mini batches." << endl;
	return batchSet;
}
/*
	non-shuffled version of batch generator. for testing purpose
*/
vector<miniBatch> batch_generator_nr(MNIST_instance_set dataset, int batchSize){
	int numBatch = dataset.trainSet.size() / batchSize;
	cout << "Generating mini batches..." << endl;
	vector<miniBatch> batchSet;
	for (int i = 0; i < numBatch; i++){
		vector<MNIST_instance>::const_iterator firstIns = dataset.trainSet.begin()
			+ i * batchSize;
		vector<MNIST_instance>::const_iterator lastIns = dataset.trainSet.begin()
			+ (i + 1) * batchSize;
		vector<MNIST_instance> instances(firstIns, lastIns);
		miniBatch batchIns = {
			instances,
		};
		batchSet.push_back(batchIns);
	}
	cout << "Generated " << numBatch << " mini batches." << endl;
	return batchSet;
}
#endif

