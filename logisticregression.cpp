#include "logisticregression.h"

LogisticRegression::LogisticRegression()
{

}


void LogisticRegression::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestFunc"), &LogisticRegression::TestFunc);
}


String LogisticRegression::TestFunc()
{
	//Just a simple "is this Working ?" lines..
	std::string testReturn{"Logistic Regression Test Ok"};
	String tryThis(testReturn.c_str());
	return tryThis;
}
