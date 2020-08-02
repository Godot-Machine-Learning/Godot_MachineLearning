#ifndef SIMPLELINEARREGRESSION_H
#define SIMPLELINEARREGRESSION_H
#include "core/reference.h"
#include <string>
class SimpleLinearRegression : public Reference
{
	GDCLASS(SimpleLinearRegression,Reference);
public:
	SimpleLinearRegression();

public:
	String TestFunc();

protected:
	static void _bind_methods();
};

#endif // SIMPLELINEARREGRESSION_H
