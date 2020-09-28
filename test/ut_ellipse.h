#include "../src/ellipse.h"

TEST(Ellipse, CreateUseInt) {
    Ellipse ellipse(4, 3);
    ASSERT_DOUBLE_EQ(37.699111843077517, ellipse.area());
    ASSERT_DOUBLE_EQ(22.849555921538759, ellipse.perimeter());
    ASSERT_EQ("Ellipse (4.000, 3.000)", ellipse.info());
}

TEST(Ellipse, CreateUseDouble) {
    Ellipse ellipse(4.5, 3.5);
    ASSERT_DOUBLE_EQ(49.480084294039244, ellipse.area());
    ASSERT_DOUBLE_EQ(25.991148575128552, ellipse.perimeter());
    ASSERT_EQ("Ellipse (4.500, 3.500)", ellipse.info());
}

TEST(Ellipse, ExceptionForSemiMajorAxesIsNotInRange) {
    try {
        Ellipse(0, 1);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsNotInRange) {
    try {
        Ellipse(1, 0);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsBiggerThanSemiMajorAxes) {
    try {
        Ellipse(4, 8);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
