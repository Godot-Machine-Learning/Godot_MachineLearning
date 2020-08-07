#include "IgodotNNInterfaces.h"

IGodotNNInterfaces::IGodotNNInterfaces(const IGodotNNInterfaces& copyFromThis)
{
	this->_inputVector = copyFromThis._inputVector;
	this->_outputVector = copyFromThis._outputVector;
}


IGodotNNInterfaces::IGodotNNInterfaces(IGodotNNInterfaces&& moveFromThis)
{
	this->_inputVector = moveFromThis._inputVector;
	this->_outputVector = moveFromThis._outputVector;
	moveFromThis._inputVector.clear();
	moveFromThis._outputVector.clear();
}

void IGodotNNInterfaces::SetInputs(const PoolRealArray& setToThis)
{
	int incomingSize = setToThis.size();
	_inputVector.clear();
	_inputVector.resize(incomingSize);
	for(int indexer = 0; indexer < incomingSize; ++indexer)
	{
		_inputVector[indexer] = setToThis.get(indexer);
	}
	#ifdef NNDEBUG
	std::cout<<"Inputs Are Set"<<std::endl;
	for(auto& eachmember: _inputVector)
		std::cout<<eachmember<<std::endl;
	#endif
}


void IGodotNNInterfaces::SetOutputs(const PoolRealArray& setToThis)
{
	int incomingSize = setToThis.size();
	_outputVector.clear();
	_outputVector.resize(incomingSize);
	for(int indexer = 0; indexer < incomingSize; ++indexer)
	{
		_outputVector[indexer] = setToThis.get(indexer);
	}
	#ifdef NNDEBUG
	std::cout<<"outputs Are Set"<<std::endl;
	for(auto& eachmember: _inputVector)
		std::cout<<eachmember<<std::endl;
	#endif
}

std::vector<double> IGodotNNInterfaces::GetInputVector() const noexcept
{
	return _inputVector;
}

std::vector<double> IGodotNNInterfaces::GetOutputVector()
{
	return _outputVector;
}
