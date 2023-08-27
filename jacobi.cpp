#include <iostream>
#include <cmath>
using namespace std;

double absDiff(double a, double b)
{
  return fabs(a - b);
}
int jacobiIteration(double A[][3], double b[], double x[], int maxIterations, double tolerance)
{
  int n = 3;
  double xNew[n];
  for (int i = 0; i < n; i++)
  {
    xNew[i] = 0.0;
  }

  int iteration = 0;
  double error = tolerance + 1.0;

  while (iteration < maxIterations && error > tolerance)
  {
    for (int i = 0; i < n; i++)
    {
      double sum = 0.0;
      for (int j = 0; j < n; j++)
      {
        if (i != j)
        {
          sum += A[i][j] * x[j];
        }
      }
      xNew[i] = (b[i] - sum) / A[i][i];
    }
    error = absDiff(x[0], xNew[0]);
    for (int i = 1; i < n; i++)
    {
      double diff = absDiff(x[i], xNew[i]);
      if (diff > error)
      {
        error = diff;
      }
    }
    for (int i = 0; i < n; i++)
    {
      x[i] = xNew[i];
    }

    iteration++;
    for (int i = 0; i < 3; i++)
      cout << xNew[i] << " ";
    cout << endl;
  }
  return iteration;
}

int main()
{
  double A[3][3];
  double b[3];
  cout << "Enter the coefficients of the system:" << ::endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      ::cout << "A[" << i << "][" << j << "]: ";
      ::cin >> A[i][j];
    }
  }
  cout << "Enter the constants of the system:" << ::endl;
  for (int i = 0; i < 3; i++)
  {
    cout << "b[" << i << "]: ";
    cin >> b[i];
  }

  double x[3] = {0, 0, 0};

  int maxIterations = 100;
  double tolerance = 1e-6;

  int iterations = jacobiIteration(A, b, x, maxIterations, tolerance);
  cout << "Number of iterations reached: " << iterations << ::endl;

  return 0;
}
