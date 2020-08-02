#ifndef MULTIPLELINEARREGRESSION_H
#define MULTIPLELINEARREGRESSION_H
#include "core/reference.h"
#include <string>

class MultipleLinearRegression : public Reference
{
	GDCLASS(MultipleLinearRegression,Reference);

public:
	MultipleLinearRegression();
public:
	String TestFunc();

protected:
	static void _bind_methods();
};

#endif // MULTIPLELINEARREGRESSION_H
