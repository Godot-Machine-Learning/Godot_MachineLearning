#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

#include "core/reference.h"
#include <string>
#include "IgodotNNInterfaces.h"
#include "logistic_regression.h"

class LogisticRegression : public IGodotNNInterfaces
{
	GDCLASS(LogisticRegression,IGodotNNInterfaces);


public:
	LogisticRegression();

public:
	String TestFunc(); //Will be deleted later
	void	StartTraining(void) override;
	real_t	CalculateOutput(real_t) override{return 0;};
	real_t  CalculateForMultipleInput(PoolRealArray calculateForthis) override;
	void	BinderForFinished(bool);

protected:
	static void _bind_methods();
private:
	logistic_regression _lr;
};

#endif // LOGISTICREGRESSION_H
