#include<math.h>
#include<cstring>
inline double mse_prime(double topActivation, int actual){
	double actualArr[10];
	std::memset(actualArr, 0.0, sizeof(actual));
	actualArr[actual] = 1.0;

}