#ifndef SIMPLELINEARREGRESSION_H
#define SIMPLELINEARREGRESSION_H
#include <string>
#include <future>
#include <thread>
#include "lsr.h"
#include "IgodotNNInterfaces.h"
//#define NNDEBUG

class SimpleLinearRegression : public IGodotNNInterfaces
{
	GDCLASS(SimpleLinearRegression,Reference);

public:
	SimpleLinearRegression();
	virtual ~SimpleLinearRegression(){};
	SimpleLinearRegression(const SimpleLinearRegression&);
	SimpleLinearRegression(SimpleLinearRegression&&);

public:
	void	BinderForFinished(bool);
	void	StartTraining(void) override;
	real_t	CalculateOutput(real_t) override;
	real_t  CalculateForMultipleOutput(PoolRealArray){return 0;};
protected:
	static void _bind_methods();

private:
	simple_linear_regression _simpleLR;
	std::future<void> TrainingFuture;

private: // Dummy Functions Will be deleted later
	String TestFunc();
};

#endif // SIMPLELINEARREGRESSION_H
