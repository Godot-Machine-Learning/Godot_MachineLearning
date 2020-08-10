#ifndef DATAIOCLASS_H
#define DATAIOCLASS_H
#include <vector>

class DataIOClass
{
public:
	DataIOClass();\
	virtual ~DataIOClass();
	DataIOClass(const DataIOClass& copyFromThis);
	DataIOClass(DataIOClass&& moveFromThis);
	DataIOClass& operator = (const DataIOClass& copyFromThis);
	DataIOClass& operator = (DataIOClass&& moveFromThis);

public: // Interfaces
	std::vector<double> GetInput() const noexcept;
	std::vector<std::vector<double>> GetMultipleInput() const noexcept;
	std::vector<double> GetOutput() const noexcept;
	void InsertMultipleInput(std::vector<double> insertThis);
	void SetInputs(std::vector<double> toThis);
	void SetOutputs(std::vector<double> toThis);

private:
	std::vector<double> _InputVector = {};
	std::vector<std::vector<double>> _MultipleInputVector;
	std::vector<double> _OutputVector = {};
};

#endif // DATAIOCLASS_H
