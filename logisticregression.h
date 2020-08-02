#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

#include "core/reference.h"
#include <string>


class LogisticRegression : public Reference
{
	GDCLASS(LogisticRegression,Reference);

public:
	LogisticRegression();

public:
	String TestFunc();

protected:
	static void _bind_methods();
};

#endif // LOGISTICREGRESSION_H
