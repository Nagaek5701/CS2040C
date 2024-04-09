#include "RGB.h"

#include <iostream>

#define BOUND(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

RGB::RGB(int red, int green, int blue) :
    red_(BOUND(red, 0, 255)),
    green_(BOUND(green, 0, 255)),
    blue_(BOUND(blue, 0, 255)) { }

RGB::~RGB() { }

void RGB::print() {
  std::cout << "RGB(" << red_ << ", " << green_ << ", " << blue_ << ")"
    << std::endl;
}

RGB RGB::mix(const RGB& other) {
  int redMix = red()+other.red();
  int greenMix = green()+other.green();
  int blueMix = blue()+other.blue();
  return RGB(redMix, greenMix, blueMix);
}

RGB RGB::scale(double factor) {
    int redScale = round(red() * factor);
    int greenScale = round(green() * factor);
    int blueScale = round(blue() * factor);
  return RGB(redScale, greenScale, blueScale);
}
