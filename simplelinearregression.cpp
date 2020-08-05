#include "simplelinearregression.h"

SimpleLinearRegression::SimpleLinearRegression()
{
	_simpleLR.TrainingFinishFunc = std::bind(&SimpleLinearRegression::TrainingFinishBindHere,this,std::placeholders::_1);
	ADD_SIGNAL(MethodInfo("TrainingFinished", PropertyInfo(Variant::BOOL, "TEST TEXT")));
}

SimpleLinearRegression::SimpleLinearRegression(const SimpleLinearRegression& copyFromthis)
{
	this->_simpleLR = copyFromthis._simpleLR;
}

SimpleLinearRegression::SimpleLinearRegression(SimpleLinearRegression&& moveFromthis)
{
	this->_simpleLR = moveFromthis._simpleLR;
}


void SimpleLinearRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &SimpleLinearRegression::TestFunc);
	ClassDB::bind_method(D_METHOD("SetInputs","InputArray"), &SimpleLinearRegression::SetInputs);
	ClassDB::bind_method(D_METHOD("SetOutputs","OutputArray"), &SimpleLinearRegression::SetOutputs);
	ClassDB::bind_method(D_METHOD("StartTraining"), &SimpleLinearRegression::StartTraining);
	ClassDB::bind_method(D_METHOD("CalculateOutput","Input Value"), &SimpleLinearRegression::CalculateOutput);
}


String SimpleLinearRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Simple Linear Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}

void SimpleLinearRegression::SetInputs(const PoolRealArray& SetToThis)
{

	int incomingSize = SetToThis.size();
	std::vector<double> inputVector(incomingSize,0);

	for(int indexer = 0; indexer < incomingSize; ++indexer)
	{
		inputVector[indexer] = SetToThis.get(indexer);
	}
	_simpleLR.SetInputs(inputVector);
	#ifdef NNDEBUG
	std::cout<<"Inputs Are Set"<<std::endl;
	#endif
}

void SimpleLinearRegression::SetOutputs(const PoolRealArray& SetToThis)
{
	int incomingSize = SetToThis.size();
	std::vector<double> inputVector(incomingSize,0);
	for(int indexer = 0; indexer < incomingSize; ++indexer)
	{
		inputVector[indexer] = SetToThis.get(indexer);
	}
	_simpleLR.SetOutputs(inputVector);
	#ifdef NNDEBUG
	std::cout<<"Outputs Are Set"<<std::endl;
	#endif
}

void SimpleLinearRegression::TrainingFinishBindHere(bool input)
{
	std::cout<<"Training Finished"<<std::endl;
	emit_signal("TrainingFinished", true);
}

void SimpleLinearRegression::StartTraining(void)
{
	std::cout<<"Training Start Command Received"<<std::endl;
	std::function<void(void)> myFo = std::bind(&simple_linear_regression::fit,&_simpleLR);
	TrainingFuture= std::async(std::launch::async,myFo);
}

real_t SimpleLinearRegression::CalculateOutput(real_t input)
{
	return static_cast<real_t>(_simpleLR.predict(input));
}
