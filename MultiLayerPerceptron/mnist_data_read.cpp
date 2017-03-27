/*
	read mnist data set using 'mnist_data_reader' libraray 
	cast the type of image pixel to double
*/
#ifndef MNIST_DATA_READ_CPP
#define MNSIT_DATA_READ_CPP
#include <vector>
#include "mnist_data_read.h"
#include "mnist_reader_less.hpp"

using namespace std;
MNIST_dataset_pro mnist_data_read(){
	MNIST_dataset_pro dataset_pro;
	// dataset is a struct with all MNIST data, it contains:
	//	training_images, 2D vector of unsigned char, 60000 * 784
	//	training_labels, 1D vector of unsigned char, 60000
	//	test_images, 2D vector of unsigned char, 10000 * 784
	//	test_labels, 1D vector of unsigned char, 10000
	auto dataset_m = mnist::read_dataset();
	
	dataset_pro.trainLabels = dataset_m.training_labels;
	
	dataset_pro.testLabels = dataset_m.test_labels;
	
	dataset_pro.trainImgs.reserve(dataset_m.training_images.size());
	
	for (auto&& v : dataset_m.training_images){
		dataset_pro.trainImgs.emplace_back(std::begin(v), std::end(v));
	}
	
	dataset_pro.testImgs.reserve(dataset_m.test_images.size());
	for (auto&& v : dataset_m.test_images){
		dataset_pro.testImgs.emplace_back(std::begin(v), std::end(v));
	}
	return dataset_pro;
}
#endif
