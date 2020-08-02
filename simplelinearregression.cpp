#include "simplelinearregression.h"

SimpleLinearRegression::SimpleLinearRegression()
{

}


void SimpleLinearRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &SimpleLinearRegression::TestFunc);
}


String SimpleLinearRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Simple Linear Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}
