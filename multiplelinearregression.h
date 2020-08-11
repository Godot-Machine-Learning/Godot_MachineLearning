#ifndef MULTIPLELINEARREGRESSION_H
#define MULTIPLELINEARREGRESSION_H
#include <string>
#include "core/reference.h"
#include "IgodotNNInterfaces.h"
#include "mlr.h"
class MultipleLinearRegression : public IGodotNNInterfaces
{
	GDCLASS(MultipleLinearRegression,IGodotNNInterfaces);

public:
	MultipleLinearRegression();
public:
	String TestFunc(); //Will be deleted later
	void	StartTraining(void) override;
	real_t	CalculateOutput(real_t) override{return 0;};
	real_t  CalculateForMultipleInput(PoolRealArray calculateForthis) override;
	void	BinderForFinished(bool);
protected:
	static void _bind_methods();
private:
	LinearRegression _mlr;
};

#endif // MULTIPLELINEARREGRESSION_H
