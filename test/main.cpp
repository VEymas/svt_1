#include <find_solution.h>
#include <create_right_part.h>
#include <iostream>

int main() {
    int n;
    std::cout << "Введите число точек:";
    std::cin >> n;
    std::vector<double> right_part(n);
    create_right_part(n, right_part);
    std::vector<double> x(n);
    find_solution(n, x, right_part);
    double val, l2_norm = 0, c_norm = 0;
    for(int i = 1; i < n; i++) {
        val = abs(x[i] - 1 / (i * i + 10));
        l2_norm += val * val;

        c_norm = std::max(c_norm, val);
    }
    std::cout << "l2_norm: " << sqrt(l2_norm) / n << std::endl;
    std::cout << "c_norm: " << c_norm<< std::endl;
}