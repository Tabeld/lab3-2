#include <cassert>
#include "svg_line.h"

void test_positive() {
    double dash_length=10, gap_length=10;
    in_for_line(dash_length, gap_length);
    assert(dash_length==10);
    assert(gap_length==10);
}

int main(){
    test_positive();
}
