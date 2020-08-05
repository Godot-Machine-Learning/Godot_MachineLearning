#ifndef SIMPLELINEARREGRESSION_H
#define SIMPLELINEARREGRESSION_H
#include <string>
#include "core/reference.h"
#include "lsr.h"

class SimpleLinearRegression : public Reference
{
	GDCLASS(SimpleLinearRegression,Reference);
public:
	SimpleLinearRegression();

public:
	String TestFunc();
	void	SetInputs(const PoolRealArray&);
	void	SetOutputs(const PoolRealArray&);
protected:
	static void _bind_methods();

private:
	simple_linear_regression _simpleLR;
};

#endif // SIMPLELINEARREGRESSION_H
