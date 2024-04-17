#include <create_right_part.h>

void create_right_part(int n, std::vector<double>& right_part) {
    double step = 1 / (double) n * n;
    for (int i = 1; i < n; ++i) {
        right_part[i] = 2 * ((i * i * step + 10) * (i * i * step + 10) - 4 * i * i * step * (i * i * step + 10)) / ((i * i * step + 10) * (i * i * step + 10) * (i * i * step + 10) * (i * i * step + 10));
    }
}