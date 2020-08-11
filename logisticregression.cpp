#include "logisticregression.h"

LogisticRegression::LogisticRegression()
{
	_lr.TrainingFinish = std::bind(&LogisticRegression::BinderForFinished,this,std::placeholders::_1);
	ADD_SIGNAL(MethodInfo("TrainingFinished", PropertyInfo(Variant::BOOL, "TEST TEXT")));
}


void LogisticRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &LogisticRegression::TestFunc);
	ClassDB::bind_method(D_METHOD("InsertMultipleInput","InputArray"), &LogisticRegression::InsertMultipleInput);
	ClassDB::bind_method(D_METHOD("SetOutputs","OutputArray"), &LogisticRegression::SetOutputs);
	ClassDB::bind_method(D_METHOD("StartTraining"), &LogisticRegression::StartTraining);
	ClassDB::bind_method(D_METHOD("CalculateForMultipleInput","InputValue"), &LogisticRegression::CalculateForMultipleInput);
}


String LogisticRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Logistic Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}

void LogisticRegression::StartTraining()
{
	for(const auto& eachVector : GetMultipleInput())
	{
		_lr.InsertMultipleInput(eachVector);
	}
	_lr.SetOutputs(GetOutputVector());
	_lr.Train();
}

real_t LogisticRegression::CalculateForMultipleInput(PoolRealArray calculateForthis)
{
	std::vector<double> inputVector = {};
	inputVector.resize(calculateForthis.size());
	for(int counter = 0; counter < calculateForthis.size(); ++ counter)
	{
		inputVector[counter] = calculateForthis.get(counter);
	}
	return(_lr.Predict(inputVector)[0]);
}

void LogisticRegression::BinderForFinished(bool input)
{
	std::cout<<"Training Finished"<<std::endl;
	emit_signal("TrainingFinished", true);
}
