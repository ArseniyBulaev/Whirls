#include <Task.h>
#include <string>

using namespace std;


int main()
{
	string filesDirectory = "E:\\DEV\\C++\\Whirls\\Whirls\\Files\\";
	string iputFilePath = filesDirectory + "input.txt";
	string outputFilePath = filesDirectory + "output.txt";
	string hFilePath = filesDirectory + "h.txt";

	double maxT = 1000;

	Task task(maxT, iputFilePath, outputFilePath, hFilePath);

	task.Run();
	

	return 0;
}