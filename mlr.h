// SWAMI KARUPPASWAMI THUNNAI

#pragma once
#define DEBUG 1
#define NODEBUG 0


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <future>
#include <mutex>
#include "dataioclass.h"
#include "itrainpredict.h"

/*
Similar class of scikit-learn's GaussianNB
Written By: Visweswaran N on 2019-09-02
Edited By:  https://github.com/JUNZ1 Aug/2020
*/

class LinearRegression : public DataIOClass, public ITrainPredict
{
private:
	// Independent variable X
	std::vector<std::vector<double>> X={};
	std::vector<double> y;
	std::vector<double> bias;
	unsigned short int verbose=0;

private:
	void print(std::string message);
	
public:
	LinearRegression();
	LinearRegression(const LinearRegression& copyFromThis);
	LinearRegression(LinearRegression&& moveFromThis);
	LinearRegression(std::string model_name);
	virtual ~LinearRegression(){};
	LinearRegression& operator = (const LinearRegression& copyFromThis);
	LinearRegression& operator = (LinearRegression&& moveFromThis);
	LinearRegression(std::vector<std::vector<double>> X, std::vector<double> y, unsigned short int verbose) : X(X), y(y), verbose(verbose) {};
public:
	void fit();
	double predict(std::vector<double> test);
	void save_model(std::string model_name);
	std::vector<double> get_bias();

public: //Overrited Interfaces
	void Train() override;
	std::vector<double> Predict(std::vector<double>) override;
private:
	std::future<void> TrainFuture;
	std::mutex _trainingMutex;

};
