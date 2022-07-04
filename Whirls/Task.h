#pragma once

#define _USE_MATH_DEFINES

#include <FileHandler.h>
#include <DataModel.h>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

class Task
{
	public:
		Task(double maxT, string inputPath, string outputPath, string hPath);
		void RunExplicitMethod();
		double H(int diffIndex, double dx, double dy);
		double H();

	private:
		FileHandler _fileHandler;
		vector <Whirl> _whirls;
		double _maxT;



};

