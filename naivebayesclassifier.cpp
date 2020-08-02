#include "naivebayesclassifier.h"

NaiveBayesClassifier::NaiveBayesClassifier()
{

}

void NaiveBayesClassifier::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &NaiveBayesClassifier::TestFunc);
}


String NaiveBayesClassifier::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Naive Bayes Classifier Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}
