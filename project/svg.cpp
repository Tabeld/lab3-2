#include "svg.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void svg_begin(double width, double height) {
    std::cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    std::cout << "<svg ";
    std::cout << "width='" << width << "' ";
    std::cout << "height='" << height << "' ";
    std::cout << "viewBox='0 0 " << width << " " << height << "' ";
    std::cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    std::cout << "</svg>\n";
}

void svg_text(double left, double baseline, std::string text) {
    std::cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, std::string stroke, std::string fill) {
    std::cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='"
            << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

void svg_line(double x1, double y1, double x2, double y2, std::string stroke, double stroke_width, std::string stroke_dasharray) {
    std::cout << "<line x1='" << x1 << "' y1='" << y1 << "' x2='" << x2 << "' y2='" << y2
                << "' stroke='" << stroke << "' stroke-width='" << stroke_width << "' stroke-dasharray='" << stroke_dasharray << "' />";
}

void show_histogram_svg(const std::vector<size_t>& bins, const std::vector<std::string>& bins_title, double dash_length, double gap_length) {
    const auto IMAGE_WIDTH = 900;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    auto IMAGE_HEIGHT = BIN_HEIGHT * bins.size();
    const auto BLOCK_WIDTH = 10;
    double top = 0;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    for (int i=0; i<bins.size(); i++) {
        const double bin_width = bins[i] * BLOCK_WIDTH;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, bins_title[i]);
        std::cout << " \n";
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
        std::cout << " \n";
        top += BIN_HEIGHT;
        svg_line(0, top, IMAGE_WIDTH, top, "black", 1, std::to_string(dash_length) + " " + std::to_string(gap_length));
        std::cout << " \n";
    }

    svg_end();

}
