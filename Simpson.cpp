#include <iostream>
#include <cmath>

double f(double x) {
    return sqrt(sin(x));
}

double simpsonsOneThird(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            integral += 2 * f(x);
        } else {
            integral += 4 * f(x);
        }
    }

    integral *= h / 3;

    return integral;
}

int main() {
    double a = 0.0; // Lower limit of integration
    double b = M_PI/2; // Upper limit of integration
    int n = 4;    // Number of subintervals

    double integral = simpsonsOneThird(a, b, n);

    std::cout << "Approximate integral: " << integral << std::endl;

    return 0;
}
