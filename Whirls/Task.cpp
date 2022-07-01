#define _USE_MATH_DEFINES

#include "Task.h"
#include <iostream>
#include <math.h>



Task::Task(double maxT, string inputPath, string outputPath, string hPath) : _fileHandler(inputPath, outputPath, hPath)
{
	_maxT = maxT;
	_whirls = _fileHandler.LoadInputs();
}

void Task::Run()
{
	double t = 0;

	double dt = 0.1;
	double dx = 0.01;
	double dy = 0.01;

	_fileHandler.WriteOutputHader(_whirls);

	while (t <= _maxT)
	{
		for (int i = 0; i < _whirls.size(); i++)
		{
			_whirls[i].x = _whirls[i].x - (dt / _whirls[i].g) * (dx - (H(i, 0, dy) - H(i, 0, 0)) / dy);
			_whirls[i].y = _whirls[i].y - (dt / _whirls[i].g) * (dy + (H(i, dx, 0) - H(i, 0, 0)) / dx);
		}

		
		_fileHandler.SaveState(_whirls);
		_fileHandler.SaveH(t, H(1, 0, 0));

		t += dt;
	}

	
}

double Task::H(int i, double dx, double dy)
{
	double sumH = 0;
	double xI, yI, gI, xJ, yJ, gJ;

	xI = _whirls[i].x;
	yI = _whirls[i].y;
	gI = _whirls[i].g;


	for (int j = i + 1; j < _whirls.size(); j++)
	{
		xJ = _whirls[j].x;
		yJ = _whirls[j].y;
		gJ = _whirls[j].g;

		sumH += gI * gJ * log(pow(xI + dx - xJ, 2) + pow(yI + dy - yJ, 2));
	}

	return -1.0/ (4*M_PI) * sumH;
}
