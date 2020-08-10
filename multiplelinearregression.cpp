#include "multiplelinearregression.h"

MultipleLinearRegression::MultipleLinearRegression()
{
	_mlr.TrainingFinish = std::bind(&MultipleLinearRegression::BinderForFinished,this,std::placeholders::_1);
	ADD_SIGNAL(MethodInfo("TrainingFinished", PropertyInfo(Variant::BOOL, "TEST TEXT")));
}

void MultipleLinearRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &MultipleLinearRegression::TestFunc);
	ClassDB::bind_method(D_METHOD("InsertMultipleInput","InputArray"), &MultipleLinearRegression::InsertMultipleInput);
	ClassDB::bind_method(D_METHOD("SetOutputs","OutputArray"), &MultipleLinearRegression::SetOutputs);
	ClassDB::bind_method(D_METHOD("StartTraining"), &MultipleLinearRegression::StartTraining);
	ClassDB::bind_method(D_METHOD("CalculateForMultipleInput","InputValue"), &MultipleLinearRegression::CalculateForMultipleInput);
}

String MultipleLinearRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Multiple Linear Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}

void MultipleLinearRegression::StartTraining()
{
	for(const auto& eachVector : GetMultipleInput())
	{
		_mlr.InsertMultipleInput(eachVector);
	}
	_mlr.SetOutputs(GetOutputVector());
	_mlr.Train();
}

real_t MultipleLinearRegression::CalculateForMultipleInput(PoolRealArray calculateForthis)
{
	std::vector<double> inputVector = {};
	inputVector.resize(calculateForthis.size());
	for(int counter = 0; counter < calculateForthis.size(); ++ counter)
	{
		inputVector[counter] = calculateForthis.get(counter);
	}
	return(_mlr.Predict(inputVector)[0]);
}

void MultipleLinearRegression::BinderForFinished(bool input)
{
	std::cout<<"Training Finished"<<std::endl;
	emit_signal("TrainingFinished", true);
}
