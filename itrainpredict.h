#ifndef ITRAINPREDICT_H
#define ITRAINPREDICT_H

#include <vector>
#include <functional>

class ITrainPredict
{
public:
	ITrainPredict() = default;
public: //Interface
	virtual void Train() = 0;
	virtual std::vector<double> Predict(std::vector<double>)= 0;
	std::function<void(bool)> TrainingFinish;
};

#endif // ITRAINPREDICT_H
