#ifndef NAIVEBAYESCLASSIFIER_H
#define NAIVEBAYESCLASSIFIER_H

#include "core/reference.h"
#include <string>
#include "IgodotNNInterfaces.h"
#include "naive_bayes.h"
class NaiveBayesClassifier : public IGodotNNInterfaces
{
	GDCLASS(NaiveBayesClassifier,IGodotNNInterfaces);

public:
	NaiveBayesClassifier();

public:
	String TestFunc(); //Will be deleted later
	void	StartTraining(void) override;
	real_t	CalculateOutput(real_t) override{return 0;};
	real_t  CalculateForMultipleInput(PoolRealArray calculateForthis) override;
	void	BinderForFinished(bool);
protected:
	static void _bind_methods();
private:
	gaussian_naive_bayes _gnb;
};

#endif // NAIVEBAYESCLASSIFIER_H
