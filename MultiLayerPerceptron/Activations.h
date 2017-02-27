#include<math.h>

inline double sigmoid(double input){
	if (input > 0){
		return 1 / (1 + exp(-input));
	}
	else{
		double e_i = exp(input);
		return e_i / (e_i + 1);
	}
}

inline double sigmoid_prime(double input){
	double s = sigmoid(input);
	return s * (1 - s);
}