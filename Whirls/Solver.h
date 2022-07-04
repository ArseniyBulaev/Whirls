#pragma once

#include <vector>

using namespace std;

class Solver
{
	public:
		Solver(const vector<double> &A, const vector<double> &f, int n, const vector <double> &x);
		vector <double> Relaxation(double omega, double eps);


	private:
		vector<double> A; // ������� �������
		vector<double> f; // ������ ������ �����
		vector<double> x; // ��������� �����������
		int n;			  // ������ �������

		double _EuclideanNorm(const vector<double> &x);
		vector<double> _Difference(const vector<double> &x1, const vector <double> &x2);


};

