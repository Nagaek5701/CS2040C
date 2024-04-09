#include "RGB.h"

#include <gtest/gtest.h>

namespace testing {

TEST(RGBTest, Constructor) {
  RGB rgb(1, 2, 3);
  EXPECT_EQ(1, rgb.red());
  EXPECT_EQ(2, rgb.green());
  EXPECT_EQ(3, rgb.blue());
}

TEST(RGBTest, Constructor_LimitValues) {
  RGB rgb(-1, 42, 256);
  EXPECT_EQ(0, rgb.red());
  EXPECT_EQ(42, rgb.green());
  EXPECT_EQ(255, rgb.blue());
}

TEST(RGBTest, mixingTest) {
	RGB rgb1(5, 42, 55);
	RGB rgb2(5, 22, 55);
	RGB result = rgb1.mix(rgb2);
	EXPECT_EQ(result.red(), 5);
	EXPECT_EQ(result.green(), 32);
	EXPECT_EQ(result.blue(), 55);

}

TEST(RGBTest, addOverload) {
	RGB rgb1(5, 42, 55);
	RGB rgb2(5, 42, 55);
	RGB result = rgb1 + rgb2;
	EXPECT_EQ(result.red(), 5);
	EXPECT_EQ(result.green(), 32);
	EXPECT_EQ(result.blue(), 55);
}

TEST(RGBTest, Print) {
  // just test that print doesn't crash
  RGB rgb(200, 0, 200);
  rgb.print();
}

}  // namespace testing