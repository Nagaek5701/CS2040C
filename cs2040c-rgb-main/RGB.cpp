#include "RGB.h"

#include <iostream>

#define BOUND(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

RGB::RGB(int red, int green, int blue) :
    red_(BOUND(red, 0, 255)),
    green_(BOUND(green, 0, 255)),
    blue_(BOUND(blue, 0, 255)) { }


RGB::~RGB() { }

RGB RGB::mix(const RGB& other) {
    int avgR = (red() + other.red()) / 2;
    int avgG = (green() + other.green()) / 2;
    int avgB = (blue() + other.blue()) / 2;
    return RGB(avgR, avgG, avgB);
}

RGB overload+(const )

void RGB::print() {
  std::cout << "RGB(" << red_ << ", " << green_ << ", " << blue_ << ")"
    << std::endl;
}
