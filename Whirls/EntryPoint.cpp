#include <Task.h>
#include <Solver.h>
#include <string>
#include <vector>

using namespace std;

void solver_test();

int main()
{
	/*string filesDirectory = "E:\\DEV\\C++\\Whirls\\Whirls\\Files\\";
	string iputFilePath = filesDirectory + "input.txt";
	string outputFilePath = filesDirectory + "output.txt";
	string hFilePath = filesDirectory + "h.txt";

	double maxT = 1000;

	Task task(maxT, iputFilePath, outputFilePath, hFilePath);

	task.RunExplicitMethod();*/

	solver_test();


	return 0;
}

void solver_test()
{
	double omega = 0.5;
	double eps = 0.001;
	int n = 3;

	vector<double> A{ 8, 1, 2,
					  6, 9, 5,
					  1, 5, 9 };

	vector<double> f{ 2,5,6 };

	vector<double> x{ 0,0,0 };

	Solver solver(A, f, n,  x);

	vector<double>result = solver.Relaxation(omega, eps);

	cout << "Result: ";

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}