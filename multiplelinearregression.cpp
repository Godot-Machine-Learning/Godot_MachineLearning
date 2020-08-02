#include "multiplelinearregression.h"

MultipleLinearRegression::MultipleLinearRegression()
{

}

void MultipleLinearRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &MultipleLinearRegression::TestFunc);
}


String MultipleLinearRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Multiple Linear Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}
