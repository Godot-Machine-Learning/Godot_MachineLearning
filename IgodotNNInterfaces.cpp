#include "IgodotNNInterfaces.h"

std::ostream& operator<<(std::ostream& os, const PoolRealArray& poolArray)
{
	os<<"Array :"<<std::endl;
	for(int counter = 0; counter < poolArray.size() ; ++counter)
	{
		os<<poolArray.get(counter)<<" ";
	}
	os<<" "<<std::endl;
	return os;
}

IGodotNNInterfaces::IGodotNNInterfaces(const IGodotNNInterfaces& copyFromThis)
{
	this->_inputVector = copyFromThis._inputVector;
	this->_outputVector = copyFromThis._outputVector;
	this->_multipleInputVector = copyFromThis._multipleInputVector;
}

IGodotNNInterfaces::IGodotNNInterfaces(IGodotNNInterfaces&& moveFromThis)
{
	this->_inputVector = moveFromThis._inputVector;
	this->_outputVector = moveFromThis._outputVector;
	this->_multipleInputVector = moveFromThis._multipleInputVector;
	moveFromThis._inputVector.clear();
	moveFromThis._outputVector.clear();
	moveFromThis._multipleInputVector.clear();
}

void IGodotNNInterfaces::ClearAllData()
{
	_inputVector.clear();
	_outputVector.clear();
	_multipleInputVector.clear();
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

void IGodotNNInterfaces::InsertMultipleInput(const PoolRealArray &toThis)
{
	int incomingSize = toThis.size();
	std::vector<double> tempinputVector;
	tempinputVector.resize(incomingSize);
	for(int indexer = 0; indexer < incomingSize; ++indexer)
	{
		tempinputVector[indexer] = toThis.get(indexer);
	}
	_multipleInputVector.push_back(tempinputVector);
	#ifdef NNDEBUG
	std::cout<<"Multiple Inputs Are Set"<<std::endl;
	for(const auto& eachArray: _multipleInputVector)
	{
		std::cout<<"Array :"<<std::endl;
		for(const auto& eachMember : eachArray)
		{
			std::cout<<eachMember<<" ";
		}
		std::cout<<" "<<std::endl;
	}
	#endif
}

std::vector<std::vector<double>> IGodotNNInterfaces::GetMultipleInput() const noexcept
{
	return _multipleInputVector;
}
