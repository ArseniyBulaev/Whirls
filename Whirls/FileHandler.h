#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "DataModel.h"

using namespace std;


class FileHandler
{
	public:
		FileHandler();
		FileHandler(string inputFilePath, string otputFilePath, string hFilePath);
		~FileHandler();
		vector<Whirl> LoadInputs();
		void SaveState(vector<Whirl> whirls);
		void SaveH(double dt, double h);
		void WriteOutputHader(vector<Whirl> whirls);

	private :
		string		_inputFilePath;
		string		_outputFilePath;
		string		_hFilePath;

		ifstream	_inputFile;
		ofstream	_outputFile;
		ofstream	_hFile;
};

