#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x*x*x+1;
}

double trapezoidalMethod(double a, double b, double h) {
    double n = (b - a) / h;
    double integral = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += f(x);
    }
    integral *= h;
    return integral;
}

int main() {
    double a = 1.0;
    double b = 1.5; 
    double h = 0.5;    

    double integral = trapezoidalMethod(a, b, h);

    std::cout << "Approximate integral: " << integral << std::endl;

    return 0;
}
