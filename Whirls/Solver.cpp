#include "Solver.h"

Solver::Solver(const vector<double> &A, const vector<double> &f, int n, const vector<double> &x)
{
    this->A = A;
    this->f = f;
    this->x = x;
    this->n = n;           
}

vector<double> Solver::Relaxation(double omega, double eps)
{
    vector<double> xPrev;
    vector<double> xNext = x;       // Инициализация начального приближения для алгоритма
    double local_sum = 0;           // Переменная для хранения промежуточной суммы на каждом шаге алгоритма
    vector<double> difference;      // Переменная для хранения разности значений предыдущего и текущего шагов

    while (true)
    {
        xPrev = xNext;

        for (int j = 0; j < n; j++)
        {
            local_sum = 0;

            for (int k = 0; k < n; k++)
            {
                local_sum += (A[j * n + k] / A[j * n + j]) * xNext[k];
            }

            xNext[j] = xNext[j] - omega * local_sum + omega * (f[j] / A[j * n + j]);
        }

        difference = _Difference(xNext, xPrev);

        // Если достигнута требуемая точность - выход из цикла
        if (_EuclideanNorm(difference) < eps )
        {
            break;
        }
    }

    return xNext;
}


vector<double> Solver::_Difference(const vector<double>& x1, const vector<double>& x2)
{
    vector<double> difference = vector<double>(x1.size());

    for (int i = 0; i < x.size(); i++)
    {
        x[i] = x1[i] - x2[i];
    }

    return x;
}

double Solver::_EuclideanNorm(const vector<double> &x)
{
    double sum_of_squares = 0;

    for (int  i = 0; i < x.size(); i++)
    {
        sum_of_squares += x[i] * x[i];
    }

    return sqrt(sum_of_squares);
}


