#include "simplelinearregression.h"

SimpleLinearRegression::SimpleLinearRegression()
{
	_simpleLR.TrainingFinish = std::bind(&SimpleLinearRegression::BinderForFinished,this,std::placeholders::_1);
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
	ClassDB::bind_method(D_METHOD("CalculateOutput","InputValue"), &SimpleLinearRegression::CalculateOutput);
}


String SimpleLinearRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Simple Linear Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}

void SimpleLinearRegression::BinderForFinished(bool input)
{
	std::cout<<"Training Finished"<<std::endl;
	emit_signal("TrainingFinished", true);
}

void SimpleLinearRegression::StartTraining(void)
{
	std::cout<<"Training Start Command Received"<<std::endl;
	_simpleLR.SetInputs(GetInputVector());
	_simpleLR.SetOutputs(GetOutputVector());
	_simpleLR.Train();
}

real_t SimpleLinearRegression::CalculateOutput(real_t calculateThis)
{
	std::cout<<"Calculate Output CMD received Value: "<<calculateThis<<std::endl;
	std::vector<double> output = _simpleLR.Predict({calculateThis});
	return output[0];
}
