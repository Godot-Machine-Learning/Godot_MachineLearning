#include "register_types.h"

#include "register_types.h"

#include "core/class_db.h"
#include "neuralnetwork.h"
#include "simplelinearregression.h"
#include "multiplelinearregression.h"
#include "naivebayesclassifier.h"
#include "logisticregression.h"
void register_neural_types() {
	ClassDB::register_class<NeuralNetwork>();
	ClassDB::register_class<SimpleLinearRegression>();
	ClassDB::register_class<MultipleLinearRegression>();
	ClassDB::register_class<NaiveBayesClassifier>();
	ClassDB::register_class<LogisticRegression>();
}

void unregister_neural_types() {
   // Nothing to do here in this example.
}
