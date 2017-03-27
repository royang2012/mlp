#ifndef MNIST_DATA_READ_HPP
#define MNIST_DATA_READ_HPP
#include "my_MNIST_utils.hpp"
#include "mnist_reader_less.hpp"
#include <iostream>
#include <vector>


/*
read mnist data set using 'mnist_data_reader' libraray
cast the type of image pixel to double
*/
using namespace std;
MNIST_instance_set mnist_data_read(){

	MNIST_instance_set instance_set;
	cout << "Loading MNIST data from file..." << endl;
	mnist::MNIST_dataset dataset_m = mnist::read_dataset();
	// deal with training data
	for (int i = 0; i < dataset_m.training_labels.size(); i++){
		MNIST_instance instance;
		vector<double> input_i
			(dataset_m.training_images[i].begin(), dataset_m.training_images[i].end());
		instance.input = input_i;
		instance.output = dataset_m.training_labels[i];
		instance_set.trainSet.push_back(instance);
	}
	// deal with test data
	for (int i = 0; i < dataset_m.test_labels.size(); i++){
		MNIST_instance instance;
		vector<double> input_i
			(dataset_m.test_images[i].begin(), dataset_m.test_images[i].end());
		instance.input = input_i;
		instance.output = dataset_m.test_labels[i];
		instance_set.testSet.push_back(instance);
	}
	cout << "Loaded data set with " << instance_set.trainSet.size() << " training instances and "
		<< instance_set.testSet.size() << " test instances." << endl;
	return instance_set;
}
#endif

