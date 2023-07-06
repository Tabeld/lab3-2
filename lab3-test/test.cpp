#include "histogram.h"
#include <cassert>

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_n3() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_only() {
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_one() {
    double min = 0;
    double max = 0;
    find_minmax({3}, min, max);
    assert(min == 3);
    assert(max == 3);
}
void test_no() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
int main() {
    test_one();
    test_only();
    test_n3();
    test_positive();
}

