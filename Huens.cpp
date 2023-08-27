#include <iostream>
#include <cmath>

double f(double x, double y) {
    return (2*y)/x;
}

void heunsMethod(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;

    while (x < x_target) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y = y + 0.5 * (k1 + k2);
        x = x + h;
    }

    std::cout << "Approximate solution at x = " << x_target << ": " << y << std::endl;
}

int main() {
    double x0 = 1.0;
    double y0 = 2.0;
    double h = 0.25;
    double x_target = 2.0;

    heunsMethod(x0, y0, h, x_target);

    return 0;
}
