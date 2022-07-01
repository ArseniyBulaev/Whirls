#include "FileHandler.h"

FileHandler::FileHandler()
{
}

FileHandler::FileHandler(string inputFilePath, string otputFilePath, string hFilePath)
{
	_inputFilePath = inputFilePath;
	_outputFilePath = otputFilePath;
	_hFilePath = hFilePath;

	_inputFile.open(_inputFilePath);
	_outputFile.open(_outputFilePath, ios::out);
	_hFile.open(_hFilePath, ios::out);
}

FileHandler::~FileHandler()
{
	if (_inputFile.is_open()) _inputFile.close();

	if (_outputFile.is_open()) _outputFile.close();

	if (_hFile.is_open()) _hFile.close();
}

vector<Whirl> FileHandler::LoadInputs()
{
	Whirl whirl;
	vector<Whirl> whirls = vector<Whirl>();
	string header;

	if (_inputFile.is_open())
	{
		getline(_inputFile, header);

		while (_inputFile >> whirl.x >> whirl.y >> whirl.g)
		{
			whirls.push_back(whirl);
		}
	}

	return whirls;
}

void FileHandler::SaveState(vector<Whirl> whirls)
{

	for (int i = 0; i < whirls.size(); i++)
	{
		if (i != 0)
		{
			_outputFile << " ";
		}

		_outputFile << whirls[i].x << " "<< whirls[i].y;
	}

	_outputFile << endl;
}

void FileHandler::SaveH(double dt, double h)
{
	_hFile << "Time: " << dt << " H: " << h << endl;
}

void FileHandler::WriteOutputHader(vector<Whirl> whirls)
{
	for (int i = 0; i < whirls.size(); i++)
	{
		_outputFile << "X_" << i + 1 << " Y_" << i + 1 << " ";
	}

	_outputFile << endl;

}

