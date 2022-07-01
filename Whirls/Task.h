#pragma once

#include <FileHandler.h>
#include <DataModel.h>
#include <string>
#include <vector>

class Task
{
	public:
		Task(double maxT, string inputPath, string outputPath, string hPath);
		void Run();
		double H(int i, double dx, double dy);

	private:
		FileHandler _fileHandler;
		vector <Whirl> _whirls;
		double _maxT;



};

