#include "histogram.h"
#include <vector>
#include <algorithm>

void find_minmax(const std::vector<double>& numbers, double& min, double& max) {
    max = *std::max_element(numbers.begin(), numbers.end());
    min = *std::min_element(numbers.begin(), numbers.end());
}
