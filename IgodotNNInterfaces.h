#ifndef IGODOTNNINTERFACES_H
#define IGODOTNNINTERFACES_H
#include <iostream>
#include <vector>
#include "core/variant.h"
#include "core/reference.h"
#define NNDEBUG
// Common Interface for All Neural Network Classes

class IGodotNNInterfaces : public Reference
{
public:
	IGodotNNInterfaces(){};
	IGodotNNInterfaces(const IGodotNNInterfaces&);
	IGodotNNInterfaces(IGodotNNInterfaces&&);
	virtual ~IGodotNNInterfaces(){}

public: //Interfaces For Godot
	void	SetInputs(const PoolRealArray&);
	void	SetOutputs(const PoolRealArray&);
	virtual void	StartTraining(void)=0;
	virtual real_t	CalculateOutput(real_t)=0;

public: //Interfaces For NoNGodot
	std::vector<double> GetInputVector() const noexcept;
	std::vector<double> GetOutputVector();

private:
	std::vector<double> _inputVector={};
	std::vector<double> _outputVector={};
};

#endif // IGODOTNNINTERFACES_H
