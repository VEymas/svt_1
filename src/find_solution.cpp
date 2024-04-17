#include <find_solution.h>

void find_solution(int n, std::vector<double>& x, std::vector<double>& right_part) {
    double A = -1.0 * n * n;
    double B = 2 * n * n;
    double M_C = 1.0 * n * n;
    std::vector<double> alpha(n);
    std::vector<double> betta(n);
    std::vector<double> y(n);
    y[1] = B;
    alpha[1] = M_C / y[1];
    betta[1] = right_part[1] / y[1];
    for(int i = 2; i < n - 1; i++) {
        y[i] = B + A * alpha[i - 1];
        alpha[i] = M_C / y[i];
        betta[i] = (right_part[i] - A * betta[i - 1]) / y[i];
    }

    y[n - 1] = B + A * alpha[n - 2];
    betta[n - 1] = (right_part[n - 1] - A * betta[n - 2]) / y[n - 1];

    x[n - 1] = betta[n - 1];

    for(int i = n - 2; i > 0; i--) {
        x[i] = alpha[i]* x[i + 1] + betta[i];
    }
}