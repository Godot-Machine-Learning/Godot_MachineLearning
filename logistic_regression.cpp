// SWAMI KARUPPASWAMI THUNNAI

#include <iomanip>
#include "logistic_regression.h"
#include "json.h"

using json = nlohmann::json;

void logistic_regression::get_unique_labels()
{
	if (verbose) std::cout << "Getting classes...\n";
	for (double i : y)
	{
		unique_lables.insert(i);
	}
	if (verbose) std::cout << "Class count: " << unique_lables.size() << "\n";
}

logistic_regression::logistic_regression()
{
	this->verbose = DEBUG;
}

logistic_regression::logistic_regression(const logistic_regression& copyFromThis)
{
	this->X = copyFromThis.X;
	this->y = copyFromThis.y;
	this->verbose = copyFromThis.verbose;
}


logistic_regression::logistic_regression(logistic_regression&& moveFromThis)
{
	this->X = moveFromThis.X;
	this->y = moveFromThis.y;
	this->verbose = moveFromThis.verbose;
	moveFromThis.X.clear();
	moveFromThis.y.clear();
}

logistic_regression& logistic_regression::operator=(const logistic_regression &copyFromThis)
{
	this->X = copyFromThis.X;
	this->y = copyFromThis.y;
	this->verbose = copyFromThis.verbose;
	return *this;
}

logistic_regression& logistic_regression::operator=(logistic_regression&& moveFromThis)
{
	this->X = moveFromThis.X;
	this->y = moveFromThis.y;
	this->verbose = moveFromThis.verbose;
	moveFromThis.X.clear();
	moveFromThis.y.clear();
	return  *this;
}

logistic_regression::logistic_regression(std::string model_name)
{
	std::ifstream file;
	file.open(model_name);
	if (!file.is_open()) throw "Model cannot be loaded because it cannot be opened!";
	json j;
	file >> j;
	file.close();
	std::set<unsigned long int> labels = j["labels"];
	unique_lables = labels;
	for (unsigned long int label : unique_lables)
	{
		std::vector<double> bias = j[std::to_string(label)];
		bias_map[label] = bias;
	}
}

void logistic_regression::fit()
{
	get_unique_labels();
	// Implementing one vs rest
	for (unsigned long int label : unique_lables)
	{
		std::vector<double> new_y;
		for (unsigned long int i : y)
		{
			if (i == label) new_y.push_back(1);
			else new_y.push_back(0);
		}
		if (verbose)
		{
			std::cout << "Training for: " << label << "\n";
		}
		LinearRegression mlr(X, new_y, verbose);
		mlr.fit();
		std::vector<double> bias = mlr.get_bias();
		bias_map[label] = bias;
	}
	if (verbose)
	{
		std::cout << "Model has been trained!\n";
	}
	if(TrainingFinish)
	{
		TrainingFinish(true);
		std::cout<<"connected.."<<std::endl;
	}
}

std::map<unsigned long int, double> logistic_regression::predict(std::vector<double> test)
{
	std::map<unsigned long int, double> result;
	for (unsigned long int label : unique_lables)
	{
		double prediction = 0.0;
		prediction += bias_map[label][0];
		for (unsigned long int i = 0; i < test.size(); i++)
		{
			double value = bias_map[label][i + 1] * test[i];
			prediction += value;
		}
		prediction = -1 * prediction;
		prediction = 1 / (1 + exp(prediction));
		result[label] = prediction;
	}
	return result;
}

void logistic_regression::save_model(std::string model_name)
{
	json j;
	std::map<unsigned long int, std::vector<double>>::iterator itr1 = bias_map.begin();
	std::map<unsigned long int, std::vector<double>>::iterator itr2 = bias_map.end();
	j["labels"] = unique_lables;
	for (std::map<unsigned long int, std::vector<double>>::iterator itr = itr1; itr != itr2; ++itr)
	{
		unsigned long int label = itr->first;
		j[std::to_string(label)] = itr->second;
	}
	std::ofstream file;
	file.open(model_name);
	if (file.is_open())
	{
		file << std::setw(4) << j << std::endl;
		file.close();
	}
	else
	{
		throw "File cannot be opened for saving the model. May be the file is opened in some other place or you might not have proper permissions.";
	}
}



void logistic_regression::Train()
{
	std::lock_guard<std::mutex> LG(_trainingMutex);
	X.clear();
	y.clear();
	X = GetMultipleInput();
	for(auto eachOutput : GetOutput())
	{
		y.push_back(static_cast<unsigned long int>(eachOutput));
	}
	_trainFuture = std::async(std::launch::async,&logistic_regression::fit,this);
}

std::vector<double> logistic_regression::Predict(std::vector<double> predictThis)
{
	std::lock_guard<std::mutex> LG(_trainingMutex);
	std::map<unsigned long int, double> probabilities = predict(predictThis);
	std::max_element(probabilities.begin(),probabilities.end());
	unsigned long int belongedclass = std::max_element(probabilities.begin(),probabilities.end())->first;
	return{static_cast<double>(belongedclass)};
}



