#ifndef MY_MNIST_UTILS_HPP
#define MY_MNIST_UTILS_HPP
#include <vector>
#include <cstdint>
using namespace std;
struct MNIST_instance{
	vector<double> input;
	uint8_t output;
};

struct MNIST_instance_set{
	vector<MNIST_instance> trainSet;
	vector<MNIST_instance> testSet;
};

struct miniBatch {
	vector<MNIST_instance> instances;
};
#endif