#ifndef NAIVEBAYESCLASSIFIER_H
#define NAIVEBAYESCLASSIFIER_H

#include "core/reference.h"
#include <string>

class NaiveBayesClassifier : public Reference
{
	GDCLASS(NaiveBayesClassifier,Reference);

public:
	NaiveBayesClassifier();

public:
	String TestFunc();

protected:
	static void _bind_methods();
};

#endif // NAIVEBAYESCLASSIFIER_H
