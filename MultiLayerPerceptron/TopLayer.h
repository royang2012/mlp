#ifndef TOPLAYER_H
#define TOPLAYER_H
#include"Layer.h"


class TopLayer : public Layer{
private:
	int actual;
public:
	void forward(Layer prevLayer);
	void backward();
	void set_y();
};

#endif