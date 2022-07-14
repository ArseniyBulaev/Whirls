#include <Task.h>
#include <Solver.h>
#include <string>
#include <vector>

using namespace std;


int main()
{
	string filesDirectory = "Files\\";
	string iputFilePath = filesDirectory + "input.txt";
	string outputFilePath = filesDirectory + "output.txt";
	string hFilePath = filesDirectory + "h.txt";

	double maxT = 1000;

	Task task(maxT, iputFilePath, outputFilePath, hFilePath);

	task.RunExplicitMethod();


	return 0;
}

