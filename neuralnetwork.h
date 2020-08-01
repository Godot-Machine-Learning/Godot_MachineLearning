#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "core/reference.h"
class NeuralNetwork : public Reference
{
	GDCLASS(NeuralNetwork,Reference);
	int count;

protected:
	static void _bind_methods();

public:
	NeuralNetwork();

public:
	void add(int p_value);
	void reset();
	int get_total() const;
};

#endif // NEURALNETWORK_H
