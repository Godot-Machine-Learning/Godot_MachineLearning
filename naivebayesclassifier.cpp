#include "naivebayesclassifier.h"

NaiveBayesClassifier::NaiveBayesClassifier()
{
	_gnb.TrainingFinish = std::bind(&NaiveBayesClassifier::BinderForFinished,this,std::placeholders::_1);
	ADD_SIGNAL(MethodInfo("TrainingFinished", PropertyInfo(Variant::BOOL, "TEST TEXT")));
}

void NaiveBayesClassifier::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &NaiveBayesClassifier::TestFunc);
	ClassDB::bind_method(D_METHOD("InsertMultipleInput","InputArray"), &NaiveBayesClassifier::InsertMultipleInput);
	ClassDB::bind_method(D_METHOD("SetOutputs","OutputArray"), &NaiveBayesClassifier::SetOutputs);
	ClassDB::bind_method(D_METHOD("StartTraining"), &NaiveBayesClassifier::StartTraining);
	ClassDB::bind_method(D_METHOD("CalculateForMultipleInput","InputValue"), &NaiveBayesClassifier::CalculateForMultipleInput);
}


String NaiveBayesClassifier::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Naive Bayes Classifier Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}
void NaiveBayesClassifier::StartTraining()
{
	for(const auto& eachVector : GetMultipleInput())
	{
		_gnb.InsertMultipleInput(eachVector);
	}
	_gnb.SetOutputs(GetOutputVector());
	_gnb.Train();
}

real_t NaiveBayesClassifier::CalculateForMultipleInput(PoolRealArray calculateForthis)
{
	std::vector<double> inputVector = {};
	inputVector.resize(calculateForthis.size());
	for(int counter = 0; counter < calculateForthis.size(); ++ counter)
	{
		inputVector[counter] = calculateForthis.get(counter);
	}
	return(_gnb.Predict(inputVector)[0]);
}

void NaiveBayesClassifier::BinderForFinished(bool input)
{
	std::cout<<"Training Finished"<<std::endl;
	emit_signal("TrainingFinished", true);
}

