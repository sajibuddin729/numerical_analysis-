#include <iostream>
#include <cmath>

// Function to define the differential equation dy/dx
double dydx(double x, double y)
{
    return 3 * x * x + 1; 
}

// Function to perform Euler's method
void eulerMethod(double x0, double y0, double h, double xTarget)
{
    double x = x0;
    double y = y0;

    while (x < xTarget)
    {
        double slope = dydx(x, y);
        y += h * slope;
        x += h;

        std::cout << "x = " << x << ", y = " << y << std::endl;
    }

    std::cout << "Approximate solution at x = " << xTarget << " is y = " << y << std::endl;
}

int main()
{
    double x0, y0, h, xTarget;
    
    // Input the initial condition (x0, y0)
    std::cout << "Enter the initial condition:" << std::endl;
    std::cout << "x0: ";
    std::cin >> x0;
    std::cout << "y0: ";
    std::cin >> y0;

    // Input the step size (h)
    std::cout << "Enter the step size (h): ";
    std::cin >> h;

    // Input the target x-value (xTarget)
    std::cout << "Enter the target x-value: ";
    std::cin >> xTarget;

    eulerMethod(x0, y0, h, xTarget);

    return 0;
}



