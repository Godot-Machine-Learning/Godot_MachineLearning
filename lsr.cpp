// SWAMI KARUPPASWAMI THUNNAI

#include "lsr.h"

void simple_linear_regression::print(std::string message)
{
	if (this->verbose) std::cout << message << "\n";
}

void simple_linear_regression::calculate_N()
{
	if (this->X.size() == this->y.size())
	{
		this->N = this->X.size();
	}
	else
	{
		throw "SIZE MISMATCH";
	}
}

// Calculates the X square and saves it in XX vector
void simple_linear_regression::x_square()
{
	print("Calculating X*X");
	for (double i : this->X)
	{
		this->XX.push_back(i*i);
	}
}

// Calculates X*y and stores it in Xy vector
void simple_linear_regression::x_cross_y()
{
	print("Calculating X*y");
	for (unsigned int index = 0; index < N; index++)
	{
		this->Xy.push_back(this->X[index] * this->y[index]);
	}
}

// Calculate all the summation
void simple_linear_regression::calculate_sigma()
{
	// Calculate summation of X
	print("Calculating sigma for X");
	for (double i : this->X)
	{
		this->sigma_X += i;
	}

	// Calculate the summation of Y
	print("Calculating sigma for Y");
	for (double i : this->y)
	{
		this->sigma_y += i;
	}

	// Calculate the summation of XX
	print("Calculating sigma for X*X");
	for (double i : this->XX)
	{
		this->sigma_XX += i;
	}

	// Calculate the summation of Xy
	print("Calculating sigma for X*y");
	for (double i : this->Xy)
	{
		this->sigma_Xy += i;
	}
}

// Calculate our slope - m
void simple_linear_regression::calculate_slope()
{
	print("Calculating slope");
	this->m = ((this->N * this->sigma_Xy) - (this->sigma_X * this->sigma_y)) / ((this->N * this->sigma_XX) - (this->sigma_X * this->sigma_X));	
}

// Calculate our intercept (or) bias
void simple_linear_regression::calculate_bias()
{
	print("Calculating Intercept (or) Bias");
	this->b = (sigma_y - (this->m * this->sigma_X)) / this->N;
}

// Constructor without parameter
simple_linear_regression::simple_linear_regression()
{
	//Lets keep it in this way
	this->verbose = DEBUG;
}

// Constructor to load existing model
simple_linear_regression::simple_linear_regression(std::string model_name)
{
	std::ifstream file;
	file.open(model_name);
	if (!file.is_open()) throw "Model cannot be opened!";
	std::stringstream stream;
	stream << file.rdbuf();
	std::string values = stream.str();
	unsigned int index = values.find(",");
	std::string _m = "";
	std::string _b = "";
	for (unsigned int i = 0; i < index; i++)
	{
		_m += values[i];
	}
	for (unsigned int i = index+1; i < values.size(); i++)
	{
		_b += values[i];
	}
	this->m = std::stod(_m);
	this->b = std::stod(_b);
}

// constructor for start training new model
simple_linear_regression::simple_linear_regression(std::vector<double> X, std::vector<double> y, unsigned short verbose)
{
	this->X = X;
	this->y = y;
	this->verbose = verbose;
}

//Copy Constructor
simple_linear_regression::simple_linear_regression(const simple_linear_regression& copyFromThis)
{
	this->X = copyFromThis.X;
	this->y = copyFromThis.y;
	this->verbose = copyFromThis.verbose;
}

//Move Constructor
simple_linear_regression::simple_linear_regression(simple_linear_regression&& moveFromThis)
{
	this->X = moveFromThis.X;
	this->y = moveFromThis.y;
	this->verbose = moveFromThis.verbose;
	moveFromThis.X.clear();
	moveFromThis.y.clear();
}

//Copy Assignment
simple_linear_regression& simple_linear_regression::operator=(const simple_linear_regression& copyFromThis)
{
	this->X = copyFromThis.X;
	this->y = copyFromThis.y;
	this->verbose = copyFromThis.verbose;
	return *this;
}

//Move Assignment
simple_linear_regression& simple_linear_regression::operator=(simple_linear_regression&& moveFromThis)
{
	this->X = moveFromThis.X;
	this->y = moveFromThis.y;
	this->verbose = moveFromThis.verbose;
	moveFromThis.X.clear();
	moveFromThis.y.clear();
	return *this;
}

// method to train our model, where all methods merges. 
void simple_linear_regression::fit()
{
	print("Training");
	this->calculate_N();
	this->x_square();
	this->x_cross_y();
	this->calculate_sigma();
	this->calculate_slope();
	this->calculate_bias();
	if(TrainingFinish)
	{
		TrainingFinish(true);
		std::cout<<"connected.."<<std::endl;
	}

	print("Model has been trained :)");
}

// Method used for predicting future values
double simple_linear_regression::predict(double _X)
{
	return (this->m * _X) + this->b;
}

// A method used to save model so that we do not need to retrain it
void simple_linear_regression::save_model(std::string file_name)
{
	std::ofstream file;
	file.open(file_name);
	if (!file.is_open()) throw "Model cannot be saved because file cannot be opened to write.Check for permissions and make sure the file is not open!";
	file << this->m << "," << this->b;
	file.close();
}

void simple_linear_regression::Train()
{
	std::lock_guard<std::mutex> LG(_trainingMutex);
	X = GetInput();
	y = GetOutput();
	TrainFuture = std::async(std::launch::async,&simple_linear_regression::fit,this);
}

std::vector<double> simple_linear_regression::Predict(std::vector<double> predictThis)
{
	std::lock_guard<std::mutex> LG(_trainingMutex);
	return {predict(predictThis[0])};
}
