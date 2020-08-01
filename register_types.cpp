#include "register_types.h"

#include "register_types.h"

#include "core/class_db.h"
#include "neuralnetwork.h"

void register_neural_types() {
	ClassDB::register_class<NeuralNetwork>();
}

void unregister_neural_types() {
   // Nothing to do here in this example.
}
