// SWAMI KARUPPASWAMI THUNNAI

#pragma once

#include "mlr.h"
#include <set>
#include <map>
#include <future>
#include <mutex>
#include <algorithm>
#include "dataioclass.h"
#include "itrainpredict.h"

/*
Similar class of scikit-learn's GaussianNB
Written By: Visweswaran N on 2019-09-02
Edited By:  https://github.com/JUNZ1 Aug/2020
*/

class logistic_regression : public DataIOClass, public ITrainPredict
{
private:
	std::vector<std::vector<double>> X;
	std::vector<unsigned long int> y;
	unsigned short int verbose;

	// Unique labels
	std::set<unsigned long int> unique_lables;

	// Bias variables
	std::map<unsigned long int, std::vector<double>>  bias_map;
private:
	void get_unique_labels();
public:
	logistic_regression();
	logistic_regression(const logistic_regression& copyFromThis);
	logistic_regression(logistic_regression&& moveFromThis);
	virtual ~logistic_regression(){};
	logistic_regression& operator= (const logistic_regression& copyFromThis);
	logistic_regression& operator= (logistic_regression&& moveFromThis);
	logistic_regression(std::vector<std::vector<double>> X, std::vector<unsigned long int> y, unsigned short int verbose): X(X), y(y), verbose(verbose) {}
	logistic_regression(std::string model_name);
	void fit();
	std::map<unsigned long int, double> predict(std::vector<double> test);
	void save_model(std::string model_name);

public: //Overrited Interfaces
	void Train() override;
	std::vector<double> Predict(std::vector<double>) override;
private:
	std::mutex _trainingMutex;
	std::future<void> _trainFuture;
};

