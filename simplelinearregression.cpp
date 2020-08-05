#include "simplelinearregression.h"

SimpleLinearRegression::SimpleLinearRegression()
{

}


void SimpleLinearRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &SimpleLinearRegression::TestFunc);
	ClassDB::bind_method(D_METHOD("SetInputs","InputArray"), &SimpleLinearRegression::SetInputs);
	ClassDB::bind_method(D_METHOD("SetOutputs","OutputArray"), &SimpleLinearRegression::SetOutputs);
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
}
