#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork()
{
	count = 0;
}

void NeuralNetwork::add(int p_value) {
	count += p_value;
}

void NeuralNetwork::reset() {
	count = 0;
}

int NeuralNetwork::get_total() const {
	return count;
}

void NeuralNetwork::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "value"), &NeuralNetwork::add);
	ClassDB::bind_method(D_METHOD("reset"), &NeuralNetwork::reset);
	ClassDB::bind_method(D_METHOD("get_total"), &NeuralNetwork::get_total);
}
