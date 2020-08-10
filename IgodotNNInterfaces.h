#ifndef IGODOTNNINTERFACES_H
#define IGODOTNNINTERFACES_H
#include <iostream>
#include <vector>
#include <iostream>
#include "core/variant.h"
#include "core/reference.h"
#define NNDEBUG
// Common Interface for All Neural Network Classes
//This class may be seperated as two different class,based on Single Data and Multiple Data consept

std::ostream& operator<<(std::ostream& os, const PoolRealArray& poolArray);

class IGodotNNInterfaces : public Reference
{
public:
	IGodotNNInterfaces(){};
	IGodotNNInterfaces(const IGodotNNInterfaces&);
	IGodotNNInterfaces(IGodotNNInterfaces&&);
	virtual ~IGodotNNInterfaces(){}

public: //Interfaces For Godot
	void	ClearAllData(void);
	void	InsertMultipleInput(const PoolRealArray& toThis);
	void	SetInputs(const PoolRealArray&);
	void	SetOutputs(const PoolRealArray&);


public: //Interfaces For NoNGodot
	std::vector<std::vector<double>> GetMultipleInput() const noexcept;
	std::vector<double> GetInputVector() const noexcept;
	std::vector<double> GetOutputVector();

public:
	virtual void	StartTraining(void)=0;
	virtual real_t	CalculateOutput(real_t)=0;
	virtual real_t	CalculateForMultipleInput(PoolRealArray)=0;

private:
	std::vector<std::vector<double>> _multipleInputVector={};
	std::vector<double> _inputVector={};
	std::vector<double> _outputVector={};

};



#endif // IGODOTNNINTERFACES_H
