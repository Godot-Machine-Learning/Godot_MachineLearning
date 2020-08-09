#include "dataioclass.h"

DataIOClass::DataIOClass()
{

}

DataIOClass::~DataIOClass()
{

}


DataIOClass::DataIOClass(const DataIOClass& copyFromThis)
{
	this->_InputVector = copyFromThis._InputVector;
	this->_MultipleInputVector = copyFromThis._MultipleInputVector;
	this->_OutputVector = copyFromThis._OutputVector;
}

DataIOClass::DataIOClass(DataIOClass&& moveFromThis)
{
	this->_InputVector = moveFromThis._InputVector;
	this->_MultipleInputVector = moveFromThis._MultipleInputVector;
	this->_OutputVector = moveFromThis._OutputVector;
	moveFromThis._InputVector.clear();
	moveFromThis._OutputVector.clear();
}

DataIOClass& DataIOClass::operator=(const DataIOClass &copyFromThis)
{
	this->_InputVector = copyFromThis._InputVector;
	this->_MultipleInputVector = copyFromThis._MultipleInputVector;
	this->_OutputVector = copyFromThis._OutputVector;
	return *this;
}

DataIOClass& DataIOClass::operator=(DataIOClass&& moveFromThis)
{
	this->_InputVector = moveFromThis._InputVector;
	this->_MultipleInputVector = moveFromThis._MultipleInputVector;
	this->_OutputVector = moveFromThis._OutputVector;
	moveFromThis._InputVector.clear();
	moveFromThis._OutputVector.clear();
	return *this;
}

void DataIOClass::SetInputs(std::vector<double> toThis)
{
	this->_InputVector = toThis;
}

void DataIOClass::SetOutputs(std::vector<double> toThis)
{
	this->_OutputVector = toThis;
}

std::vector<double> DataIOClass::GetInput() const noexcept
{
	return _InputVector;
}

std::vector<double> DataIOClass::GetOutput() const noexcept
{
	return _OutputVector;
}

void DataIOClass::InsertMultipleInput(std::vector<double> insertThis)
{
	this->_MultipleInputVector.push_back(insertThis);
}
