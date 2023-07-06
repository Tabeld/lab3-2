#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#endif // SVG_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, std::string text);
void svg_rect(double x, double y, double width, double height, std::string stroke, std::string fill);
void svg_line(double x1, double y1, double x2, double y2, std::string stroke, double stroke_width, std::string stroke_dasharray);
void show_histogram_svg(const std::vector<size_t>& bins, const std::vector<std::string>& bins_title, double dash_length, double gap_length);
