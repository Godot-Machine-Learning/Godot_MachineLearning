#ifndef SIMPLELINEARREGRESSION_H
#define SIMPLELINEARREGRESSION_H
#include <string>
#include <future>
#include <thread>
#include "core/reference.h"
#include "core/variant.h"

#include "lsr.h"

#define NNDEBUG

class SimpleLinearRegression : public Reference
{
	GDCLASS(SimpleLinearRegression,Reference);

public:
	SimpleLinearRegression();
	virtual ~SimpleLinearRegression(){};
	SimpleLinearRegression(const SimpleLinearRegression&);
	SimpleLinearRegression(SimpleLinearRegression&&);

public:
	void	SetInputs(const PoolRealArray&);
	void	SetOutputs(const PoolRealArray&);
	void TrainingFinishBindHere(bool);
	void StartTraining(void);
	real_t CalculateOutput(real_t);

protected:
	static void _bind_methods();

private:
	simple_linear_regression _simpleLR;
	std::future<void> TrainingFuture;

private: // Dummy Functions Will be deleted later
	String TestFunc();
};

#endif // SIMPLELINEARREGRESSION_H
